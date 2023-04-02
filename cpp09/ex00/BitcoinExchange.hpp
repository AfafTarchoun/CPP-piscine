/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:02:20 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/02 02:27:42 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange
{
	private:
		typedef std::map<std::string, float>	btc;
		btc	_data;
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange		&operator=(BitcoinExchange const &);
		bool	check_line(std::string line);
		bool	check_date(std::string year, std::string month, std::string day);
		bool	check_value(std::string value);

	public:
		BitcoinExchange(btc data);
		~BitcoinExchange();
		void	exchange_res(std::string line);
};