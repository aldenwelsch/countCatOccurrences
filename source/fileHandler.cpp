#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "fileHandler.hpp"

FileHandler::FileHandler(std::string inputFilepath, std::string outputFilepath)
{
    m_inputFile = inputFilepath;
    m_outputFile = outputFilepath;
}

std::string FileHandler::readInputFile()
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
