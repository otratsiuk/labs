#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>


class Archiver{
private:
    struct Segment{
        double left;
        double right;
        char character;
    };

    std::map<char, int> letters;
    std::map<char, double> probability;
    int numberOfLetters = 0;

private:    
    void countLetters(std::string &fileName);
    void countProbability();
    std::map<char, Segment> defineSegmentsForCode(); 
    std::map<char, Segment> defineSegmentsForDecode();

public:
    Archiver();
    void arithmeticCode(std::string &fileName);
    void arithmeticDecode(std::string &fileName);
};
