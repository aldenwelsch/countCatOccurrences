#include <string>
#include <vector>

void helloWorld();

/**
 * @brief SubstringFinder: A class to find all occurrences of a substring sub[0...m-1] in an input
 *  string in[0...n-1]. 0 <= m <= n <= MAX.
 * 
 *  Notes on time complexity:
 *  This is an implementation of the classic KMP pattern search algo, which runs in O(n) time. The 
 *  Naive approach to this implementation would just iterate through the input string and check for 
 *  subsequent substring characters (m), resulting in O((n-m+1)m) -> O(nm + m^2) (dropping 
 *  significant m) worst case, but could have a best case of O(n)).
 * 
 *  The above is true for the general case, but in the case of this CountCatOccurrences application,
 *  we know that the substring is simply "cat". Whether this is case sensitive, using the Naive algo,
 *  we know that where m = 3, that the time complexity reduces to O((n-3+1)3), which simplifies to 
 *  O(n) in the worst case.
 * 
 */
class SubstringFinder
{
    public:
        // TODO: handle case sensitivity, whitespace handling 
        SubstringFinder(std::string inputString, std::string substring);

        void setNewSubstring(std::string substring);
        void setNewInputString(std::string inputString);
        bool findSubstringInString();

    private:
        
        std::string substringToFind;
        std::string inputString;
    
    protected:
        std::vector<int> occurences;
        
        
};