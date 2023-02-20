/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutated.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:14 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/20 02:22:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTATED_TPP
#define MUTATED_TPP
#include "Mutated.hpp"

template <class T> MutantStack<T>::MutantStack()
{
    std::cout << "Mutated constructor called" << std::endl;
}

template <class T> MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template <class T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &)
{
    return *this;
}

template <class T> MutantStack<T>::~MutantStack()
{
    std::cout << "Mutated destructor called" << std::endl;
}

#endif
