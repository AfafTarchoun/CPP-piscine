/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:31:22 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/03 01:44:44 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//merge-insert sort using vector

std::vector<int> insertion_sort(std::vector<int> arr)
{
    for (std::vector<int>::size_type i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
    return arr;
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> result;
    std::vector<int>::size_type i = 0;
    std::vector<int>::size_type j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

std::vector<int> merge_insertion_sort(std::vector<int> arr)
{
    if (arr.size() < 10)
        return insertion_sort(arr);
    else 
    {
        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());
        left = merge_insertion_sort(left);
        right = merge_insertion_sort(right);
        return merge(left, right);
    }
}

//merge-insert sort using Deque
std::deque<int> insertion_sort(std::deque<int> arr)
{
    for (std::deque<int>::size_type i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
    return arr;
}

std::deque<int> merge(std::deque<int> left, std::deque<int> right)
{
    std::deque<int> result;

    while (!left.empty() && !right.empty())
    {
        if (left.front() < right.front())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty())
    {
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

std::deque<int> merge_insertion_sort(std::deque<int> arr)
{
    if (arr.size() < 10)
        return insertion_sort(arr);
    else
    {
        int mid = arr.size() / 2;
        std::deque<int> left(arr.begin(), arr.begin() + mid);
        std::deque<int> right(arr.begin() + mid, arr.end());
        left = merge_insertion_sort(left);
        right = merge_insertion_sort(right);
        return merge(left, right);
    }
}

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
    // std::sort(v.begin(), v.end());
    v = merge_insertion_sort(v);
    std::clock_t end_time_v = std::clock();
    double duration_v = (end_time_v - start_time_v) / (double) CLOCKS_PER_SEC * 1e6;

    // Sort using deque
    std::clock_t start_time_d = std::clock();
    // std::sort(d.begin(), d.end());
    d = merge_insertion_sort(d);
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
