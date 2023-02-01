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

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > grade_to_sign)
        throw Form::GradeTooLowException();
    else
        signed = true;
}