#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Calculator
{
private:
    std::vector<std::string> var;
    void variables();
    void clear();
    void save();
    void load();
    void about();
    void run(std::string);
    bool fun(std::string);

public:
    Calculator(){};
    void start();
    void cal();
};
