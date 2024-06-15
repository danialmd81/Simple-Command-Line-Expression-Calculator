#include "Calculator.hpp"

using namespace std;

#define ln "\n"                                                                            // new line
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
    cout << "Simple Command Line Expression Calculator\n"
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
                 << "Simple Command Line Expression Calculator\n"
                 << "Version 1.1\n"
                 << "Developer: " << dn << ln
                 << "}\n"
                 << sep;
        }
        else if (input == "exit")
        {
            return;
        }
        else if (input.contains("run"))
        {
            string file_name;
            file_name = input.substr(4);
            run(file_name);
        }
        else
        {
            // اگر عبارت ورودی یک عبارت ریاضی باشد، برنامه باید مقدار آن را محاسبه کرده و نتیجه را چاپ کند.
        }
        cal();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
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
         << "Simple Command Line Expression Calculator\n"
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
    ifstream file;
    file.open(file_name);
}