
#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & I);
        ~Intern();
        
        
        Form *makeForm(std::string nameForm, std::string target);
        class errorForm : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return "there was an error while creating the form\n";
                }
        };
};

#endif