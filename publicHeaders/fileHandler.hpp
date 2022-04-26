#include <string>

class FileHandler
{
    public:
        FileHandler(std::string inputFilepath, std::string outputFilepath);

        std::string readInputFile();
        void outputResultToFile(std::string text);
        
    private:
        std::string m_inputFile;
        std::string m_outputFile;
};
