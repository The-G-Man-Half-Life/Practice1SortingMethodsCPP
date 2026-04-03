//includes
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <random>

//methods

std::vector<std::string> Utils::readWordsFromFile(std::string& ubication){
    //variables
    std::vector<std::string> wordsVec;
    std::ifstream file(ubication);
    std::string word;

    //verifyFile
    if (!file.is_open()){
        std::cerr << "The file does not exist or it does not have that name" << std::endl;
    }
    else{
        //Cycle to insert words in the vector
        while (file >> word){
            wordsVec.push_back(word);
        }
    }

    //close the file
    file.close();
    
    return wordsVec;
}

std::vector<int> Utils::convertWordsToInts(int wordsVecSize){
    //variables
    std::vector<int> intVec;
    
    //this will creates a vector with numbers from 1 to the size of the vector
    //allowing for better management
    for (int i = 1; i <= wordsVecSize; i++)
    {
        intVec.push_back(i);
    }
    return intVec;
}

void Utils::randomizeWordsOrd(std::vector<int>& intsVec, int wordsVecSize){
    //variables
    int rdmNum;
    
    //creator of random number    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,wordsVecSize-1);

    //cycle to swap words and randomize order
    for (int i = 0; i < intsVec.size()-1 ; i++)
    {
        rdmNum = dis(gen);
        std::swap(intsVec[i], intsVec[rdmNum]);
    }
}

int Utils::showMenu(){    
    //variables
    int option;

    //execution
    std::cout << "\n========================================\n";
    std::cout << "BIENVENIDO A LAS PRUEBAS DE ORDENAMIENTO\n";
    std::cout << "========================================\n";
    std::cout << "1. Quick Sort" << std::endl;
    std::cout << "2. Heap Sort" << std::endl;
    std::cout << "3. AVL Tree" << std::endl;
    std::cout << "4. Finalizar el programa" << std::endl;
    std::cout << "Ingrese la opcion que desee ejecutar: ";

    // Try reading the number
    if (std::cin >> option) {
        //Enter here if the option is a number
        if (option >= 1 && option <= 4) {
            return option;
        } 
        //Enter here if the option is out of range
        else {
            std::cout << "\nEl numero debe estar entre 1 y 4.\n\n";
            //Extra option to repeat cycle
            return 5;
        }
    } 
    else {
        // Enter heres if the option is not a number
        std::cout << "\nEl numero debe estar entre 1 y 4.\n\n";
        
        // clean the console error
        std::cin.clear(); 
        
        // Clean the wrong use input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //Extra option to repeat cycle in this case of error
        return 5;
    }
}

// Auxiliar function to stop the function and continue in a more clean way
void Utils::pauseConsole() {
    std::cout << "\nPresione Enter para continuar...";
    // Cleans any rests from std::cin >> option
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); 
}