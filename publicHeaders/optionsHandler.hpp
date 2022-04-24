#include <iostream>
#include <string>

// Defines the input mode. Using enum class rather than bool to provide expandability
enum class InputMode
{
    console,
    file,
    continuous
};

/**
 * @brief OptionsHandler: handles the console arguments provided for CountCatOccurrences.
 * Options include:
 *  Whether to use a file input, console input, continuous console input (via stdin)
 *      If using file input, specify the filepath
 *      If using console input, specify the input   
 *  Whether to be case-sensitive when comparing to "cat"
 *  Whether to allow for general substring matching 
 *      If allowing for general substring matching, specify the substring to match
 *  Whether to output result to a file
 *      If outputting to a file, specify the filepath
 *  Output a help menu
 */
class OptionsHandler
{


    public:
        OptionsHandler(int argc, char** argv);
        bool parseOptions();
        void displayMenu();

        bool isCaseSensitive() { return caseSensitive; };
        bool isWhitespaceIgnored() { return whitespaceIgnored; };
        bool isOutputToFile() { return outputToFile; };
        bool isNewSubstring() { return newSubstring; };

        std::string getInputFilepath() { return inputFilepath; };
        std::string getOutputFilepath() { return outputFilepath; };
        std::string getSubstring() { return substring; };
        std::string getInputString() {return inputString; };

        InputMode getInputMode() { return inputMode; };

        

    private:
        int argCount;
        char** argList;

        InputMode inputMode;

        bool caseSensitive;
        bool whitespaceIgnored;
        bool outputToFile;
        bool newSubstring;

        std::string inputFilepath;
        std::string outputFilepath;
        std::string substring;

        // String to find/count occurrences of substring in (only used in console mode)
        std::string inputString;

        void parseOptionalFlags(int index);
        bool isValidFilepath(std::string);
        bool storeArgListFilepathIfValid(int index);
};



