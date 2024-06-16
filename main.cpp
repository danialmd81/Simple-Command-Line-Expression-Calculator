#include "Calculator.hpp"

int main()
{
    try
    {
        Calculator cal;
        cal.first();
        cal.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}