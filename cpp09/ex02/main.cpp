/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:31:16 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/05 21:41:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Error: Please provide a list of positive integers.\n";
        return;
    }
    sort_and_print(argc, argv);
    return (0);
}