#include "substringCounter.hpp"

SubstringCounter::SubstringCounter(std::string inputString, std::string substring) : SubstringFinder(inputString, substring)
{
    countOccurrencesInString();
    numberOfOccurrences = 0;
}

void SubstringCounter::countOccurrencesInString()
{
    numberOfOccurrences = occurences.size();
}