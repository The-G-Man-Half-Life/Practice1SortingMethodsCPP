//includes
#include "HeapSort.hpp"

//methods
void HeapSort::heapingSort(std::vector<int>& intsVec){
    HeapSort::maxHeapify(intsVec, intsVec.size()-1);
}