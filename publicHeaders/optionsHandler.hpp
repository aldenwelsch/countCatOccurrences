#ifndef OPTIONSHANDLER_H
#define OPTIONSHANDLER_H

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

        /**
         * @brief isCaseInsensitive
         *  Gets the boolean of whether the class has been set to be caseInsensitive
         * 
         * @return true if case insensitive
         * @return false otherwise
         */
        bool isCaseInsensitive() { return m_caseInsensitive; };

        /**
         * @brief isWhitespaceIgnored
         *  Gets the boolean of whether the class has been set to have whitespace ignored
         * 
         * @return true if whitespace is to be ignored
         * @return false otherwise
         */
        bool isWhitespaceIgnored() { return m_whitespaceIgnored; };

        /**
         * @brief isOutputToFile
         *  Gets the boolean of whether the class will output the result to file or not
         * 
         * @return true if output to file is set
         * @return false otherwise
         */
        bool isOutputToFile() { return m_outputToFile; };

        /**
         * @brief isNewSubstring
         *  Gets the boolean of whether the class will use a different substring than "cat", user-specified
         * 
         * @return true if a different substring is to be used
         * @return false otherwise
         */
        bool isNewSubstring() { return m_newSubstring; };

        /**
         * @brief Get the Input Filepath object
         * 
         * @return std::string the filepath
         */
        std::string getInputFilepath() { return m_inputFilepath; };

        /**
         * @brief Get the Output Filepath object
         * 
         * @return std::string The filepath
         */
        std::string getOutputFilepath() { return m_outputFilepath; };

        /**
         * @brief Get the Substring object
         * 
         * @return std::string The new substring
         */
        std::string getSubstring() { return m_substring; };

        /**
         * @brief Get the Input String object
         * 
         * @return std::string the specified input string
         */
        std::string getInputString() {return m_inputString; };

        /**
         * @brief Get the Input Mode object
         * 
         * @return InputMode The stored input mode
         */
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

#endif