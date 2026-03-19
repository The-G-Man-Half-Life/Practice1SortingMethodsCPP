//includes
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <random>

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

void Utils::randomizeWordsOrd(std::vector<std::string>& wordsVec){
    //variables
    int rdmNum;
    
    //creator of random number    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,99999);

    //cycle to swap words and randomize order
    for (int i = 0; i < wordsVec.size()-1 ; i++)
    {
        rdmNum = dis(gen);
        std::swap(wordsVec[i], wordsVec[rdmNum]);
    }
}