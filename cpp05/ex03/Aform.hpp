/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:53 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 20:53:12 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        AForm();
        AForm(std::string name, const int grade_to_sign, const int grade_to_execute);
        AForm(AForm& other);
        AForm& operator=(AForm const & other);
        virtual ~AForm() = 0;
        std::string getName();
        int  getGradeToSign();
        int  getGradeToExecute();
        void beSigned(Bureaucrat b);
        void execute(Bureaucrat const & executor) const ;
        class   GradeTooHighException : public std::exception
        {
            public :
                const char * what() const throw ()
            {
                return "Error : Grade is High";
            }
        };
        class   GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw ()
            {
                return "Error : Grade is Low";
            }
        };
};

#endif