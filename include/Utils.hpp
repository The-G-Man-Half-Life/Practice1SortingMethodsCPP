//include guards
#pragma once

//importation of necessary elements
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <random>


class Utils
{
private:

public:
    //methods
    static std::vector<std::string> readWordsFromFile(std::string& ubication);
    static std::vector<int> convertWordsToInts(int wordsVecSize);
    static void randomizeWordsOrd(std::vector<int>& intsVec, int wordsVecSize);
    static int showMenu();
    static void pauseConsole();
};

