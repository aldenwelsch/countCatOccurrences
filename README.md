# countCatOccurences

## Purpose
Homework problem for Overwatch

### Prompt
1. Write a program in C++ that counts the number of occurrences of the word “cat” in incoming text. The program should support two text entry modes: 1) console input, and 2) file input.
2. Write a unit test for your cat counter.
3. Track your work in a Git repository. Deliver your answer as a Git repository on a publicly-accessible website (such as Github) or a zipped folder containing your git repository.


## Assumptions:
- Linux-only, No Windows, Mac support
    - Can add support by implementing checks in the makefile and adding support for the desired compiler
- Prompt was ambiguous on maximum size of input string, so assuming 32-bit unsigned long max sizeW
    - Running on 32-bit (use of unsigned long vs. unsigned long long in the substringFinder and substringCounter classes)
    - If 64-bit needed, implementation would need to use unsigned long long and compiler check machine support


## Build Dependencies:
### Building for Linux:
Running on Windows
- Windows Subsystem for Linux 2 (WSL) installed
- GCC/G++ installed in WSL

Running on Linux 
- GCC/G++ installed


## Installation

Download or clone repository from https://github.com/aldenwelsch/countCatOccurences

1. If downloaded from a compressed archive, extract to desired directory
2. Use a console application to open the archive.
3. At the root directory of the repository, run `make`


## Tests


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

