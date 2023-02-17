/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:12:04 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:06 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_FORM_HPP
# define PRESIDENTIAL_FORM_HPP
#include "Aform.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
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