/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:28:17 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/13 18:29:37 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include<string>

class Brain
{
    protected :
        std::string ideas[100];
    public :
        Brain();
        Brain(std::string ideas);
        Brain(Brain & B);
        Brain & operator=(Brain const & B);
        ~Brain();
        std::string    getIdeas(int n) const ;
        void            setIdeas(std::string idea, int n);
};

 #endif