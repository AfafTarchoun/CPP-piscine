/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:35 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/02 02:27:47 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(btc  data)
{
	_data = data;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::check_line(std::string line)
{
	if (line.size() < 13)
		return false;
	for (int i = 0; i < 13; i++)
    {
		if (!std::isdigit(line[i]) && (i < 4 || i == 5 || i == 6 || i == 8 || i == 9))
			return false;
		if (line[i] != '-' && (i == 4 || i == 7))
			return false;
		if (line[i] != ' ' && (i == 10 || i == 12))
			return false;
		if (line[i] != '|' && i == 11)
			return false;
	}
	return true;
}

bool	BitcoinExchange::check_date(std::string y, std::string m, std::string d)
{
	int year;
	std::istringstream(y) >> year;
	int month;
	std::istringstream(m) >> month;
	int day;
	std::istringstream(d) >> day;

	if (year < 2009 || 2022 < year || month < 1 || 12 < month || day < 1 || 31 < day)
		return false;
	if (month == 2 && day > 29)
		return false;
	if (month == 2 && day == 29 && year % 4 != 0)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

bool	BitcoinExchange::check_value(std::string value)
{
	int dot = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
			return false;
		if (value[i] == '.')
			dot++;
		if (dot > 1)
			return false;
	}
	return true;
}

void	BitcoinExchange::exchange_res(std::string line)
{
	if (line == "date | value")
		return;
	if (!check_line(line))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);
	if (!check_date(year, month, day))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, 10);
	std::string strVal = line.substr(13, line.size() - 13);
	if (strVal.empty())
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	if (!check_value(strVal))
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	float value;
	std::istringstream(strVal) >> value;
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	btc::iterator	rating = _data.upper_bound(date);
	if (rating != _data.begin())
		rating--;
	std::cout << date << " => " << value << " = " << rating->second * value << std::endl;
}
