/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/16 23:20:40 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float>	convertCsvToMap()
{
	std::ifstream dataCsv;
	dataCsv.open("data.csv", std::ifstream::in);
	if (dataCsv.fail()) {
		std::cout << "Error: could not read `data.csv`." << std::endl;
	}
	std::map<std::string, float>	ret;
	std::string line;
	while (std::getline(dataCsv, line))
    {
		if (line == "date,exchange_rate")
			continue;
		size_t comma = line.find(",");
		size_t comma2 = line.find(",", comma + 1);
		if (line.size() < 12 || comma == std::string::npos || comma2 != std::string::npos) {
			std::cout << "Error: invalid `data.csv`." << std::endl;
		}
		std::string key = line.substr(0, comma);
		std::string value = line.substr(comma + 1, line.size() - comma - 1);
		std::istringstream(value) >> ret[key];
	}
	if (ret.size() == 0)
    {
		std::cout << "Error: invalid `data.csv`." << std::endl;
	}
	return ret;
}

void	output(std::map<std::string, float> map) {
	for(std::map<std::string, float>::iterator itr = map.begin();
			itr != map.end(); ++itr) {
		std::cout << "key = " << itr->first
							<< ", val = " << itr->second << std::endl;;
	}
}

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (input.fail()) {
		std::cout << "Error: could not read input file." << std::endl;
		return 1;
	}

	std::map<std::string, float> data = convertCsvToMap();
	// std::map<std::string, float> data = convertCsvToMap("./ngData.csv");
	// output(data);
	BitcoinExchange be(data);
	std::string line;
	while (std::getline(input, line)) {
		be.exchange_res(line);
	}
}