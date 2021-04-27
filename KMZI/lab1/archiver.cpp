#include "archiver.h"

Archiver::Archiver(){}

void Archiver::countLetters(std::string &fileName){
    std::fstream file(fileName);
   
    char letter;
    while (file >> letter)
    {
        numberOfLetters++;

        if(letters.contains(letter)){
            letters.at(letter)++;
        }
        else{
            letters.insert(std::pair<char, int>(letter, 1));
        }
    }
}

void Archiver::countProbability(){
    double letterCost = static_cast<double>(1)/static_cast<double>(numberOfLetters);

    for(auto &_ : letters){
        probability.insert(std::pair<char, double>(_.first, static_cast<double>(_.second * letterCost)));
    }
}

std::map<char, Archiver::Segment> Archiver::defineSegmentsForCode(){
    std::map<char, Archiver::Segment> segment;
    double l = 0;

    for(auto &p : probability){
        segment.insert(std::make_pair(p.first, Segment{l, l + p.second}));
        l = segment.at(p.first).right;
    }

    return segment;
}

void Archiver::arithmeticCode(std::string &fileName){
    std::fstream file(fileName);
    countLetters(fileName);
    countProbability();

    std::map<char, Archiver::Segment> segment = defineSegmentsForCode();

    double left = 0;
    double right = 1;

    char s;
    while(file >> s){
        double newRight = left + (right - left) * segment.at(s).right;
        double newLeft = left + (right - left) * segment.at(s).left;
        left = newLeft;
        right = newRight;
    }
    file.close();
    file.open(fileName, std::ios_base::out | std::ios_base::trunc);

    double result = (left + right) / 2;

    std::stringstream str;
    str << std::fixed << std::setprecision(16) << result;
    file << str.str();

    file.close();
}

std::map<char, Archiver::Segment> Archiver::defineSegmentsForDecode(){
    std::map<char, Archiver::Segment> segment;
    double l = 0;

    for(auto &p : probability){
        segment.insert(std::make_pair(p.first, Segment{l, l + p.second, p.first}));
        l = segment.at(p.first).right;
    }

    return segment;
}

void Archiver::arithmeticDecode(std::string &fileName){
    std::fstream file(fileName);

    double code;
    file >> code;
    file.close();

    file.open(fileName, std::ios_base::out | std::ios_base::trunc);

    std::map<char, Archiver::Segment> segment = defineSegmentsForDecode();
    
    for(int i = 0; i < numberOfLetters; i++){
        for(auto &_ : segment){
            if(code >= _.second.left && code < _.second.right){
                file << _.second.character;
                code = (code - _.second.left) / (_.second.right - _.second.left);
                break;
            }
        }
    }
    file.close();
}
