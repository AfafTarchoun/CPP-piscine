/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "intern.hpp"

int main()
{
    Intern someRandomIntern;

    Form* rrf;
    try
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    }
    catch(std::exception & e)
    {

        std::cerr << e.what() << std::endl;
    }
    // catch (std::string error_msg)
    // {
    //     std::cerr << error_msg << std::endl;
    // }
    // system("Leaks coffee_making");
    return 0;
}