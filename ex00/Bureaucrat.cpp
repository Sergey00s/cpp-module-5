#include "Bureaucrat.hpp"

std::string Bureaucrat::getName()
{
    return this->name;
}

short Bureaucrat::getGrade()
{
    return this->grade;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &cpy)
{
    out << cpy.getName() << ", bureaucrat grade " << cpy.getGrade();
    return out;
}

Bureaucrat::Bureaucrat(short grade) : name("default")
{
    std::cout << "Bureaucrat " << this->name << " has been created" << std::endl;
    this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " has been destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name)
{
    std::cout << "Bureaucrat " << this->name << " has been created" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, short grade) : name(name)
{
    std::cout << "Bureaucrat " << this->name << " has been created" << std::endl;
    this->grade = grade;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat() : name("default")
{
    std::cout << "Bureaucrat " << this->name << " has been created" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name)
{
    std::cout << "Bureaucrat " << this->name << " has been created" << std::endl;
    this->setGrade(cpy.grade);
}
 
Bureaucrat &Bureaucrat::operator=(Bureaucrat &cpy)
{
    this->setGrade(cpy.grade);
    return *this;
}

void Bureaucrat::setGrade(short grade)
{   
    if(grade < 1)
    {
        throw TooHighException(); 
    }
    else if(grade > 150)
    {
        throw TooLowException();
    }
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade()
{
    this->setGrade(this->grade + 1);
}
