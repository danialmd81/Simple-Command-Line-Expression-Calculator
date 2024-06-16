#include "Calculator.hpp"

using namespace std;

#define ln "\n"                                                                          // new input
#define dn "Danial Mobini (40130023)"                                                    // developer name
#define sep "------------------------------------------------------------------------\n" // seperator

void Calculator::first()
{
    cout << "Simple Command input Expression Calculator\n"
         << "Version 1.1\n"
         << "Developer: " << dn << ln
         << sep << "? ";
}

void Calculator::start()
{
    try
    {
        if (cal(cin))
            start();
    }
    catch (const exception &e)
    {
        cout << e.what() << ln;
        start();
    }
}

bool Calculator::cal(istream &myStream, string Prefix)
{
    string input;
    myStream >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (!input.empty())
    {
        if (input == "variables")
        {
            cout << "ans = " << var.size() << " variables\n"
                 << "{\n";
            for (auto &&i : this->var)
            {
                cout << i.first << '=' << i.second << ln;
            }
            cout << "}\n"
                 << sep << Prefix;
        }
        else if (input == "clear")
        {
            cout << "ans =\n"
                 << "{\n"
                 << var.size() << " variables deleted\n"
                 << "}\n"
                 << sep << Prefix;
            var.clear();
        }
        else if (input == "save")
        {
            ofstream file("variables.dat");
            if (file.is_open())
            {
                for (const auto &v : var)
                {
                    file << v.first << ln << v.second << ln;
                }
                file.close();

                cout << "ans = " << var.size() << " variables\n"
                     << "{\n"
                     << "done\n"
                     << "}\n"
                     << sep << Prefix;
            }
            else
            {
                cout << "ans = "
                     << "{\n"
                     << "Error: Unable to open file\n"
                     << "}\n"
                     << sep << Prefix;
            }
        }
        else if (input == "load")
        {
            ifstream file("variables.dat");
            if (file.is_open())
            {
                var.clear();
                string name, value;
                while (getline(file, name))
                {
                    getline(file, value);
                    var.insert({name, stod(value)});
                }
                file.close();

                cout << "ans = " << var.size() << " variables\n"
                     << "{\n";
                for (auto &&i : var)
                {
                    cout << i.first << '=' << i.second << ln;
                }
                cout << "}\n"
                     << sep << Prefix;
            }
            else
            {
                cout << "ans = "
                     << "{\n"
                     << "Error: Unable to open file\n"
                     << "}\n"
                     << sep << Prefix;
            }
        }
        else if (input == "about")
        {
            cout << "ans =\n"
                 << "{\n"
                 << "Simple Command input Expression Calculator\n"
                 << "Version 1.1\n"
                 << "Developer: " << dn << ln
                 << "}\n"
                 << sep << Prefix;
        }
        else if (input == "exit")
        {
            return false;
        }
        else if (input.contains("run"))
        {
            string file_name;
            myStream >> file_name;
            run(file_name);
        }
        else
        {
            string no_s_str;

            for (char c : input)
            {
                if (c != ' ')
                {
                    no_s_str += c;
                }
            }

            pair<double, string> result;
            if (no_s_str.contains('='))
            {
                size_t pos = no_s_str.find('=');
                string str = no_s_str.substr(0, pos);
                no_s_str = no_s_str.erase(0, pos + 1);

                if (no_s_str.contains('+') || no_s_str.contains('-') ||
                    no_s_str.contains('*') || no_s_str.contains('/'))
                {
                    result = calculateExpression(no_s_str, input);
                    if (result.second != "null")
                    {
                        cout << "ans =\n"
                             << "{\n"
                             << result.second << ln
                             << "}\n"
                             << sep << Prefix;
                    }
                    else
                    {
                        if (var.contains(str))
                        {
                            var[str] = calculateExpression(no_s_str, input).first;
                        }
                        else
                        {
                            var.insert({str, calculateExpression(no_s_str, input).first});
                        }

                        cout << "ans =\n"
                             << "{\n"
                             << str << "=" << var[str] << ln
                             << "}\n"
                             << sep << Prefix;
                    }
                }
                else
                {
                    if (isNumber(no_s_str))
                    {
                        var.insert({str, stod(no_s_str)});
                        cout << "ans =\n"
                             << "{\n"
                             << str << "=" << var[str] << ln
                             << "}\n"
                             << sep << Prefix;
                    }
                    else
                    {
                        if (var.find(no_s_str) != var.end())
                        {
                            var.insert({str, var[no_s_str]});
                            cout << "ans =\n"
                                 << "{\n"
                                 << str << "=" << var[str] << ln
                                 << "}\n"
                                 << sep << Prefix;
                        }
                        else
                        {
                            cout << "ans =\n"
                                 << "{\n"
                                 << "Error: Undefined variable " << no_s_str << ln
                                 << "}\n"
                                 << sep << Prefix;
                        }
                    }
                }
            }
            else if (no_s_str.contains('+') || no_s_str.contains('-') ||
                     no_s_str.contains('*') || no_s_str.contains('/'))
            {
                result = calculateExpression(no_s_str, input);
                if (result.second != "null")
                {
                    cout << "ans =\n"
                         << "{\n"
                         << result.second << ln
                         << "}\n"
                         << sep << Prefix;
                }
                else
                {
                    cout << "ans =\n"
                         << "{\n"
                         << calculateExpression(no_s_str, input).first << ln
                         << "}\n"
                         << sep << Prefix;
                }
            }
            else
            {
                cout << "ans =\n"
                     << "{\n"
                     << "Error: Invalid command " << input << ln
                     << "}\n"
                     << sep << Prefix;
            }
        }
        return true;
    }
    return false;
}

// ∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧
size_t find_operator_after(size_t &pos, string &str)
{
    size_t i;
    for (i = pos + 1; i < str.size(); ++i)
    {
        if (str.at(i) == '*' || str.at(i) == '/' || str.at(i) == '+' || str.at(i) == '-')
        {
            break;
        }
    }
    return i;
}

size_t find_operator_befor(size_t &pos, string str)
{
    size_t i;
    for (i = pos - 1; i > 0; --i)
    {
        if (str.at(i) == '*' || str.at(i) == '/' || str.at(i) == '+' || str.at(i) == '-')
        {
            break;
        }
    }
    return i;
}

bool operanding(string &expression, string &operand1, string &operand2, char &myOperator,
                size_t &befor_pos)
{
    if (expression.contains('*') || expression.contains('/'))
    {
        if (expression.contains('*') && expression.contains('/') && expression.find('*') < expression.find('/'))
        {
            myOperator = '*';
        }
        else if (expression.contains('*') && expression.contains('/'))
        {
            myOperator = '/';
        }
        else if (expression.contains('*'))
        {
            myOperator = '*';
        }
        else
        {
            myOperator = '/';
        }
    }
    else if (expression.contains('+') || expression.contains('-'))
    {
        if (expression.contains('+') && expression.contains('-') && expression.find('+') < expression.find('-'))
        {
            myOperator = '+';
        }
        else if (expression.contains('+') && expression.contains('-'))
        {
            myOperator = '-';
        }
        else if (expression.contains('+'))
        {
            myOperator = '+';
        }
        else
        {
            myOperator = '-';
        }
    }
    else
    {
        return false;
    }
    size_t pos = expression.find(myOperator), after_pos = find_operator_after(pos, expression);
    befor_pos = find_operator_befor(pos, expression);

    operand1 = expression.substr(befor_pos, pos);
    operand2.clear();
    for (size_t i = pos + 1; i < after_pos; i++)
    {
        operand2 += expression.at(i);
    }

    expression.erase(befor_pos, after_pos);

    return true;
}

pair<double, string> Calculator::calculateExpression(string &expression, string input)
{
    pair<double, string> result;
    if (expression.contains("++") || expression.contains("--") ||
        expression.contains("**") || expression.contains("//"))
    {
        result = {0, "Error: Invalid Expression " + input};
    }
    else
    {
        char myOperator;
        string operand1, operand2;
        size_t before_pos;
        while (operanding(expression, operand1, operand2, myOperator, before_pos))
        {
            result = calculateSimpleExpression(myOperator, operand1, operand2);
            if (result.second != "null")
                return result;
            expression.insert(before_pos, to_string(result.first));
        }
        result.first = stod(expression);
    }
    return result;
}
// ∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨
//-------------------------------------------------------------------------------------------
// ∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧∧
bool isNumber(const std::string &str)
{
    bool flag = true;
    for (char c : str)
    {
        if (isdigit(c) == false && c != '.')
        {
            flag = false;
            break;
        }
    }
    return flag;
}

optional<double> operander(string &operand, map<string, double> &var)
{
    double o;
    if (isNumber(operand))
    {
        o = stod(operand);
    }
    else
    {
        if (var.find(operand) != var.end())
        {
            o = var[operand];
        }
        else
            return nullopt;
    }
    return o;
}

pair<double, string> Calculator::calculateSimpleExpression(char &myOperator, string &operand1, string &operand2)
{
    double o1, o2, result;
    auto res = operander(operand1, var);
    if (res != nullopt)
        o1 = res.value();
    else
        return {0, "Error: Invalid variable name " + operand1};

    res = operander(operand2, var);
    if (res != nullopt)
        o2 = res.value();
    else
        return {0, "Error: Invalid variable name " + operand2};

    try
    {
        switch (myOperator)
        {
        case '*':
            result = o1 * o2;
            break;
        case '/':
            result = o1 / o2;
            break;
        case '+':
            result = o1 + o2;
            break;
        case '-':
            result = o1 - o2;
            break;
        default:
            return {0, "Operator"};
            break;
        }
    }
    catch (const std::exception &e)
    {
        return {result, e.what()};
    }

    if (result == 1.0f / 0.0f)
    {
        return {0, "Error: Divide by zero"};
    }
    return {result, "null"};
}
// ∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨∨

int countLines(const std::string &filename)
{
    ifstream file(filename);
    int count = 0;
    std::string line;

    while (std::getline(file, line))
    {
        ++count;
    }
    file.close();
    return count;
}

void Calculator::run(string file_name)
{
    int n = countLines(file_name);
    ifstream file(file_name);
    if (file.is_open())
    {
        cout << "ans = " << countLines(file_name) << ln << ln;

        cout << "[1] ";
        for (int i = 1; i < n; i++)
        {
            string input;
            getline(file, input);
            cout << input << ln;
            istringstream iss(input);
            cal(iss, "[" + to_string(i + 1) + "]" + " ");
        }
        string input;
        getline(file, input);
        cout << input << ln;
        istringstream iss(input);
        cal(iss);
        file.close();
    }
    else
    {
        cout << "ans = "
             << "{\n"
             << "Error: Unable to open file\n"
             << "}\n"
             << sep << " ?";
    }
}