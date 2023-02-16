
#include "form.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("Target")
{
    // int random = time(NULL) % 2;
    // std::cout << random << std::endl;
    std::cout << "RobotomyRequestForm Default Constructor Called\n";
    if(this->getSGrade() > 72 || this->getEGrade() > 45)
        throw(GradeTooLowException());
    std::cout << getTarget() << this->target << " has been robotomized successfully 50 percent the time.\n";
    int random;
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time.\n";
    else
        std::cout << getTarget() << this->target << " the robotomy failed.\n";
}
RobotomyRequestForm::RobotomyRequestForm(std::string name, const int sign_grade, const int execute_grade) : Form(name, sign_grade, execute_grade)
{
    target = "EEEEE";

    std::cout << "RobotomyRequestForm Paramitrized Constructor Called\n";
    if(this->getSGrade() > 72 || this->getEGrade() > 45)
        throw(GradeTooLowException());
    int random;
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time.\n";
    else
        std::cout << getTarget() << this->target << " the robotomy failed.\n";

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target)
{
    if(this->getSGrade() > 72 || this->getEGrade() > 45)
        throw(GradeTooLowException());
    int random;
    srand(time(NULL));
    random = rand() % 100;
    if(random > 50)
        std::cout << this->target << " has been robotomized successfully 50 percent the time.\n";
    else
        std::cout << getTarget() << this->target << " the robotomy failed.\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Deastuctor Called\n";
}

void    RobotomyRequestForm::setTarget(std::string T)
{
    this->target = T;
}

std::string RobotomyRequestForm::getTarget(void) const 
{
    return (this->target);
}
