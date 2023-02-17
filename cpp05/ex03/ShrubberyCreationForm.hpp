/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:18:45 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 18:18:45 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
#include "Aform.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
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