#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "fileHandler.hpp"

FileHandler::FileHandler(std::string inputFilepath, std::string outputFilepath)
{
    m_inputFile = inputFilepath;
    m_outputFile = outputFilepath;
}

std::string FileHandler::readInputFile(bool isCaseInsensitive, bool isWhitespaceIgnored)
{
    std::string fileString = "";

    // Open file
    std::ifstream inputFileHandler(m_inputFile);
    
    // Read file if successfully opened
    if (inputFileHandler.is_open())
    {
        std::stringstream buffer;
        buffer << inputFileHandler.rdbuf();

        // Convert to string
        fileString = buffer.str();

        // Close file
        inputFileHandler.close();
    }
    else
    {
        std::cout << "Could not open input file: " << m_inputFile << ". Exiting with error code 1" << std::endl;
        exit(1);
    }

    // Format string according to options
    stringFormatter(fileString, isCaseInsensitive, isWhitespaceIgnored);

    return fileString;
}

void FileHandler::outputResultToFile(std::string text)
{
    // Open file
    std::ofstream outputFileHandler(m_outputFile);

    // If opened successfully, write to file (assuming overwrite existing)
    if (outputFileHandler.is_open())
    {
        outputFileHandler << text;

        // Close file
        outputFileHandler.close();
    }
    else
    {
        std::cout << "Could not open output file: " << m_outputFile << ". Exiting with error 1" << std::endl;
        exit(1);
    }
}

void FileHandler::stringFormatter(std::string &text, bool isCaseInsensitive, bool isWhitespaceIgnored)
{
    // Convert characters to lowercase
    if (isCaseInsensitive)
    {
        std::transform(text.begin(), text.end(), text.begin(), 
        [](unsigned char c)
        {  
            return std::tolower(c);
        });
    }
    if (isWhitespaceIgnored)
    {
        // Remove whitespace      
        text.erase(std::remove_if(text.begin(), text.end(), isSpace), text.end());
    }

    std::cout << "New text: " << text << std::endl;
}

bool isSpace(unsigned char c) {
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f');
}