#include "substringCounter.hpp"
#include "optionsHandler.hpp"
#include "fileHandler.hpp"

int main(int argc, char** argv)
{
    helloWorld();

    OptionsHandler options = OptionsHandler(argc, argv);

    // TODO: Add fileHandler instance


    // Identify the input string and substring
    std::string inputString = "";
    std::string substring = "cat"; // default value

    // If a substring was specified by the user, use that instead of the default
    if (options.isNewSubstring())
    {
        substring = options.getSubstring();
    }

    // If in console mode, we get the input string directly from the options
    if (options.getInputMode() == InputMode::console)
    {
        inputString = options.getInputString();
    }


    SubstringCounter counter = SubstringCounter(inputString, substring);



    return 0;
}