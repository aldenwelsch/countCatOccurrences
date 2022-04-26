#include <iostream>
#include "gtest/gtest.h"
#include "substringCounter.hpp"
#include "stringHelpers.hpp"
#include "fileHandler.hpp"

TEST(SubstringCounterTest, BasicCatTest) 
{
    std::string inputString = "cat";
    SubstringCounter counter = SubstringCounter(inputString, "cat");
    counter.findSubstringInString();
    ASSERT_EQ(1, counter.getNumberOfOccurrences());

    counter.setNewInputString("catcatcat");
    counter.findSubstringInString();
    ASSERT_EQ(3, counter.getNumberOfOccurrences());

    counter.setNewInputString("al;j hge;rwlcataowigebnas;ogib");
    counter.findSubstringInString();
    ASSERT_EQ(1, counter.getNumberOfOccurrences());

    counter.setNewInputString("aw'p;eingiopng[nCataw'gklnecatpi");
    counter.findSubstringInString();
    ASSERT_EQ(1, counter.getNumberOfOccurrences());

    counter.setNewInputString("cata;sloknso[aihgbnocaatcaaaatccccaatcatttcccaaattt;als;aslkjhdfbscat");
    counter.findSubstringInString();
    ASSERT_EQ(3, counter.getNumberOfOccurrences());

    counter.setNewInputString(R"(
    catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcat
    catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcat
    catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcat
    catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcat
        )");
    counter.findSubstringInString();
    ASSERT_EQ(144, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputTooShort) 
{
    std::string inputString = "";
    SubstringCounter counter = SubstringCounter(inputString, "cat");
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());

    counter.setNewInputString("c");
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());

    counter.setNewInputString("ca");
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputHasWhitespace) 
{
    std::string inputString = "c at ca\nt c\rat ca\tt ca\vt c\fat";
    SubstringCounter counter = SubstringCounter(inputString, "cat");
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());

    // Set to ignore whitespace
    stringFormatter(inputString, false, true);
    counter.setNewInputString(inputString);
    ASSERT_EQ("catcatcatcatcatcat", inputString);

    counter.findSubstringInString();
    ASSERT_EQ(6, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputHasCapitals) 
{
    std::string inputString = "cat Cat cAt caT CAt CaT cAT CAT";
    SubstringCounter counter = SubstringCounter(inputString, "cat");
    counter.findSubstringInString();
    ASSERT_EQ(1, counter.getNumberOfOccurrences());

    // Set to be case-insensitive
    stringFormatter(inputString, true, false);
    counter.setNewInputString(inputString);
    ASSERT_EQ("cat cat cat cat cat cat cat cat", inputString);

    counter.findSubstringInString();
    ASSERT_EQ(8, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputHasWhitespaceAndCapitals) 
{
    std::string inputString = "c at Ca\nt c\rAt ca\tT CA\vt CaT cAT CA\fT";
    SubstringCounter counter = SubstringCounter(inputString, "cat");
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace
    stringFormatter(inputString, true, true);
    counter.setNewInputString(inputString);
    ASSERT_EQ("catcatcatcatcatcatcatcat", inputString);

    counter.findSubstringInString();
    ASSERT_EQ(8, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputAndSubstringHaveWhitespaceAndCapitals) 
{
    std::string substring = "C\nA t";
    std::string inputString = "c at Ca\nt c\rAt ca\tT CA\vt CaT cAT CA\fT";
    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.findSubstringInString();
    ASSERT_EQ(0, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    ASSERT_EQ("catcatcatcatcatcatcatcat", inputString);
    ASSERT_EQ("cat", substring);

    counter.findSubstringInString();
    ASSERT_EQ(8, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, GenericSubstring) 
{
    std::string substring = "a;a;wlkGh wasdglbn \naeaw;lkt";
    std::string inputString = "awgne;alwknpasha;a;wlkGh wasdglbn \naeaw;lkt;lkjbna;a;wlkGh wasdglbn aeaw;lkta;a;wlkGh wasdglbn \naeaw;lkta;a;wlkGh wasdglbn \naeaw;lkt";
    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.findSubstringInString();
    ASSERT_EQ(3, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    ASSERT_EQ("awgne;alwknpasha;a;wlkghwasdglbnaeaw;lkt;lkjbna;a;wlkghwasdglbnaeaw;lkta;a;wlkghwasdglbnaeaw;lkta;a;wlkghwasdglbnaeaw;lkt", inputString);
    ASSERT_EQ("a;a;wlkghwasdglbnaeaw;lkt", substring);

    counter.findSubstringInString();
    ASSERT_EQ(4, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, UncommonStrings) 
{
    std::string inputString = "ca± µ± A±µA±µA±µ A ± µ";
    std::string substring = "A±µ";
    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.findSubstringInString();
    ASSERT_EQ(3, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    counter.findSubstringInString();
    ASSERT_EQ(5, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputIsFromFile) 
{
    FileHandler fileHandler = FileHandler("./test/input.txt", "");
    std::string substring = "Asdf c";
    std::string inputString = fileHandler.readInputFile();

    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.findSubstringInString();
    ASSERT_EQ(1, counter.getNumberOfOccurrences());

    substring = "cat";
    counter.setNewSubstring(substring);
    counter.findSubstringInString();
    ASSERT_EQ(4, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    counter.findSubstringInString();
    ASSERT_EQ(11, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, InputIsFromBinaryFile) 
{
    FileHandler fileHandler = FileHandler("./test/binaryInput", "");
    std::string inputString = fileHandler.readInputFile();
    std::string substring = "cat";

    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.setNewInputString(inputString);
    counter.findSubstringInString();
    ASSERT_EQ(174, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    counter.findSubstringInString();
    ASSERT_EQ(175, counter.getNumberOfOccurrences());
}

TEST(SubstringCounterTest, LargeFile) 
{
    FileHandler fileHandler = FileHandler("./test/largeInput.txt", "");
    std::string inputString = fileHandler.readInputFile();
    std::string substring = "cat";

    SubstringCounter counter = SubstringCounter(inputString, substring);
    counter.setNewInputString(inputString);
    counter.findSubstringInString();
    ASSERT_EQ(16384648, counter.getNumberOfOccurrences());

    // Set to be case-insensitive and ignore whitespace for both input string and substring
    stringFormatter(inputString, true, true);
    stringFormatter(substring, true, true);
    counter.setNewInputString(inputString);
    counter.setNewSubstring(substring);
    counter.findSubstringInString();
    ASSERT_EQ(32769296, counter.getNumberOfOccurrences());
}
