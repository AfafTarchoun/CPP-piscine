/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:03 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/20 02:29:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span & other);
        void addNumber(int num);
        void addRange(std::vector<int> &_data2);
        int shortestSpan() const;
        int longestSpan() const;
        ~Span();
    private:
        unsigned int _n;
        std::vector<int> _data;
};
#endif