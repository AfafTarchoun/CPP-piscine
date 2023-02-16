/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:31 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"

Form::Form() : name("john"), is_signed(false), grade_to_sign(149), grade_to_execute(2)
{
    std::cout << "Form Default constructor Called\n";
}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    this->is_signed = false;
    std::cout << "Form Paramitrized Constructor Called\n";
}

Form::Form(Form & other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    *this = other;
    std::cout << "Form Copy Constructor Called\n";
}


Form & Form::operator=(Form const & other)
{
    std::cout << "Form Copy Assignment Overload Called\n";
    this->is_signed = other.is_signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Form Distructor Called\n";
}

void    Form::beSigned(Bureaucrat B)
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

int Form::getGradeToExecute(void)
{
    return (this->grade_to_execute);
}

int Form::getGradeToSign(void)
{
    return (this->grade_to_sign);
}

std::string Form::getName(void)
{
    return (this->name);
}

void    Form::execute(Bureaucrat const & executor) const 
{
    if(executor.getGrade() < 1)
        throw(GradeTooHighException());
    else if(executor.getGrade() > 150)
        throw(GradeTooLowException());
    if (is_signed)
        std::cout << "Form : " << this->name << " executed " << executor.getName() << '\n';
    else
        std::cout << "Form : The form is not signed\n";
}