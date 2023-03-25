/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:35 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/21 07:10:24 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

void read_file_and_fill_map(std::string filename, std::map<std::string, double>& data_map)
{
    std::ifstream infile(filename.c_str());
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string date_str;
        double value;
        std::string year_str, month_str, day_str;
        if (std::sscanf(date_str.c_str(), "%4s-%2s-%2s", &year_str[0], &month_str[0], &day_str[0]) != 3)
            // continue; // Skip invalid date format
            std::cout << "invalide date format\n";
        int year = atoi(year_str.c_str());
        int month = atoi(month_str.c_str());
        int day = atoi(day_str.c_str());
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || value < 0 || value > 1000)
            // continue; // Skip invalid values
            std::cout << "invalid values\n";
        std::ostringstream date_ss;
        date_ss << year << "-" << month << "-" << day;
        std::string date = date_ss.str();
        // if (data_map.count(date))
        //     data_map[date] += value; // Aggregate values for existing dates
        data_map[date] = value; // Insert new date with value
    }
}

int main(int ac, char *av[])
{
    std::map<std::string, double> data_map;
    read_file_and_fill_map(av[1], data_map);
    for (std::map<std::string, double>::iterator it = data_map.begin(); it != data_map.end(); ++it)
    {
        std::cout << it->first << "\t" << it->second << std::endl;
    }
    return 0;
}
