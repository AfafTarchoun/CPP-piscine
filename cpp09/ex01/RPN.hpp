/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:30:52 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/02 23:54:56 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

std::string add_spaces(const std::string& expression);
int         evaluate_rpn_expression(const std::string& expression);
