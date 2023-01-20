#include "Bureaucrat.hpp"

int main(int argc, char const *argv[])
{
        Bureaucrat b1("hello", 149);
        b1.decrementGrade();
    try
    {
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << b1 << std::endl;
    return 0;
}
