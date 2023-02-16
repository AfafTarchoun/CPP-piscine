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
// int main()
// {
//     try {
//         Bureaucrat b("John", 0);
//     }
//     catch (Bureaucrat::GradeTooHighException &e)
//     {
//         // handle exception
//     }
//     return 0;
// }
int main()
{
    try
    {
        Bureaucrat b(146,"john");

        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
       
        Bureaucrat c;
        c = b;

        std::cout << c.getName() << std::endl;
        std::cout << c.getGrade() << std::endl;
        std::cout << b.getGrade() << '\n';
        std::cout << b;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}