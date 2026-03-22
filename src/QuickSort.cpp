//#includes
#include "QuickSort.hpp"
#include <vector>
#include <iostream>

//methods
    /*method that will be used to connect the private methods behind
    the recursion with the method that will take care of receiving the
    vector and sorting it so no other places can use them except
    this that will use it as intended*/ 
    void QuickSort::sortingQuick(std::vector<int>& intsVec){
        //sorting the entirety from position 0 to last position
        QuickSort::sortingQuickLR(intsVec, 0, intsVec.size()-1);
    }
