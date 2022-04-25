#include <iostream>
#include <string>
#include "optionsHandler.hpp"
#include "fileHandler.hpp"

OptionsHandler::OptionsHandler(int argc, char** argv)
{
    // Take in the arguments
    m_argCount = argc;
    m_argList = argv;

    // Set up default values
    m_caseInsensitive = false;
    m_whitespaceIgnored = false;
    m_outputToFile = false;
    m_newSubstring = false;

    m_inputFilepath = "";
    m_outputFilepath = "";
    m_substring = "";

    parseOptions();
}

bool OptionsHandler::parseOptions()
{
    // Protect against too many arguments since we use a for-loop based on the argument count
    if (m_argCount > 9)
    {
        std::cout << "Too many arguments provided." << std::endl;
        displayMenu();
        return false;
    }
    
    // Default case - no arguments 
    if (m_argCount < 2)
    {
        // Just display help menu
        std::cout << "Please provide arguments" << std::endl;
        displayMenu();
        return false;
    }
    else
    {
        // Determine the input mode
        if (std::string(m_argList[1]) == "file")
        {
            m_inputMode = InputMode::file;

            // Check the next positional argument for valid filepath
            if (storeArgListFilepath(2, m_inputFilepath) == false)
            {
                return false;
            }
            
            // Get remaining argument flags
            parseOptionalFlags(3);
        }
        else if (std::string(m_argList[1]) == "console")
        {
            m_inputMode = InputMode::console;

            // Get the next positional argument - that's the input string (even if it matches an argument flag)
            if (m_argCount >= 3)
            {
                m_inputString = m_argList[2];
                std::cout << "input string: " << m_inputString << std::endl;
            }
            
            // Get remaining argument flags
            parseOptionalFlags(3);
        }
        else if (std::string(m_argList[1]) == "continuous")
        {
            m_inputMode = InputMode::continuous;
            
            // Get remaining argument flags
            parseOptionalFlags(2);
        }
        else
        {
            if (std::string(m_argList[1]) != "--help" && std::string(m_argList[1]) != "-h")
            {
                std::cout << "Invalid argument or no input mode was provided." << std::endl;
            }
            displayMenu();
            return false;
        }
    }
    return true;
}

void OptionsHandler::parseOptionalFlags(int index)
{
    for (int i = index; i < m_argCount; i++)
    {
        std::string arg = m_argList[i];
        if (arg.compare("--help") == 0 || arg.compare("-h") == 0)
        {
            displayMenu();
            return;
        }
        else if (arg.compare("--caseInsensitive") == 0 || arg.compare("-c") == 0)
        {
            m_caseInsensitive = true;
        }
        else if (arg.compare("--ignoreWhitespace") == 0 || arg.compare("-i") == 0)
        {
            m_whitespaceIgnored = true;
        }
        else if (arg.compare("--output") == 0 || arg.compare("-o") == 0)
        {
            m_outputToFile = true;
            if (storeArgListFilepath(i + 1, m_outputFilepath) == false)
            {
                
                return;
            }
            // skip the next item since that was stored as filepath
            i++;
        }
        else if (arg.compare("--substring") == 0 || arg.compare("-s") == 0)
        {
            if (m_argCount > i + 1)
            {
                // store as substring and skip next item
                m_substring = m_argList[++i];
                m_newSubstring = true;
            }
            else
            {
                std::cout << "Substring flag was found, but no substring provided." << std::endl;
            }
        }
    }
}

void OptionsHandler::displayMenu()
{
    // TODO: output help menu
    std::string menuString = R"(
CountCatOccurrences <input mode> [flags]

input mode:
    file <filepath>                 input string is provided by the contents of a file. Enter the filepath
                                        of the text file to read as input when in "file" mode
    console <inputText>             input string is provided at the console as a console argument. Enter 
                                        the string to search. Use quotations if the desired string contains 
                                        whitespace
    continuous                      input string provided by the user when prompted by the application

flags:
    -h, --help                      display the help menu
    -c, --caseInsensitive           make the search case-insensitive
    -i, --ignoreWhitespace          ignore whitespace in the search
    -o, --output <output file>      output the result to a file. Specify the filepath for the output file
    -s, --substring <substring>     use a different substring other than the default "cat". Specify the substring
    )";
    std::cout << menuString << std::endl;

}

bool OptionsHandler::storeArgListFilepath(int index, std::string &filepath)
{
    if (m_argCount > index)
    {
        filepath = m_argList[index];
        return true;
    }
    std::cout << "No filepath provided." << std::endl;
    return false;
}