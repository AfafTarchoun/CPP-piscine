/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:32:46 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/26 16:50:03 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <sstream>

int main(int argc, char* argv[])
{
    // Check that at least one argument (the program name) was provided
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " integer_sequence" << std::endl;
        return 1;
    }

    // Initialize the vector with the input sequence
    std::vector<int> v;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream ss(argv[i]);
        int n;
        if (!(ss >> n) || n < 1)
        {
            std::cerr << "Error: " << argv[i] << " is not a positive integer." << std::endl;
            return 1;
        }
        v.push_back(n);
    }

    // Display the unsorted sequence
    std::cout << "Before:";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Sort the sequence using merge-insert sort with list
    std::list<int> l;
    std::clock_t start = std::clock();
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        std::list<int>::iterator ins_pos = std::upper_bound(l.begin(), l.end(), *it);
        l.insert(ins_pos, *it);
    }
    std::clock_t end = std::clock();

    // Display the sorted sequence
    std::cout << "After:";
    for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Display the time used by the algorithm with list
    std::cout << "Time to process a range of " << v.size() << " elements with list: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    // Sort the sequence using merge-insert sort with vector
    std::vector<int> w;
    start = std::clock();
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        std::vector<int>::iterator ins_pos = std::upper_bound(w.begin(), w.end(), *it);
        w.insert(ins_pos, *it);
    }
    end = std::clock();

    // Display the time used by the algorithm with vector
    std::cout << "Time to process a range of " << v.size() << " elements with vector: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << " s" << std::endl;

    return 0;
}
