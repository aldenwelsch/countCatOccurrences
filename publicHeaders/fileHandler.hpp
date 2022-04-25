#include <string>

class FileHandler
{
    public:
        FileHandler(std::string inputFilepath, std::string outputFilepath);

        std::string readInputFile(bool isCaseInsensitive = false, bool isWhitespaceIgnored = false);
        void outputResultToFile(std::string text);
        
    private:
        std::string m_inputFile;
        std::string m_outputFile;

        /**
         * @brief stringFormatter
         *  This function formats the provided string by changing all characters to lowercase and 
         *  removing whitespace (and EOL characters) as indicated by the arguments 
         * 
         * @param text The string to format
         * @param isCaseInsensitive boolean to indicate whether to change characters to lowercase 
         * @param isWhitespaceIgnored bool to indicate whether to remove whitespace and OEL characters
         */
        void stringFormatter(std::string &text, bool isCaseInsensitive, bool isWhitespaceIgnored);
};

/**
 * @brief isSpace
 *  A helper function specifying if a character is whitespace (including endline characters)
 * 
 * @param c the character to check
 * @return true if the character is whitespace
 * @return false otherwise
 */
bool isSpace(unsigned char c);