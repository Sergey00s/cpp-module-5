#include "Form.h"


Form::Form() : name("default"), gradeToSign(150), gradeToExecute(150)
{
    this->isSigned = false;
    std::cout << "Form " << this->name << " has been created" << std::endl;
}


Form::Form(const Form &cpy) : name(cpy.name), gradeToSign(cpy.gradeToSign), gradeToExecute(cpy.gradeToExecute)
{
    this->isSigned = cpy.isSigned;
    std::cout << "Form " << this->name << " has been created" << std::endl;
}

Form::Form(const std::string name, const short gradeToSign, const short gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = false;
    std::cout << "Form " << this->name << " has been created" << std::endl;
}

Form &Form::operator=(Form &cpy)
{
    this->isSigned = cpy.isSigned;
    return *this;
}


void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->gradeToSign)
    {
        this->isSigned = true;
        std::cout << obj.getName() << " signed " << this->name << std::endl;
    }
    else
    {
        throw Form::FormNotSignedException();
    }
}

void Form::signForm(Bureaucrat &obj)
{
    if (this->isSigned)
    {
        std::cout << this->name << " is already signed" << std::endl;
    }
    else
    {
        try
        {
            this->beSigned(obj);
        }
        catch(const std::exception& e)
        {
            std::cerr << obj.getName() <<" couldn't sign " << this->name + " because " << e.what() << '\n';
        }
    }
}


Form::~Form()
{
    std::cout << "Form " << this->name << " has been destroyed" << std::endl;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

short Form::getGradeToSign() const
{
    return this->gradeToSign;
}

short Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}


std::ostream &operator<<(std::ostream &out, Form &cpy)
{
    out << "Name : " << cpy.getName() << std::endl;
    out << "is signed : " << cpy.getIsSigned() << std::endl;
    out << "grade to sign : " << cpy.getGradeToSign() << std::endl;
    out << "grade to execute : " << cpy.getGradeToExecute() << std::endl;
    return out;
}

