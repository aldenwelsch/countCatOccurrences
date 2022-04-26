#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    // Initialize
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests
    std::cout << "RUNNING TESTS ..." << std::endl;
    if (RUN_ALL_TESTS() == false)
        std::cout << "<<<SUCCESS>>>" << std::endl;
    else
        std::cout << "FAILED" << std::endl;

    return 0;
}