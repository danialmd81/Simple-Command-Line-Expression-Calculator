#include "Calculator.hpp"

int main()
{
    try
    {
        Calculator cal;
        cal.start();
        cal.cal();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}