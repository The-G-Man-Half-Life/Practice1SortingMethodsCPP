#include <iostream>
#include "Utils.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "BalancedTree.hpp"
#include "Performance.hpp"

void executeQuickSort(std::vector<int> unorganizedVector){
    //variable
    Timer timer;

    //execution
    timer.start();
    QuickSort::sortingQuick(unorganizedVector);
    timer.stop();

    //printing of information
    std::cout << "========================================\n";
    std::cout << "Quick sort Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << " Miliseconds" << std::endl;
    std::cout << "Uso de memoria estimado: " << std::endl;
    MemoryEstimator::printQuickSortMemory(unorganizedVector.size());
}

void executeHeapSort(std::vector<int> unorganizedVector){
    //variable
    Timer timer;

    //execution
    timer.start();
    HeapSort::heapingSort(unorganizedVector);
    timer.stop();

    //printing of information
    std::cout << "========================================\n";
    std::cout << "Heap sort Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << " Miliseconds" << std::endl;
    std::cout << "Uso de memoria estimado: " << std::endl;
    MemoryEstimator::printHeapSortMemory(unorganizedVector.size());
}

void executeBalancedTree(std::vector<int> unorganizedVector){
    //variable
    Timer timer;
    BalancedTree tree;
    std::vector<int> organizedList;

    //execution
    timer.start();
    //insert the Dataset in the tree first
    for (int number: unorganizedVector){
        tree.insertNumber(number);
    }
    //calling the organizator method
    organizedList = tree.getInorder();
    timer.stop();

    //printing of information
    std::cout << "========================================\n";
    std::cout << "AVL tree Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << " Miliseconds" << std::endl;
    std::cout << "Uso de memoria estimado: " << std::endl;
    MemoryEstimator::printBalancedTreeMemory(unorganizedVector.size());
}

int main(){
    // variables
    std::string fileUbication;
    std::vector<std::string> wordsVec;
    std::vector<int> intsVec;
    int wordsVecSize;
    BalancedTree tree;
    std::vector<std::string> organizedVectorByQuickSort;
    std::vector<std::string> organizedVectorByHeapSort;
    std::vector<std::string> organizedTreeVector;
    int option;
    bool flag = true;

    //calling the function to read the file
    fileUbication = "data/dataset.txt";
    wordsVec = Utils::readWordsFromFile(fileUbication);
    wordsVecSize = wordsVec.size();

    /*Converting each word into a number to handle easier
    the data once it needs to be sorted */
    intsVec = Utils::convertWordsToInts(wordsVecSize);
    Utils::randomizeWordsOrd(intsVec,wordsVecSize);

    /*Using a while cycle to simulate the basic characteristics
    of a menu*/
    while (flag == true){
        /*Showing the menu once every cycle is done
        and gathering the option choosen by the user*/
        option = Utils::showMenu();
        /*Using a switch to choose which case the user chose*/
        switch (option){
        case 1:
            //Cast of the sorting method and its required info
            executeQuickSort(intsVec);
            /*Usar of pauseConsole to give a more controled management 
            for the user to watch the menu and shorting methods*/
            Utils::pauseConsole();
            break;
        case 2:
            executeHeapSort(intsVec);
            Utils::pauseConsole();
            break;
        case 3:
            executeBalancedTree(intsVec);
            Utils::pauseConsole();
            break;
        case 4:
            //Option which will be used to stop the menu and end the cycle
            std::cout << "Adios" << std::endl;
            flag = false;
            break;
        default:
            break;
        }
    }
}
