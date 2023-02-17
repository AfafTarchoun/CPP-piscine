/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:07:20 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"

Form::Form() : name("john"), is_signed(false), grade_to_sign(149), grade_to_execute(2)
{
    std::cout << "Form Default constructor" << std::endl;;
}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    this->is_signed = false;
    std::cout << "Form Paramitrized Constructor"<< std::endl;
}

Form::Form(Form & other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    *this = other;
    std::cout << "Form Copy Constructor Called"<< std::endl;
}


Form & Form::operator=(Form const & other)
{
    std::cout << "Form Copy Assignment Overload"<< std::endl;;
    this->is_signed = other.is_signed;
    return *this;
}

Form::~Form()
{
    std::cout << "Form Distructor" << std::endl;;
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

bool Form::getSigned()
{
    return is_signed;
}

std::ostream& operator<<(std::ostream& os, Form &f)
{
    os << "form" << f.getName() << " is ";
    if (f.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << "requires grade of " << f.getGradeToSign() << "to sign and grade of " << f.getGradeToExecute()<< "to execute." << std::endl;
    return os;
}