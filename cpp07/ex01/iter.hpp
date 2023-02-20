/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:03:57 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/19 01:11:27 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T* arr, int len, void f(T const &arr))
{
    for (int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}

#endif