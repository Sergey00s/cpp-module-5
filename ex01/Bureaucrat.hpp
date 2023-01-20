#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        short grade;
    private:
        class TooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too high";
                }
        };
        class TooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too low";
                }
        };

    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, short grade);
        Bureaucrat(std::string name);
        Bureaucrat(short grade);
        ~Bureaucrat(void);
        void setGrade(short grade);
        void incrementGrade();
        void decrementGrade();
        short getGrade();
        std::string getName();
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(Bureaucrat &cpy);
    
};
 
 std::ostream &operator<<(std::ostream &out, Bureaucrat &cpy);

#endif