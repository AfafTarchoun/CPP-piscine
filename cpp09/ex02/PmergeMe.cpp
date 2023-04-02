/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:31:22 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/02 02:33:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sort_and_print(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Error: Please provide a list of positive integers.\n";
        return;
    }

    std::vector<int>    v;
    std::deque<int>     d;
    for(int i = 1; i < argc; ++i)
    {
        int val = std::atoi(argv[i]);
        if(val <= 0)
        {
            std::cout << "Error: Invalid input " << argv[i] << "\n";
            return;
        }
        v.push_back(val);
        d.push_back(val);
    }

    // Print unsorted sequence
    std::cout << "Before:";
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n";

    // Sort using vector
    std::clock_t start_time_v = std::clock();
    std::sort(v.begin(), v.end());
    std::clock_t end_time_v = std::clock();
    double duration_v = (end_time_v - start_time_v) / (double) CLOCKS_PER_SEC * 1e6;

    // Sort using deque
    std::clock_t start_time_d = std::clock();
    std::sort(d.begin(), d.end());
    std::clock_t end_time_d = std::clock();
    double duration_d = (end_time_d - start_time_d) / (double) CLOCKS_PER_SEC * 1e6;

    // Print sorted sequence and timings
    std::cout << "After:";
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << " " << *it;
    std::cout << "\n";

    std::cout << "Time to process a range of " << v.size() << " elements with std::sort and vector: " << duration_v << " us\n";
    std::cout << "Time to process a range of " << d.size() << " elements with std::sort and deque: " << duration_d << " us\n";
}
