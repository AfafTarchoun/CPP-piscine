/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutated.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:19 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 21:55:46 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATED_HPP
#define MUTATED_HPP
#include <iostream>
#include <stack>

template <class T >
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return std::stack<T>::c.begin();
        }
        iterator end()
        {
            return std::stack<T>::c.end();
        }
        MutantStack();
        MutantStack(const MutantStack &obj);
        MutantStack &operator=(const MutantStack &a);
        ~MutantStack();
};
#include "Mutated.tpp"
#endif