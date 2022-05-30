#pragma once
#include <iostream>
#include <vector>


class Polish {

private:

    int value;
    int popValue;
    std::string term;
    std::string output;
    

public:

    char stackOpp(std::vector <char>*);
    bool check (std::vector<char> opperators, std::vector<int> integers);

    std::string returnAlg(std::vector<char> opperators, std::vector<int> integers);






};