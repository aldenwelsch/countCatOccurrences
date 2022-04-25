#include "substringFinder.hpp"

/**
 * @brief SubstringCounter: a class derived from substringFinder to specifically look for number of substring 
 *  occurrences.
 * 
 *  This doesn't necessarily need to be a separate derived class from SubstringFinder to make it work, with only 
 *  the addition of the count of occurrences, but by making it a derived class, we can use the base class to 
 *  expand on more generic use cases. What if next time we want a substringReplacer, too? Perhaps we need to 
 *  other functionality using substringFinder other than just getting the number of occurrences of the substring?
 *  For the small amount of extra effort, we gain easy expandability.
 */
class SubstringCounter : public SubstringFinder
{
    public:
        SubstringCounter(std::string inputString, std::string substring);
        
        unsigned long getNumberOfOccurrences() { return m_numberOfOccurrences; };
    
    private:

        unsigned long m_numberOfOccurrences;

    protected:

        /** 
         * @brief storeFoundOccurrence
         *  This overrides the virtual function defined in substringFinder so that the occurrence-finding 
         *  algorithm increments the occurrence counter instead of storing the index. When storing the indices
         *  of the occurrences in the SubstringFinder class, we use space complexity of O(n) in the worst case.
         *  By only incrmenting the occurrence counter in this class, we avoid space complexity of O(n) and 
         *  instead have space complexity of just the stored value of the occurrence counter, O(1).
         */
        void storeFoundOccurrence(unsigned long index);
};