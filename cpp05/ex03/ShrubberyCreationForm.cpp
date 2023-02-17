/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:12:32 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 22:42:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Aform.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : target("Target")
{
    std::cout << "ShrubberyCreationForm Default Constructor" <<std::endl;
    if(this->getGradeToSign() > 145 || this->getGradeToExecute() > 137)
        throw(GradeTooLowException());
    drawTree(this->target);
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, const int sign_grade, const int execute_grade) : AForm(name, sign_grade, execute_grade)
{
    this->target = "Creation";
    std::cout << "ShrubberyCreationForm Paramitrized Constructor"<<std::endl;
    if(this->getGradeToSign() > 145 || this->getGradeToExecute() > 137)
        throw(GradeTooLowException());
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"<<std::endl;
    drawTree(this->target);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target)
{
    if(this->getGradeToSign() > 145 || this->getGradeToExecute() > 137)
        throw(GradeTooLowException());
    drawTree(this->target);
    // std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox\n";
}

void ShrubberyCreationForm::drawTree(std::string target)
{
    std::cout << this->target << std::endl;
    std::ofstream file (target + "_Shrubbery");
    file << "              * " << std::endl;
    file << "             (|) " << std::endl;
    file << "            ( | ) " << std::endl;
    file << "           (  |  ) " << std::endl;
    file << "          (   |   ) " << std::endl;
    file << "         *    *    * " << std::endl;
    file << "        (|)  (|)  (|) " << std::endl;
    file << "       ( | )( | )( | ) " << std::endl;
    file << "      (  | () | () |  ) " << std::endl;
    file << "     *   ** * ** * *   * " << std::endl;
    file << "    (|)  |   (|)   |  (|) " << std::endl;
    file << "   ( | ) |  ( | )  | ( | ) " << std::endl;
    file << "  (  |  )| (  |  ) |(  |  ) " << std::endl;
    file << "  *   *   *   *   *   *   * " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Deastuctor" << std::endl;
}

void    ShrubberyCreationForm::setTarget(std::string T)
{
    this->target = T;
}

std::string ShrubberyCreationForm::getTarget(void) const 
{ 
    return (this->target);
}
