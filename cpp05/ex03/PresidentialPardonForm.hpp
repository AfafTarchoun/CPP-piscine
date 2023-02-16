#ifndef PRESIDENTIAL_FORM_HPP
# define PRESIDENTIAL_FORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
    private :
        std::string target;
    public : 
        PresidentialPardonForm();
PresidentialPardonForm(std::string name, const int sign_grade, const int execute_grade);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        std::string getTarget(void) const ;
        void    setTarget(std::string T);
        
};

#endif