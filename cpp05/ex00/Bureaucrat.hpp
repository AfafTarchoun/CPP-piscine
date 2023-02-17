#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

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
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        class   GradeTooHighException : public std::exception
        {
            public :
                const char * what() const throw ()
            {
                return "Error : Grade is High\n";
            }
        };
        class   GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw ()
            {
                return "Error : Grade is Low\n";
            }
        };
    private:
        const   std::string name;
        int     grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif