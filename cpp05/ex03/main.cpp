/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:22:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "intern.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* rrf;
    try
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    }
    catch(std::exception & e)
    {

        std::cerr << e.what() << std::endl;
    }
    return 0;
}