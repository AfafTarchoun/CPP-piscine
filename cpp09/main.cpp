/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:57:39 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/16 04:07:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bitcoin.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: btc <prices_file>\n";
        return 1;
    }

    // Read bitcoin prices from CSV file
    std::vector<Price> prices;
    std::ifstream prices_file(argv[1]);
    if (!prices_file)
    {
        std::cerr << "Error: could not open file " << argv[1] << "\n";
        return 1;
    }
    std::string line;
    while (std::getline(prices_file, line))
    {
        std::istringstream ss(line);
        std::string date_str;
        double value;
        if (std::getline(ss, date_str, ',') && ss >> value)
            prices.push_back({date_str, value});
    }

    // Read dates and values to evaluate from standard input
    std::vector<Price> input_prices;
    while (std::getline(std::cin, line))
    {
        std::istringstream ss(line);
        std::string date_str;
        double value;
        if (std::getline(ss, date_str, '|') && ss >> value)
            input_prices.push_back({date_str, value});
    }

    // Look up bitcoin prices for each input date and output result
    for (const auto& input_price : input_prices)
    {
        double exchange_rate = -1;
        for (const auto& price : prices)
        {
            if (price.date == input_price.date)
            {
                exchange_rate = price.value;
                break;
            }
        }
        if (exchange_rate < 0)
            std::cerr << "Error: no bitcoin price found for date " << input_price.date << "\n";
        else
            std::cout << input_price.value * exchange_rate << "\n";
    }

    return 0;
}
