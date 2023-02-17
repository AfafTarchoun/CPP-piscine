/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:45:19 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/16 21:45:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include "Aform.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & Intern);
        ~Intern();
        AForm *makeForm(std::string nameForm, std::string target);
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