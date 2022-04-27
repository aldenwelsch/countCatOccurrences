#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler
{
    public:
        FileHandler(std::string inputFilepath, std::string outputFilepath);

        /**
         * @brief readInputFile
         *  Reads the contents of the member-stored input file
         * 
         * @return std::string The contents of the file
         */
        std::string readInputFile();

        /**
         * @brief outputResultToFile
         *  Outputs the text to file (the stored member output file)
         * 
         * @param text The text to write in the output file
         */
        void outputResultToFile(std::string text);
        
    private:
        std::string m_inputFile;
        std::string m_outputFile;
};

#endif