#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "variables")
        {
            // منجر به چاپ لیست متغیرهاي تعریف شده به همراه ارزش آنها می شود
        }
        else if (str == "clear")
        {
            //  کلیه متغیرها را حذف می کن . د
        }
        else if (str == "save")
        {
            /*
            کلیه متغیرها را در یک فایل با نام
            variables.dat
            پوشه محل اجراي برنامه ذخیره می کند
            */
        }
        else if (str == "load")
        {
            /*
            کلیه متغیرهاي ذخیره شده در فایل
            variables.dat
            در پوشه محل اجراي برنامه را لود میکند.
            • کلیه متغیرهاي فعلی پیش از لود شدن حذف می شوند.
            */
        }
        else if (str == "about")
        {
            /* درباره برنامه شرحی را در خروجی نشان می ده د */
        }
        else if (str == "exit")
        {
            break;
        }
        else if (str == "run")
        {
            /*
             عنوان پارامتر مسیر یک فایل متشکل از دستورات را دریافت و هر یک از آنها را به ترتیب اجرا می کند
            • هر دستور در یک خط فایل قرار گرفته است
            • اجراي هر دستور مشابه تایپ و اجراي دستی آن است
            run c:\project\a.txt
             */
        }
        // ۷- برنامه نسبت به حروف کوچک و بزرگ حساس است.
        // خطاهاي موجود در هر عبارت باید توسط برنامه اعلام شود. به عنوان نمونه:
        // (Error: Divide by zero) خطاي تقسیم بر صفر (a
        // (Error: Undefined variable ‘x’) خطاي عدم تعریف یک متغیر (b
        // Error: Invalid variable name ‘x خطاي عدم اعتبار نام یک متغیر (’ 12 (c
        else
        {
            /* code */
        }
    }
    return 0;
}