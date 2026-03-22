#include <iostream>
#include "Utils.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "BalancedTree.hpp"

int main(){

    
    // test to try out the function to put in the words in the vector
    // variables
    std::string fileUbication;
    std::vector<std::string> wordsVec;
    std::vector<int> intsVec;
    int wordsVecSize;
    BalancedTree tree;
    std::vector<int> organizedTreeVector;
    //caling the function to read the file
    
    fileUbication = "data/dataset.txt";
    wordsVec = Utils::readWordsFromFile(fileUbication);
    wordsVecSize = wordsVec.size();

    std::cout << "Se leyeron: " << wordsVec.size() << std::endl;

    intsVec = Utils::convertWordsToInts(wordsVecSize);
    Utils::randomizeWordsOrd(intsVec,wordsVecSize);

    std::cout << "Vector antes:" << std::endl;
    for (int i = 0; i < wordsVec.size(); i++)
    {
        std::cout << intsVec.at(i) << std::endl;
    }   

    // QuickSort::sortingQuick(intsVec);

    // HeapSort::heapingSort(intsVec);

    for (int number : intsVec)
    {
        tree.insertNumber(number);
    }
    
    organizedTreeVector = tree.getInorder();

    std::cout << "vector despues:" << std::endl;
    for (int i = 0; i < wordsVec.size(); i++)
    {
        std::cout << organizedTreeVector.at(i) << std::endl;
    }
}

