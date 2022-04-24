#include "substringFinder.hpp"

/**
 * @brief SubstringCounter: a class derived from substringFinder to specifically look for number of substring 
 *  occurrences.
 * 
 *  This doesn't necessarily need to be a separate derived class from SubstringFinder, with only the addition 
 *  of the count of occurrences, but by making it a derived class, we can use the base class to expand on more 
 *  generic use cases. What if next time we want a substringReplacer, too? Perhaps we need to implement some 
 *  other functionality using substringFinder other than just getting the number of occurrences of the substring?
 *  For the small amount of extra effort, we gain easy expandability.
 */
class SubstringCounter:SubstringFinder
{
    public:
        SubstringCounter(std::string inputString, std::string substring);
        
        void countOccurrencesInString();
        int getNumberOfOccurrences() { return numberOfOccurrences; };
    
    private:

        int numberOfOccurrences;
};