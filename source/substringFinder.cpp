#include <string>
#include <vector>
#include "substringFinder.hpp"

SubstringFinder::SubstringFinder(std::string inputString, std::string substring)
{
    m_inputString = inputString;
    m_substring = substring;
}

void SubstringFinder::setNewSubstring(std::string substring)
{
    m_substring = substring;
}

void SubstringFinder::setNewInputString(std::string inputString)
{
    m_inputString = inputString;
}

void SubstringFinder::storeFoundOccurrence(unsigned long index)
{
    m_occurrences.push_back(index);
}

void SubstringFinder::resetOccurrences()
{
    m_occurrences.clear();
}

bool SubstringFinder::findSubstringInString()
{
    // Reset occurrences in case this isn't the first time this function has been called
    resetOccurrences();

    // Assume we don't find any matches
    bool matchFound = false;

    // Get the lengths of the strings and instantiate the Lps array (vector) with the size of the substring
    unsigned long inputStringLength = m_inputString.length();
    unsigned long substringLength = m_substring.length();
    std::vector<unsigned long> longestPrefixArray(substringLength);



    // Build the Lps array
    buildLongestPrefixArray(m_substring, longestPrefixArray);

    // Create two runners
    unsigned long i = 0;
    unsigned long j = 0;

    while ( i < inputStringLength)
    {
        // If there is a match, go to the next item in both strings
        if ( m_substring[j] == m_inputString[i]) 
        {
            i++;
            j++;
        }
        
        // Check if we've reached the substringLength. If so, then we know that we have matched the substring, so store the occurrence
        if (j == substringLength)
        { 
            storeFoundOccurrence(i - substringLength);
            matchFound = true;

            // Since we've found an occurrence, set the index of the substring, j, to the previous length of longest prefix
            j = longestPrefixArray[j - 1]; 
        } 
        // If we haven't exceeded the length of the inputString and the current character of the substring and the inputString don't 
        // match, then we want to either check the next character in the 
        else if (i < inputStringLength && m_substring[j] != m_inputString[i])
        {
            // if the first character of the substring doesn't match, then we just want to look at the next item in the inputString
            if (j == 0)
            {
                i++;
            }
            // If we're not looking at the first character of the substring, then we want to set the index of the substring, j, to
            // the previous length of longest prefix
            else
            {
                j = longestPrefixArray[j - 1];
            }
        }
    }

    return matchFound;
}

void SubstringFinder::buildLongestPrefixArray(std::string substring, std::vector<unsigned long> &longestPrefixArray)
{
    // First index will be zero
    longestPrefixArray[0] = 0;
    unsigned long lengthOfPrefix = 0;

    // Start with the second character in the substring (if there is one)
    unsigned long i = 1;
    while (i < substring.length())
    {
        // If we have a match, add to the length of the prefix and store in the array
        if ( substring[i] == substring[lengthOfPrefix])
        {
            lengthOfPrefix++;
            longestPrefixArray[i] = lengthOfPrefix;
            i++;
            continue;
        }
        else
        {
            // If we don't have a match and previous length is 0, restart the length of the prefix and set to zero in the array
            if (lengthOfPrefix == 0)
            {
                longestPrefixArray[i] = 0;
                i++;
                continue;
            }
            // If we don't have a match, but the previous length is >0, then the new length of the prefix is the previous length
            else
            {
                lengthOfPrefix = longestPrefixArray[lengthOfPrefix - 1];
                // Don't increment i since we need to check for a match again 
                continue;
            }
        }
    }
}
