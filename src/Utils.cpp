//includes
#include "Utils.hpp"
#include <fstream>
#include <iostream>

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
