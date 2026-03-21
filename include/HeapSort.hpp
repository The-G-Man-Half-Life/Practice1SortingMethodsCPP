//include guards
#pragma once

//includes
#include <vector>
#include <iostream>

class HeapSort
{
private:
    //atributes

    //methods

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

    /*Main method that takes care behind all the logic behind the heap. It reviews using the father of the 
    who is the biggest and after that turns it into the new father doing this recursively from the most in 
    the bottom left towards the root of the vector and then it switches the element in the root with */
    static void heapify(std::vector<int>& intsVec,int crrntChildUbication, int lastSortedValUbication){
        //variables
        int fatherUbication;
        int fatherValue;
        int rightChildUbication;
        int rightChildVal;
        int leftChildUbication;
        int leftChildVal;
        
        if (crrntChildUbication == 0){
            // std::cout << "termine 1 heap" << std::endl;
            //     for (int i = 0; i < intsVec.size(); i++)
            //     {
            //         std::cout << intsVec.at(i) << std::endl;
            //     }
            std::swap(intsVec[0], intsVec[lastSortedValUbication]);
            maxHeapify(intsVec,lastSortedValUbication-1);
            return;
        }
        
        fatherUbication = obtainFatherUbication(intsVec, crrntChildUbication);
        fatherValue = intsVec.at(fatherUbication);
        rightChildUbication = obtainRightChildUbication(intsVec, fatherUbication);
        leftChildUbication = obtainLeftChildUbication(intsVec, fatherUbication);

        if(rightChildUbication <= lastSortedValUbication){
            rightChildVal = intsVec.at(rightChildUbication);
            if (rightChildVal > fatherValue ){
                std::swap(intsVec[rightChildUbication], intsVec[fatherUbication]);
                fatherValue = rightChildVal;
            }
        }
        if(leftChildUbication <= lastSortedValUbication){
            leftChildVal = intsVec.at(leftChildUbication);
            if (leftChildVal > fatherValue){   
                std::swap(intsVec[leftChildUbication], intsVec[fatherUbication]);
            }
        }

        heapify(intsVec,leftChildUbication-1, lastSortedValUbication);
        
    }

    static std::vector<int>& maxHeapify(std::vector<int>& intsVec,int sortedLastPoint){
        if (sortedLastPoint != 0 ){
            heapify(intsVec, sortedLastPoint, sortedLastPoint);
        }
        return intsVec;
        
    }

public:

    // methods
    static void heapingSort(std::vector<int>&);
};

