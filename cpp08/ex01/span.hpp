/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:03 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:42:03 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

class Span {
public:
    Span(unsigned int n) : _n(n) {}

    void addNumber(int num) {
        if (_data.size() == _n) {
            throw std::length_error("Span is already full.");
        }
        _data.push_back(num);
    }

    void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
        size_t n = std::distance(begin, end);
        if (_data.size() + n > _n) {
            throw std::length_error("Not enough space in Span to add range.");
        }
        _data.insert(_data.end(), begin, end);
    }

    int shortestSpan() const {
        if (_data.size() < 2) {
            throw std::length_error("Span has less than 2 numbers.");
        }
        std::vector<int> sortedData = _data;
        std::sort(sortedData.begin(), sortedData.end());
        std::adjacent_difference(sortedData.begin(), sortedData.end(), sortedData.begin());
        return *std::min_element(sortedData.begin() + 1, sortedData.end());
    }

    int longestSpan() const {
        if (_data.size() < 2) {
            throw std::length_error("Span has less than 2 numbers.");
        }
        return *std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end());
    }

private:
    unsigned int _n;
    std::vector<int> _data;
};

#endif