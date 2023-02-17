/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:24 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:17:52 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        // RobotomyRequestForm f("office",  25, 5);
        ShrubberyCreationForm f("tree", 25, 6);
        Bureaucrat b(25, "bureaucrat");
        // std::cout << f.getGradeToExecute() << std::endl;
        b.signForm(f);
        // f.execute(b);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::string error_msg)
    {
        std::cerr << error_msg << std::endl;
    }
    return 0;
}