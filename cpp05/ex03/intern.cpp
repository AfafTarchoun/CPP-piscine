/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:45:25 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 21:45:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Aform.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constuctor" << std::endl;
}

Intern::Intern(Intern const & Intern)
{
    *this = Intern;
    std::cout << "Intern Copy Constuctor"<< std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor"<< std::endl;
}

AForm* Intern::makeForm(std::string nameForm, std::string target)
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
            std::cout << "intern creates RobotomyRequestForm"<< std::endl;
            return (new RobotomyRequestForm());
        }
        case (1) :
        {
            std::cout << target << " creates ShrubberyCreationForm"<< std::endl;
            return (new ShrubberyCreationForm());
        }
        case(2) :
        {
            std::cout << "intern creates PresidentialPardonForm"<< std::endl;
            return (new PresidentialPardonForm());
        }
    }
    throw(errorForm());
}