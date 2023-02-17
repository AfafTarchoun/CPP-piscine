/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:09:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Aform.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target("Target")
{
    std::cout << "PresidentialPardonForm Default Constructor"<<std::endl;
    if(this->getGradeToSign() > 25 || this->getGradeToExecute() > 5)
        throw(GradeTooLowException());
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, const int sign_grade, const int execute_grade) : AForm(name, sign_grade, execute_grade)
{
    std::cout << "PresidentialPardonForm Paramitrized Constructor"<<std::endl;
    if(this->getGradeToSign() > 25 || this->getGradeToExecute() > 5)
        throw(GradeTooLowException());
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target)
{
    if(this->getGradeToSign() > 25 || this->getGradeToExecute() > 5)
        throw(GradeTooLowException());
    std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Deastuctor"<<std::endl;
}

void    PresidentialPardonForm::setTarget(std::string T)
{
    this->target = T;
}

std::string PresidentialPardonForm::getTarget(void) const 
{
    return (this->target);
}