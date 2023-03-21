/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:02:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/16 22:41:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Price
{
	std::string	date;
	double		value;
};

std::vector<Price>	read_prices_from_file(const std::string& filename);
std::vector<Price>	read_input_prices_from_stdin();
void				evaluate_input_prices(const std::vector<Price>& input_prices, const std::vector<Price>& prices);