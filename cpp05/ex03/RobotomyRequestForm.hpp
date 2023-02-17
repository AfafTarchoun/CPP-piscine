/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:12:25 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 18:12:25 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "Aform.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
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