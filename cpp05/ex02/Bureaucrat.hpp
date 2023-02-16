#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "form.hpp"
class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string name);
    Bureaucrat(int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(int grade,const std::string name);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void    signForm(Form & F);
    void    executeForm(Form const & form);
    class   GradeTooHighException : public std::exception
    {
        public :
            const char * what() const throw ();
    };
    class   GradeTooLowException : public std::exception
    {
        public :
            const char * what() const throw ();
    };
private:
    const std::string name;
    int grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif