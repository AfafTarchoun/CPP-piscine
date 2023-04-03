/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/03 00:47:15 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void	output(std::map<std::string, float> map)
// {
// 	for (std::map<std::string, float>::iterator itr = map.begin(); itr != map.end(); ++itr)
// 	{
// 		std::cout << "key = " << itr->first << ", val = " << itr->second << std::endl;;
// 	}
// }

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);
	std::string		line;
	if (input.fail())
	{
		std::cout << "Error: could not read input file." << std::endl;
		return (1);
	}
	std::map<std::string, float> data = dataToMap();
	// output(data);
	BitcoinExchange be(data);
	while (std::getline(input, line))
		be.exchange_res(line);
}
// int main (int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         std::cout << "Error: no input files provided." << std::endl;
//         return (1);
//     }
//     std::map<std::string, float> data = dataToMap();
//     // output(data);
//     BitcoinExchange bit(data);
//     for (int i = 1; i < argc; i++)
//     {
//         std::ifstream input(argv[i]);
//         if (input.fail())
//         {
//             std::cout << "Error: could not read input file " << argv[i] << "." << std::endl;
//             return (1);
//         }
//         std::string line;
//         while (std::getline(input, line))
//             bit.exchange_res(line);
//     }
//     return (0);
// }
