#include "Form.h"

int main(int argc, char const *argv[])
{
    Bureaucrat b1("hello", 50);
    Form frm("test", 60, 60);
    b1.decrementGrade();
    frm.beSigned(b1);
    std::cout << frm;
    return 0;
}
