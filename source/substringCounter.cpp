#include <string>
#include "substringCounter.hpp"

SubstringCounter::SubstringCounter(std::string inputString, std::string substring) : SubstringFinder(inputString, substring)
{
    m_numberOfOccurrences = 0;
}

void SubstringCounter::storeFoundOccurrence(unsigned long index)
{
    // Don't need to use the argument, just increment the counter
    m_numberOfOccurrences++;
}

void SubstringCounter::resetOccurrences()
{
    m_numberOfOccurrences = 0;
}