/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:17 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:07:53 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat")
{
    std::cout << "Bureaucrat Default constructor"<<std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name) : name(name)
{
    std::cout << "Bureaucrat Paramitrized Constructor"<<std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : name("dizzy")
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << "Bureaucrat Int Constuctor"<<std::endl;
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

void    Bureaucrat::incrementGrade(void)
{

    this->grade -= 1;
    if (grade  < 1)
        throw(Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::decrementGrade(void)
{
    this->grade += 1;
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

void   Bureaucrat::signForm(AForm & F)
{
   try
   {
        F.beSigned(*this);
        std::cout << this->name << " Signed " << F.getName() << std::endl;
    }
    catch(const std::exception& e)
   {
        std::cerr << this->name << "Couldn't Sign because of ";
        std::cerr << e.what() <<std::endl;
   }    
}

void    Bureaucrat::executeForm(AForm & Aform)
{
    if (grade  < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << this->getName() << " executed " << Aform.getName()<<std::endl;
}