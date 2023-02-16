#include "intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "form.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constuctor Called\n";
}

Intern::Intern(Intern const & I)
{
    *this = I;
    std::cout << "Intern Copy Constuctor Called\n";
}

Intern::~Intern()
{
    std::cout << "Intern Destructor Called\n";
}

Form* Intern::makeForm(std::string nameForm, std::string target)
{
    int i = 0;
    std::string arr[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    while(i < 3)
    {
        if(arr[i] == nameForm)
            break;
        i++;
    }
    switch (i)
    {
        case (0) :
        {
            std::cout << "intern creates RobotomyRequestForm\n";
            return (new RobotomyRequestForm());
        }
        case (1) :
        {
            std::cout << target << " creates ShrubberyCreationForm\n";
            return (new ShrubberyCreationForm());
        }
        case(2) :
        {
            std::cout << "intern creates PresidentialPardonForm\n";
            return (new PresidentialPardonForm());
        }
    }
    throw(errorForm());
}