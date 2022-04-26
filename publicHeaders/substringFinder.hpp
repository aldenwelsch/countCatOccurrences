#include <string>
#include <vector>

/**
 * @brief SubstringFinder: A class to find all occurrences of a substring sub[0...m-1] in an input
 *  string in[0...n-1]. 0 <= m <= n <= MAX.
 * 
 *  Notes on time complexity:
 *  This class is an implementation of the classic KMP pattern search algo, which has O(n)
 *  time complexity in the worst case. 
 * 
 *  The Naive approach to this implementation would just iterate through the input 
 *  string and check for subsequent substring characters (m), resulting in O((n-m+1)m) worst case, 
 *  but could have a best case of O(n) (as m->n or m->1)).
 * 
 *  In the case of this CountCatOccurrences application, we know that the substring is simply "cat",
 *  so m->3->1. If we used the Naive algo, we know that where m = 3 (O(1)), the time complexity 
 *  reduces to O((n-3+1)3), which simplifies to O(n) in the worst case, which is the same  for the
 *  KMP algorithm implemented here. The advantage of KMP over the Naive algorithm, for time 
 *  complexity, is in the general case, not this specific case of the "cat" substring.
 * 
 *  Notes on space complexity:
 *  Since this is an implementation of KMP, the space complexity is O(m) because we have to store
 *  the LPS array (the same length as the substring, m). 
 * 
 *  If we want to store all the indexes of the found occurrences, the space complexity adds O(n) in 
 *  the worst case, for a total of O(n + m). The derived child SubstringCounter class overrides 
 *  this storage method to avoid this additional space complexity by only incrementing a single value 
 *  for the number of occurrences, resulting in just O(m) space complexity.
 *  
 *  For the specific case of this CountCatOccurrences application, we know that the substring is 
 *  simply "cat", so m->3->1, and thus, the space complexity is O(1).
 * 
 */
class SubstringFinder
{
    public:
        SubstringFinder(std::string inputString, std::string substring);

        void setNewSubstring(std::string substring);
        void setNewInputString(std::string inputString);

        /**
         * @brief findSubstringInString
         *  This function implements a KMP pattern search for the substring in the input string stored
         *  as member variables of this class
         * 
         * @return true if occurrences were found
         * @return false otherwise
         */
        bool findSubstringInString();

    private:
        
        std::string m_substring;
        std::string m_inputString;

        // Make this virtual to declare the derived class can overload
        /**
         * @brief storeFoundOccurrence
         *  This function stores the input string index of the first character of the matching substring in 
         *  the member vector, occurrences. This will take O(n) space complexity in the worst case (e.g. 
         *  matching substring "a" in "aaaaaaaaa"). O(1) time complexity for each call.
         * 
         * @param index The index in the input string that matches the start of the substring (the found occurrence)
         */
        virtual void storeFoundOccurrence(unsigned long index);
        virtual void resetOccurrences();

        void buildLongestPrefixArray(std::string substring, std::vector<unsigned long> &longestPrefixArray);
    
    protected:
        std::vector<unsigned long> m_occurrences;
        
};