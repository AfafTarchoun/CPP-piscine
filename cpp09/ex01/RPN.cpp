/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:38 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/02 02:30:48 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"
#include <iostream>
#include <cctype>

std::string add_spaces(const std::string& expression)
{
    std::string result;
    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]) && i > 0 && !isdigit(expression[i-1]))
            result += ' ';
        result += expression[i];
    }
    return result;
}

int evaluate_rpn_expression(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: no RPN expression provided\n";
        return 1;
    }
    std::stack<int>     stack;
    std::string         expression = add_spaces(argv[1]);
    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            int number = expression[i] - '0';
            stack.push(number);
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cout << "Error: insufficient operands for " << expression[i] << "\n";
                return 1;
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result;
            switch (expression[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        std::cout << "Error: division by zero\n";
                        return 1;
                    }
                    result = operand1 / operand2;
                    break;
            }
            stack.push(result);
        }
        else if (!isspace(expression[i]))
        {
            std::cout << "Error: unrecognized token '" << expression[i] << "'\n";
            return 1;
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Error: too many operands\n";
        return 1;
    }
    std::cout << stack.top() << "\n";
    return 0;
}
