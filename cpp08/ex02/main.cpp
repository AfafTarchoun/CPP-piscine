/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:46:40 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/20 02:27:15 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mutated.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // Test popping all elements
    std::cout << "----Popping all elements:" << std::endl;
    while (!mstack.empty())
    {
        std::cout << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "----Stack size after popping all elements: " << mstack.size() << std::endl;
    // Test empty stack
    MutantStack<int> empty_stack;
    std::cout << "----Empty stack size: " << empty_stack.size() << std::endl;
    std::cout << "----Is empty stack empty? " << (empty_stack.empty() ? "Yes" : "No") << std::endl;
    return 0;
}