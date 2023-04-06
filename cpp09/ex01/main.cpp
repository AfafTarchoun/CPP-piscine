/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:27 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/05 21:31:56 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: no RPN expression provided\n";
        return (1);
    }
    if (argc > 2)
    {
        std::cerr << "Error: More than one argument provided\n";
        return (1);
    }
    std::string expression = add_spaces(argv[1]);
    return (evaluate_rpn_expression(expression));
}
