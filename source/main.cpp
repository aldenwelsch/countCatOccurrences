#include <string>
#include <signal.h>
#include "substringCounter.hpp"
#include "optionsHandler.hpp"
#include "fileHandler.hpp"
#include "stringHelpers.hpp"

// Handle keyboard interrupts for continuous mode
volatile sig_atomic_t userInterruptFlag = 0;
void checkForUserInterrupt(int sig)
{
    userInterruptFlag = 1;
}

void countOccurrences(std::string &inputString, std::string &substring, OptionsHandler &options, FileHandler &fileHandler)
{
    SubstringCounter counter = SubstringCounter(inputString, substring);

    counter.findSubstringInString();
    // Prompt ambiguous on what "output" number of occurrences means, so just 
    // sending the number to stdout.
    std::cout << counter.getNumberOfOccurrences() << std::endl;

    // Output the number of occurrences to file if specified
    if (options.isOutputToFile())
    {
        fileHandler.outputResultToFile(std::to_string(counter.getNumberOfOccurrences()));
    }
}

int main(int argc, char** argv)
{
    signal(SIGINT, checkForUserInterrupt);

    // Create an OptionsHandler instance on the "stack" (automatic memory)
    OptionsHandler options = OptionsHandler(argc, argv);

    // Add fileHandler instance
    FileHandler fileHandler = FileHandler(options.getInputFilepath(), options.getOutputFilepath());

    // Identify the input string and substring
    std::string inputString = "";
    std::string substring = "cat"; // default value

    // If a substring was specified by the user, use that instead of the default
    if (options.isNewSubstring())
    {
        substring = options.getSubstring();
        stringFormatter(substring, options.isCaseInsensitive(), options.isWhitespaceIgnored());
    }

    // If in console mode, we get the input string directly from the options
    if (options.getInputMode() == InputMode::console)
    {
        inputString = options.getInputString();

        // Format strings according to options
        stringFormatter(inputString, options.isCaseInsensitive(), options.isWhitespaceIgnored());
        
        // Count the occurrences in this string
        countOccurrences(inputString, substring, options, fileHandler);
    }
    else if (options.getInputMode() == InputMode::file)
    {
        inputString = fileHandler.readInputFile();
        
        // Format string according to options
        stringFormatter(inputString, options.isCaseInsensitive(), options.isWhitespaceIgnored());

        // Count the occurrences in this string
        countOccurrences(inputString, substring, options, fileHandler);
    }
    else if (options.getInputMode() == InputMode::continuous)
    {
        // Repeatedly prompt the user until exiting for an input
        while(true)
        {
            // Check if user prompts exit
            if (userInterruptFlag == false)
            {
                // Prompt user and get their input
                std::cout << "Enter text to search for substring (\"q\" to quit):" << std::endl << "> ";
                //std::cin >> inputString;
                std::getline(std::cin, inputString);

                // Check if user prompts exit
                if (inputString.compare("q") == 0)
                {
                    userInterruptFlag = true;
                }
            }
            else
            {
                std::cout << "User-prompted exit." << std::endl;
                return 0;
            }

            // Format string according to options
            stringFormatter(inputString, options.isCaseInsensitive(), options.isWhitespaceIgnored());

            // Count the occurrences in this string
            countOccurrences(inputString, substring, options, fileHandler);
        }
    }

    return 0;
}
