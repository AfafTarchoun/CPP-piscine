
#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
#include "form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
    private :
        std::string target;
    public : 
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name, const int sign_grade, const int execute_grade);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        std::string getTarget(void) const ;
        void    setTarget(std::string T);
        void    drawTree(std::string target);
};

#endif