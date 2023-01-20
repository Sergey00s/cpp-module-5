#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"


class Form
{
    private:
        const std::string name;
        bool isSigned;
        const short gradeToSign;
        const short gradeToExecute;
    private:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is too low";
                }
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form is not signed";
                }
        };

    public:
        Form(void);
        Form(const Form &cpy);
        Form(const std::string name, const short gradeToSign, const short gradeToExecute);
        Form &operator=(Form &cpy);
        std::string getName() const;
        bool getIsSigned() const;
        short getGradeToSign() const;
        short getGradeToExecute() const;
        ~Form();
        void beSigned(Bureaucrat &obj);
        void signForm(Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &out, Form &cpy);


#endif