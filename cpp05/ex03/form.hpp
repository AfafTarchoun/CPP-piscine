#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form();
        Form(std::string name, const int grade_to_sign, const int grade_to_execute);
        Form(Form& other);
        Form & operator=(Form const & other);
        ~Form();
        std::string getName();
        int getGradeToSign();
        int getGradeToExecute();
        void beSigned(Bureaucrat b);
        void        execute(Bureaucrat const & executor) const ;
        class   GradeTooHighException : public std::exception
        {
            public :
                const char * what() const throw () // <--- This
            {
                return "Error : Grade is High";
            }
        };
        class   GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw () // <--- This
            {
                return "Error : Grade is Low";
            }
        };
};

#endif