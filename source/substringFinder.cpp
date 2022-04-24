#include <iostream>
#include "substringFinder.hpp"

void helloWorld()
{
    std::cout << "Hello world" << std::endl;
}

SubstringFinder::SubstringFinder(std::string inputString, std::string substring)
{
    inputString = inputString;
    substringToFind = substring;
}

void SubstringFinder::setNewSubstring(std::string substring)
{
    substringToFind = substring;
}

void SubstringFinder::setNewInputString(std::string inputString)
{
    inputString = inputString;
}

bool SubstringFinder::findSubstringInString()
{
    return false;
}