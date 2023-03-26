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

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return (1);
    }
    std::vector<Price> prices = read_prices_from_file(argv[1]);
    std::vector<Price> input_prices = read_input_prices_from_stdin();
    evaluate_input_prices(input_prices, prices);
    return (0);
}
