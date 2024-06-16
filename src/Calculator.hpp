#pragma once
#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <sstream>
#include <string>

class Calculator
{
private:
    std::map<std::string, double> var;

    void run(std::string);
    bool cal(std::istream &, std::string Prefix = "? ");
    std::pair<double, std::string> calculateExpression(std::string &, std::string);
    std::pair<double, std::string> calculateSimpleExpression(char &, std::string &, std::string &);

public:
    Calculator(){};
    void first();
    void start();
};

bool isNumber(const std::string &str);