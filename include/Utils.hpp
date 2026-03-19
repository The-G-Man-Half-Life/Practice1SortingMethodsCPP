//include guards
#pragma once

//importation of required elements
#include <vector>
#include <string>


class Utils
{
private:
    //atributes

public:
    //constructor

    //methods
    static std::vector<std::string> readWordsFromFile(std::string& ubication);
    static void randomizeWordsOrd(std::vector<std::string>& wordsVec);
};

