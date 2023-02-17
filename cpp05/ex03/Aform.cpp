/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 22:45:42 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"

AForm::AForm() : name("john"), is_signed(false), grade_to_sign(50), grade_to_execute(50)
{
    std::cout << "Form Default constructor" << std::endl;
}

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    this->is_signed = false;
    std::cout << "Form Paramitrized Constructor" << std::endl;
}

AForm::AForm(AForm & other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    *this = other;
    std::cout << "Form Copy Constructor" << std::endl;
}


AForm & AForm::operator=(AForm const & other)
{
    std::cout << "Form Copy Assignment Overload" << std::endl;
    this->is_signed = other.is_signed;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form Destructor"<< std::endl;
}

void    AForm::beSigned(Bureaucrat B)
{
    if(grade_to_sign < 1 || grade_to_execute < 1)
        throw(GradeTooHighException());
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw(GradeTooLowException());
    if(B.getGrade() < 1)
        throw(GradeTooHighException());
    else if (B.getGrade() > 150)
        throw(GradeTooLowException());
    this->is_signed = true;
}

int AForm::getGradeToExecute(void)
{
    return (this->grade_to_execute);
}

int AForm::getGradeToSign(void)
{
    return (this->grade_to_sign);
}

std::string AForm::getName(void)
{
    return (this->name);
}

void    AForm::execute(Bureaucrat const & executor) const 
{
    if(executor.getGrade() < 1)
        throw(GradeTooHighException());
    else if(executor.getGrade() > 150)
        throw(GradeTooLowException());
    if (is_signed)
        std::cout << "Form : " << this->name << " executed " << executor.getName() <<std::endl;
    else
        std::cout << "Form : The form is not signed"<<std::endl;
}