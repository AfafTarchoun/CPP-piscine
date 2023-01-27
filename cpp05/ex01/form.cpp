#include "form.hpp"


void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > grade_to_sign)
        throw Form::GradeTooLowException();
    else
        signed = true;
}