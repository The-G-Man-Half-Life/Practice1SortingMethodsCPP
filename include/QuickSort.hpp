//include guards
#pragma once

//include of necessary elements
#include <vector>

class QuickSort
{
private:
    //private methods that will take care of the sorting method by using recursion

    /*SortingQuickLR (SortingQuickLeftRight) takes care of receiving the vector and the part where it will sort from
    (start) until a certain point (end). It will do that recursively creating mini imaginary vectors inside the vector
    until the sorting made by partitionate brings us to start == end because it means that the sorting in the vector 
    would have been completed already. We use something called pivot which will be the center(we take it always at 
    the beggining of each vector) of the algorithm as it will compare its value with every element  put in the left
    in case is less or equal to itself, but if is bigger we put it on the right side once this organization is made 
    we leave that pivot and make the imaginary vector in each side where the left will begin from the start of the 
    original vector and 1 position back of the pivot we left alone and the right will begin 1 position after the pivot 
    we left alone and will end at the end of the original vector where each end position of each imaginary vector(Left
    and Right) will turn into its own pivot repeating this process recursively until there is no left side or right side
    meaning all of the items are organized. The organization of each imaginary vector that will be created will always 
    begin from the left and then will be sorted the right side*/
    static std::vector<int> sortingQuickLR(std::vector<int>& intsVec, int start, int end){
        //variables
        /*This pivot will define the right and left side of our vector
        being the elements in the left minor to the pivot's value and the ones
        in the right being higher than the pivot's value*/
        int pivot;

        /*when start equals end (base case) the function ends
        and returns an organized vector*/
        if (start < end){        
            
            //finding the pivot
            pivot = partitionate(intsVec, start, end);

            /*recursivity for left, we always begin in the left
            creating the mini imaginary vectors sorted in that 
            side*/
        
            sortingQuickLR(intsVec, start, pivot-1);
            
            /*recursivity for right, we then make the right side
            and sort it using left sorting first until it runs out
            and then we do that in right until there is nothing more
            to sort*/
            sortingQuickLR(intsVec, pivot + 1, end);
        }

        /*we return the vector once the pivot moves enough to make
        itself coincide with the */
        return intsVec;
    }
    
    /*method that rearranges the vector and the mini imaginary vectors we pass to it
    and returns the pivot position so the new imaginary vectors can be made having as 
    the center that pivot which is already part of the organized vector */ 
    static int partitionate(std::vector<int>& intsVec, int start, int end){
        //variables
        int i;
        int j;
        int pivotValue;

        //defining variables
        i = start - 1;//switch position in case j <= pivotValue. i moves 1 postion then switches with j
        j = start;//comparator with the pivot if it is <= pivotValue it will switch with i as said before
        pivotValue = intsVec.at(end);// obtains pivot value for comparions
        
        //cycle to move around the vector or imaginary vector elements
        for(; j <= end ; j++)
        {
            //switching positions only if the element at j is less or equal compared to the element at the end(pivot)
            if (intsVec.at(j) <= pivotValue){
                /*i will only move if j is minor compared to the pivot value ensuring elements in the left are minor
                than the pivot and the ones in the right are higher*/
                i++;
                std::swap(intsVec[i], intsVec[j]);
            }
        }

        //returns the pivot which is now part of the already organized vecctor
         return i;

    }
public:
    /*method that will take care of receiving the vector
    and passing the required parameters to the private methods
    which will apply the recursion and sorting process*/
    static void sortingQuick(std::vector<int>& intsVec);
};

