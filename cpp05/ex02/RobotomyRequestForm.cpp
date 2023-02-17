/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:11:42 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 23:10:17 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("Target")
{
    int random;

    std::cout << "RobotomyRequestForm Default Constructor"<<std::endl;
    if(this->getGradeToSign() > 72 || this->getGradeToExecute() > 45)
        throw(GradeTooLowException());
    std::cout << getTarget() << this->target << " has been robotomized successfully 50 percent the time."<<std::endl;
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time."<<std::endl;
    else
        std::cout << getTarget() << this->target << " the robotomy failed"<<std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name, const int sign_grade, const int execute_grade) : AForm(name, sign_grade, execute_grade)
{
    int random;
    
    target = "request";
    std::cout << "RobotomyRequestForm Paramitrized Constructor"<<std::endl;
    if(this->getGradeToSign() > 72 || this->getGradeToExecute() > 45)
        throw(GradeTooLowException());
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time."<<std::endl;
    else
        std::cout << getTarget() << this->target << " the robotomy failed."<<std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target)
{
    int random;
    
    if(this->getGradeToSign() > 72 || this->getGradeToExecute() > 45)
        throw(GradeTooLowException());
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time."<<std::endl;
    else
        std::cout << getTarget() << this->target << " the robotomy failed."<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Deastuctor"<<std::endl;
}

void    RobotomyRequestForm::setTarget(std::string T)
{
    this->target = T;
}

std::string RobotomyRequestForm::getTarget(void) const 
{
    return (this->target);
}
