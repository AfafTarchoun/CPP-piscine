/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:38 by atarchou          #+#    #+#             */
/*   Updated: 2023/04/07 04:54:19 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string add_spaces(const std::string& expression)
{
    std::string result;
    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]) && i > 0 && !isdigit(expression[i-1]))
            result += ' ';
        result += expression[i];
    }
    return (result);
}

int evaluate_rpn_expression(const std::string& expression)
{
    std::stack<double> stack;

    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            double number = expression[i] - '0';
            stack.push(number);
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for " << expression[i] << "\n";
                return (1);
            }
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();
            double result;
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
                        std::cerr << "Error: division by zero\n";
                        return (1);
                    }
                    else
                        result = operand1 / operand2;
                    break;
            }
            stack.push(result);
        }
        else if (!isspace(expression[i]))
        {
            std::cerr << "Error: unrecognized token '" << expression[i] << "'\n";
            return (1);
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: too many operands\n";
        return (1);
    }
    std::cout << stack.top() << "\n";
    return (0);
}