#include "Calculator.hpp"

using namespace std;

#define ln "\n"                                                                            // new input
#define dn "Danial Mobini (40130023)"                                                      // developer name
#define sep "------------------------------------------------------------------------\n? " // seperator

void Calculator::start()
{
    cout << "Simple Command input Expression Calculator\n"
         << "Version 1.1\n"
         << "Developer: " << dn << ln
         << sep;
}

void Calculator::cal()
{
    try
    {
        string input;
        cin >> input;
        if (fun(input))
            cal();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        cal();
    }
}

bool Calculator::fun(string input)
{
    if (input == "variables")
    {
        variables();
    }
    else if (input == "clear")
    {
        clear();
    }
    else if (input == "save")
    {
        save();
    }
    else if (input == "load")
    {
        load();
    }
    else if (input == "about")
    {
        cout << "ans =\n"
             << "{\n"
             << "Simple Command input Expression Calculator\n"
             << "Version 1.1\n"
             << "Developer: " << dn << ln
             << "}\n"
             << sep;
    }
    else if (input == "exit")
    {
        return false;
    }
    else if (input == "run")
    {
        string file_name;
        cin >> file_name;
        run(file_name);
    }
    else
    {
        if (input.contains('='))
        {
            if (input.contains('+') || input.contains('-') || input.contains('*') || input.contains('/'))
            {
                operation(input);
            }
            else
            {
                string str = input.substr(0, input.find('='));

                cout << str << ln;
            }
        }
        else if (input.contains('+') || input.contains('-') || input.contains('*') || input.contains('/'))
        {
            operation(input);
        }
        else
        {
            cout << "Error: Invalid command " << input << ln;
        }
    }
    return true;
}

void Calculator::operation(string str)
{
}

void Calculator::variables()
{
    // منجر به چاپ لیست متغیرهاي تعریف شده به همراه ارزش آنها می شود
    cout << "ans =\n"
         << "{\n";
    for (auto &&i : var)
    {
        cout << i.first << '=' << i.second << ln;
    }
    cout << "}\n"
         << sep;
}

void Calculator::clear()
{
    //  کلیه متغیرها را حذف می کن . د
    cout << "ans =\n"
         << "{\n"
         << var.size() << " variables deleted\n";
    var.clear();
}

void Calculator::save()
{
    /*
    کلیه متغیرها را در یک فایل با نام
    variables.dat
    پوشه محل اجراي برنامه ذخیره می کند
    */
    ofstream file("variables.dat");
    if (file.is_open())
    {
        for (const auto &v : var)
        {
            file << v.first << ln << v.second << ln;
        }
        file.close();
    }
    else
    {
        cout << "(Error: Unable to open file";
    }
}

void Calculator::load()
{
    /*
    کلیه متغیرهاي ذخیره شده در فایل
    variables.dat
    در پوشه محل اجراي برنامه را لود میکند.
    • کلیه متغیرهاي فعلی پیش از لود شدن حذف می شوند.
    */
    ifstream file("variables.dat");
    if (file.is_open())
    {
        var.clear();
        string name;
        int value;
        while (getline(file, name))
        {
            file >> value;
            var.push_back(make_pair(name, value));
        }
        file.close();
    }
    else
    {
        cout << "(Error: Unable to open file";
    }
}

void Calculator::about()
{
    cout << "ans =\n"
         << "{\n"
         << "Simple Command input Expression Calculator\n"
         << "Version 1.1\n"
         << "Developer: " << dn << ln
         << "}\n"
         << sep;
    return;
}

void Calculator::run(string file_name)
{

    ifstream file(file_name);
    if (file.is_open())
    {
        string input;
        while (file >> input)
        {
            fun(input);
        }
        file.close();
    }
    else
    {
        cout << "(Error: Unable to open file";
    }
}