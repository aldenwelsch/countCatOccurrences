#include <iostream>
#include <string>

// Defines the input mode. Using enum class rather than bool to provide expandability
enum class InputMode
{
    console, // input string provided by console argument at application execution
    file, // input string provided by a file
    continuous // input string continually provided by user at the console (prompted by application response, not streaming)
    // Could also provide streaming support, depending on the requirements. Prompt only specified console and file input. 
};

/**
 * @brief OptionsHandler: handles the console arguments provided for CountCatOccurrences.
 *  Options include:
 *      Whether to use a file input, console input, continuous console input (via stdin)
 *          If using file input, specify the filepath
 *          If using console input, specify the input   
 *      Whether to be case-sensitive when comparing to "cat"
 *      Whether to allow for general substring matching 
 *          If allowing for general substring matching, specify the substring to match
 *      Whether to output result to a file
 *          If outputting to a file, specify the filepath
 *      Output a help menu
 */
class OptionsHandler
{
    public:
        OptionsHandler(int argc, char** argv);

        bool isCaseInsensitive() { return m_caseInsensitive; };
        bool isWhitespaceIgnored() { return m_whitespaceIgnored; };
        bool isOutputToFile() { return m_outputToFile; };
        bool isNewSubstring() { return m_newSubstring; };

        std::string getInputFilepath() { return m_inputFilepath; };
        std::string getOutputFilepath() { return m_outputFilepath; };
        std::string getSubstring() { return m_substring; };
        std::string getInputString() {return m_inputString; };
        InputMode getInputMode() { return m_inputMode; };

        /**
         * @brief parseOptions
         *  parses the arguments stored by the constructor and stores member variables
         *  with relevant values.
         * 
         * @return true if parsing completes successfully
         * @return false otherwise
         */
        bool parseOptions();

        /**
         * @brief Displays the argument options at the console.
         * 
         */
        void displayMenu();

    private:
        int m_argCount;
        char** m_argList;

        InputMode m_inputMode;

        bool m_caseInsensitive;
        bool m_whitespaceIgnored;
        bool m_outputToFile;
        bool m_newSubstring;

        std::string m_inputFilepath;
        std::string m_outputFilepath;
        std::string m_substring;

        // String to find/count occurrences of substring in (only used in console mode)
        std::string m_inputString;

        /**
         * @brief parseOptionalFlags
         *  This function parses the remaining arguments starting at the specified index of the
         *  argument list. 
         * 
         * @param index The index of the argument list to start parsing
         */
        void parseOptionalFlags(int index);

        /**
         * @brief storeArgListFilepath
         *  Checks the next argument provided (if there is one) and stores it as the 
         *  provided filepath string
         * 
         * @param index The index of the argument list to store filepath
         * @param filepath The string filepath to write to
         * @return true if stored
         * @return false otherwise
         */
        bool storeArgListFilepath(int index, std::string &filepath);
};
