/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/05 21:32:47 by atarchou         ###   ########.fr       */
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
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream	input(argv[1]);
	std::string		line;
	if (input.fail())
	{
		std::cerr << "Error: could not read input file." << std::endl;
		return (1);
	}
	std::map<std::string, float> data = dataToMap();
	// output(data);
	BitcoinExchange bit(data);
	while (std::getline(input, line))
		bit.exchange_res(line);
}
