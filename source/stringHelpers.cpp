#include <string>
#include <algorithm>
#include "stringHelpers.hpp"

void stringFormatter(std::string &text, bool isCaseInsensitive, bool isWhitespaceIgnored)
{
    // Convert characters to lowercase
    if (isCaseInsensitive)
    {
        std::transform(text.begin(), text.end(), text.begin(), 
        [](unsigned char c)
        {  
            return std::tolower(c);
        });
    }
    if (isWhitespaceIgnored)
    {
        // Remove whitespace      
        text.erase(std::remove_if(text.begin(), text.end(), isSpace), text.end());
    }
}

bool isSpace(unsigned char c)
{
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f');
}