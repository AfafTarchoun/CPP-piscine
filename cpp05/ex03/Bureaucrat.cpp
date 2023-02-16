/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:17 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:40:17 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat")
{
    std::cout << "Bureaucrat Default constructor called\n";
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name)
{
    std::cout << "Bureaucrat Paramitrized Constructor Called\n";
    this->grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : name("dizzy")
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << "Bureaucrat Int Constuctor Called\n";
    this->grade = grade;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    *this = other;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
    this->grade = other.grade;
    return *this;
 }

Bureaucrat::~Bureaucrat(){
    std::cout<<"destructor called"<<std::endl;
};

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void   Bureaucrat::signForm(Form & F)
{
   try
   {
        F.beSigned(*this);
        std::cout << this->name << " Signed " << F.getName() << std::endl;
    }
    catch(const std::exception& e)
   {
        std::cerr << this->name << "Couldn't Sign due to ";
        std::cerr << e.what() << '\n';
   }    
}

void    Bureaucrat::executeForm(Form const & form)
{
    if (grade  < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << this->getName() << " executed " << form.getName() << '\n';
}