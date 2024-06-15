#include "Calculator.hpp"

using namespace std;

#define ln "\n"                                                                            // new input
#define dn "Danial Mobini (40130023)"                                                      // developer name
#define sep "------------------------------------------------------------------------\n? " // seperator

// ۷- برنامه نسبت به حروف کوچک و بزرگ حساس است.
// خطاهاي موجود در هر عبارت باید توسط برنامه اعلام شود. به عنوان نمونه:
// (Error: Divide by zero) خطاي تقسیم بر صفر (a
// (Error: Undefined variable ‘x’) خطاي عدم تعریف یک متغیر (b
// Error: Invalid variable name ‘x خطاي عدم اعتبار نام یک متغیر (’ 12 (c
//         ۹- مشخصات برنامه تحویلی به زبان
// برنامه تحویل گرفته می شود. exe فایل هاي پروژه برنامه به همراه فایل (a
// فرمت خروجی برنامه باید دقیقا مشابه نمونه نشان داده شده باشد. (b
// برنامه به صورت ماژولار نوشته شود . (c
// براي نامگذاري متغیرها و توابع، اسامی با معنا و قواعد نام گذاري رعایت شود (d
// • متغیرهاي محلی با حرف کوچک آغاز می شوند
// • اسامی توابع با حرف بزرگ
// • اگر یک اسم از چند کلمه تشکیل شده بود، حرف اول هر کلمه بزرگ و مابقی حروف کوچک باشد.

// اگر عبارت ورودی یک عبارت ریاضی باشد، برنامه باید مقدار آن را محاسبه کرده و نتیجه را چاپ کند.

void Calculator::start()
{
    cout << "Simple Command input Expression Calculator\n"
         << "Version 1.1\n"
         << "Developer: " << dn << ln
         << sep;
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
        // اگر عبارت ورودی یک عبارت ریاضی باشد، برنامه باید مقدار آن را محاسبه کرده و نتیجه را چاپ کند.
        // z=3∗x−2∗y
        if (input.contains('='))
        {
            string str = input.substr(0, input.find('='));
            var.push_back(str);
            cout << str << ln;
        }
        else if (input.contains('+'))
        {
            cout << "a\n";
        }
        else if (input.contains('-'))
        {
            cout << "a\n";
        }
        else if (input.contains('/'))
        {
            cout << "a\n";
        }
        else if (input.contains('*'))
        {
            cout << "a\n";
        }
        else
        {
            cout << "Error: Invalid command " << input;
        }
    }
    return true;
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

void Calculator::variables()
{
    // منجر به چاپ لیست متغیرهاي تعریف شده به همراه ارزش آنها می شود
}

void Calculator::clear()
{
    //  کلیه متغیرها را حذف می کن . د
}

void Calculator::save()
{
    /*
    کلیه متغیرها را در یک فایل با نام
    variables.dat
    پوشه محل اجراي برنامه ذخیره می کند
    */
}

void Calculator::load()
{
    /*
    کلیه متغیرهاي ذخیره شده در فایل
    variables.dat
    در پوشه محل اجراي برنامه را لود میکند.
    • کلیه متغیرهاي فعلی پیش از لود شدن حذف می شوند.
    */
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
    /*
     عنوان پارامتر مسیر یک فایل متشکل از دستورات را دریافت و هر یک از آنها را به ترتیب اجرا می کند
    • هر دستور در یک خط فایل قرار گرفته است
    • اجراي هر دستور مشابه تایپ و اجراي دستی آن است
    run c:\project\a.txt
     */
    ifstream file(file_name);
    if (file.is_open())
    {
        string input;
        while (file >> input)
        {
            cout << input << '\n';
            // fun(input);
        }
        file.close();
    }
    else
    {
        cout << "(Error: Unable to open file";
    }
}