
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
    private :
        std::string target;
    public : 
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name, const int sign_grade, const int execute_grade);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        std::string getTarget(void) const ;
        void    setTarget(std::string T);
        
};

#endif