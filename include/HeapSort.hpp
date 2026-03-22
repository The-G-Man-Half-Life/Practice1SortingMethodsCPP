//include guards
#pragma once

//include of necesary elements
#include <vector>

class HeapSort
{
private:

    //methods in private as these will be used for the heap sort but should not be used externally

    /*This method takes care of obtaining the ubication of a left child given the vector 
    and the ubication of the father*/
    static const int obtainLeftChildUbication(std::vector<int>& intsVec, int fatherUbication){
        return 2*fatherUbication + 1;
    };

    /*This method takes care of obtaining the ubication of a right child given the vector 
    and the ubication of the father*/
    static const int obtainRightChildUbication(std::vector<int>& intsVec, int fatherUbication){
        return 2*fatherUbication + 2;
    };

    /*This method takes care of obtaining the ubication of a right child given the vector 
    and the ubication of the father*/
    static const int obtainFatherUbication(std::vector<int>& intsVec, int childUbication){
        return (childUbication - 1) / 2 ;
    };

    /*Main method that takes care behind all the logic of switching values in the entire heap sort.
    It starts from the last element of the vector (intsVec) and by obtaining the "father" of that 
    last element of the vector (crrntChildUbication). The father will compare itself with its right
    and left children, in case these are in ubications less or equal to the lastSortedValUbication,
    This procces will obtain the ubication and value of the father, left and right child and by using
    the ubication of the left child it will go 1 position back obtaining the next left child of the 
    next trio(left child, right child, father) to review, which will be the new crrntChildUbication 
    too. After doing this process recursively until the element in the position 0 of the vectorm it 
    will swap the element in the position 0 with the lastSortedValUbication, which is a value that 
    will be kept through all of the iterations in each heapify execution, due that the element in the 
    top, after making all these swappings, will be the biggest number putting it at the end of the vector
    and then reducing the visible size of the vector by 1. Finally this method will cast maxHeapify
    and end the execution of the heapify by using a empty return*/
    static void heapify(std::vector<int>& intsVec,int crrntChildUbication, int lastSortedValUbication){
        //variables getting ubication and values of the triad(father, left and right child)
        int fatherUbication;
        int fatherValue;
        int rightChildUbication;
        int rightChildVal;
        int leftChildUbication;
        int leftChildVal;
        
        /*base case to end the recursivity which is that the crrntChildUbication of the recursion 
        equals the first element of the vector*/
        if (crrntChildUbication == 0){
    
            /*swaps the element in the root, the biggest element not sorted, with the last sortedValUbication
            ensuring it remains in the last position */
            std::swap(intsVec[0], intsVec[lastSortedValUbication]);
            
            /*ending of the heapify it reduces the scope of the vector, the elements already sorted, by 1 and
            calls heapify to keep sorting the vector and return to ensures that 1 heapify run ends*/
            maxHeapify(intsVec,lastSortedValUbication-1);
            return;
        }
        
        /*Gathering all the variable values after the certification of the base case to ensure not making any
         unnecessary procedures*/ 
        fatherUbication = obtainFatherUbication(intsVec, crrntChildUbication);
        fatherValue = intsVec.at(fatherUbication);
        rightChildUbication = obtainRightChildUbication(intsVec, fatherUbication);
        leftChildUbication = obtainLeftChildUbication(intsVec, fatherUbication);

        /*Verifies that the father has a right Child not outside the scope of the not sorted values ensuring
        data remains unchanged but also allows for the possibly needed swaps*/
        if(rightChildUbication <= lastSortedValUbication){
            /*Obtain value of the right child*/
            rightChildVal = intsVec.at(rightChildUbication);
            /*In case that the right child value is bigger than its father's one it will swap
            them and change the father value to the one belonging to the old right child prepared
            for the next comparison*/
            if (rightChildVal > fatherValue ){
                std::swap(intsVec[rightChildUbication], intsVec[fatherUbication]);
                fatherValue = rightChildVal;
            }
        }

        /*Verifies that the father has a left Child not outside the scope of the not sorted values ensuring
        data remains unchanged but also allows for the possibly needed swaps*/
        if(leftChildUbication <= lastSortedValUbication){
            /*Obtain left child value*/
            leftChildVal = intsVec.at(leftChildUbication);
            /*If the left child value is bigger than its father's one it will swap them*/
            if (leftChildVal > fatherValue){   
                std::swap(intsVec[leftChildUbication], intsVec[fatherUbication]);
            }
        }

        /*Applies the recursivity but in the next triad (father, left and right child) by using the left child
        ubication and subtracting it 1 but also keeping the last sortedValUbication for making the swap once 
        the crrntChildUbication is equals to 0*/
        heapify(intsVec,leftChildUbication-1, lastSortedValUbication);
        
    }

    /*This takes care of making the recursion process for when the entire vector (intsVec) is completely sorted
    this by using sortedLastPoint ,which is reduced by 1 from heapify, by receiving the ubication from which the 
    vector is not sorted casting heapify to keep sorting and reducing this value until it equals 0 in which case
    it will return the vector already sorted */
    static std::vector<int>& maxHeapify(std::vector<int>& intsVec,int sortedLastPoint){
        if (sortedLastPoint != 0 ){
            heapify(intsVec, sortedLastPoint, sortedLastPoint);
        }
        return intsVec;
        
    }

public:

    // method public to execute the heap sort
    static void heapingSort(std::vector<int>&);
};

