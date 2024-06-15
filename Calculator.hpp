#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

class Calculator
{
private:
    void variables();
    void clear();
    void save();
    void load();
    void about();
    void run(std::string);

public:
    Calculator(){};
    void start();
    void cal();
};
