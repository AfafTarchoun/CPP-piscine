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
#include <map>

class btc
{
	private:
		std::map<std::string float> data;
		int valid_date(std::string date);
		int valid_val(std::string value);

	public:
		btc();
		btc(btc const &other);
		btc const &operator=(btc const &other);
		~btc();

};