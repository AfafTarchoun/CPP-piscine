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

#include "BitcoinExchange.hpp"

// Read bitcoin prices from a CSV file and return as a vector of prices
std::vector<Price> read_prices_from_file(const std::string& filename)
{
    std::vector<Price> prices;
    std::ifstream prices_file(filename.c_str());
    if (!prices_file)
    {
        std::cerr << "Error: could not open file " << filename << "\n";
        return prices;
    }
    std::string line;
    while (std::getline(prices_file, line))
    {
        std::istringstream ss(line);
        std::string date_str;
        double value;
        if (std::getline(ss, date_str, ',') && ss >> value)
        {
            Price price = {date_str, value};
            prices.push_back(price);
        }
    }
    return prices;
}


// Read dates and values to evaluate from standard input and return as a vector of prices
std::vector<Price> read_input_prices_from_stdin()
{
    std::vector<Price> input_prices;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        std::string date_str;
        double value;
        if (std::getline(ss, date_str, '|') && ss >> value)
        {
            Price input_price = {date_str, value};
            input_prices.push_back(input_price);
        }
        else
        {
            std::cerr << "Error: bad input => " << line << "\n";
        }
    }
    return input_prices;
}

// Look up bitcoin prices for each input date and output result
void evaluate_input_prices(const std::vector<Price>& input_prices, const std::vector<Price>& prices)
{
    for (std::vector<Price>::const_iterator input_price_it = input_prices.begin(); input_price_it != input_prices.end(); ++input_price_it)
    {
        double exchange_rate = -1;
        for (std::vector<Price>::const_iterator price_it = prices.begin(); price_it != prices.end(); ++price_it) {
            if (price_it->date == input_price_it->date)
            {
                exchange_rate = price_it->value;
                break;
            }
        }
        if (exchange_rate < 0)
        {
            std::cerr << "Error: no bitcoin price found for date " << input_price_it->date << "\n";
        }
        else if (input_price_it->value < 0)
        {
            std::cerr << "Error: not a positive number.\n";
        }
        else if (input_price_it->value > 1000)
        {
            std::cerr << "Error: too large a number.\n";
        }
        else
        {
            std::cout << input_price_it->date << " => " << input_price_it->value << " = " << input_price_it->value * exchange_rate << "\n";
        }
    }
}
