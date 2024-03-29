/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:54:21 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:27 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "form.hpp"

class Form;
class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(int grade,const std::string name);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form & F);
        class   GradeTooHighException : public std::exception
        {
            public :
                const char * what() const throw () // <--- This
            {
                return "Error : Grade is High";
            }
        };
        class   GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw () // <--- This
            {
                return "Error : Grade is Low";
            }
        };
    private:
        const std::string name;
        int   grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif