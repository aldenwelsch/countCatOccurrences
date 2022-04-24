#include "optionsHandler.hpp"
#include <iostream>
#include <string>

OptionsHandler::OptionsHandler(int argc, char** argv)
{
    // Take in the arguments
    argCount = argc;
    argList = argv;

    // Set up default values
    caseSensitive = false;
    whitespaceIgnored = false;
    outputToFile = false;
    newSubstring = false;

    inputFilepath = "";
    outputFilepath = "";
    substring = "";

    parseOptions();
}

bool OptionsHandler::parseOptions()
{
    // Default case - no arguments 
    if (argCount < 2)
    {
        // Just display help menu
        std::cout << "Please provide arguments" << std::endl;
        displayMenu();
        return false;
    }
    else
    {
        std::cout << "checking input mode" << std::endl;

        // Determine the input mode
        if (std::string(argList[1]) == "file")
        {
            inputMode = InputMode::file;

            // Check the next positional argument for valid filepath
            if (storeArgListFilepathIfValid(1) == false)
            {
                return false;
            }
            
            // Get remaining argument flags
            parseOptionalFlags(3);
        }
        else if (std::string(argList[1]) == "console")
        {
            inputMode = InputMode::console;

            // Get the next positional argument - that's the input string (even if it matches an argument flag)
            if (argCount >= 3)
            {
                inputString = argList[2];
                std::cout << "input string: " << inputString << std::endl;
            }
            
            // Get remaining argument flags
            parseOptionalFlags(3);
        }
        else if (std::string(argList[1]) == "continuous")
        {
            inputMode = InputMode::continuous;
            
            // Get remaining argument flags
            parseOptionalFlags(2);
        }
        else
        {
            std::cout << "Invalid argument or no input mode was provided." << std::endl;
            displayMenu();
            return false;
        }
    }
    return true;
}

void OptionsHandler::parseOptionalFlags(int index)
{
    for (int i = index; i < argCount; i++)
    {
        std::string arg = argList[i];
        if (arg.compare("--help") == 0 || arg.compare("-h") == 0)
        {
            displayMenu();
            return;
        }
        else if (arg.compare("--caseSensitive") == 0 || arg.compare("-c") == 0)
        {
            caseSensitive = true;
        }
        else if (arg.compare("--ignoreWhitespace") == 0 || arg.compare("-i") == 0)
        {
            whitespaceIgnored = true;
        }
        else if (arg.compare("--output") == 0 || arg.compare("-o") == 0)
        {
            outputToFile = true;
            if (storeArgListFilepathIfValid(i) == false)
            {
                
                return;
            }
            // skip the next item since that was stored as filepath
            i++;
        }
        else if (arg.compare("--substring") == 0 || arg.compare("-s") == 0)
        {
            if (argCount > i + 1)
            {
                // store as substring and skip next item
                substring = argList[++i];
                newSubstring = true;
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
    std::cout << "Here's the menu" << std::endl;
}

bool OptionsHandler::isValidFilepath(std::string filepath)
{
    // TODO: check for valid filepath
    return true;
}

bool OptionsHandler::storeArgListFilepathIfValid(int index)
{
    if (argCount > index + 1)
    {
        std::string filepath = argList[index];
        if (isValidFilepath(filepath))
        {
            inputFilepath = filepath;
            return true;
        }
    }
    std::cout << "Invalid or no filepath provided." << std::endl;
    return false;
}