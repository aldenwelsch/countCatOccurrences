# countCatOccurences

## Purpose
Homework problem for Overwatch

### Prompt
1. Write a program in C++ that counts the number of occurrences of the word “cat” in incoming text. The program should support two text entry modes: 1) console input, and 2) file input.
2. Write a unit test for your cat counter.
3. Track your work in a Git repository. Deliver your answer as a Git repository on a publicly-accessible website (such as Github) or a zipped folder containing your git repository.


## Assumptions:
- Prompt ambiguous on desired platform
    - Build files assume Linux-only, No Windows, Mac support
    - Can add support by implementing checks in the makefile and adding support for the desired compiler
- Prompt was ambiguous on maximum size of input string, so assuming 32-bit unsigned long max size
    - Running on 32-bit (use of unsigned long vs. unsigned long long in the substringFinder and substringCounter classes)
    - If 64-bit needed, implementation would need to use unsigned long long and compiler check machine support
- "Console input" by the prompt could mean a few things:
    - stdin, console arguments, prompted user inputs during application runtime (i.e. std::cin)
    - This application takes in console arguments in "console" mode and prompted user inputs during runtime in "continuous" mode
- ASCII vs. unicode text was not specified, assuming input could be either
- Prompt does not specify how to present the results
    - Application handles printing to stdout (default) and to file if specified
- Ambiguity around the literal-string for the word "cat". 
    - Application handles case-insensitive or sensitive text matching
    - Application handles whitespace-ignored or whitespace-included text matching
- Prompt does not specify how the application will be used, or need of extensibility for future use
    - Pattern matching is common so application provides an option for general substring matching beyond the specific "cat" string


## Build Dependencies:
### Building for Linux:

- GCC/G++ installed
- Google Test installed
    - Assuming installed at /usr/src/gtest/
- pthread installed

#### Building for Linux on Windows
- Windows Subsystem for Linux 2 (WSL) installed
    - Verify same dependencies are installed


## Installation

Download or clone repository from https://github.com/aldenwelsch/countCatOccurences

1. If downloaded from a compressed archive, extract to desired directory
2. Use a console application to open the archive.
3. At the root directory of the repository, run `make` to build the application


## Tests
Google Test is used to run unit tests on functions of this application. These are run during build time
when `make` is called. See /test/testCountCatOccurrences.cpp for list of unit tests.

## How-to-use

1. After installing, run `./CountCatOccurrences` with the desired options
```
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

```

