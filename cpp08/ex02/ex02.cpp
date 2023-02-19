/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:14 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:42:15 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class T> MutantStack<T>::MutantStack()
{
}

template <class T> MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template <class T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &a)
{
    return *this;
}

template <class T> MutantStack<T>::~MutantStack()
{
}

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
    std::stack<int> s(mstack);
    return 0;
}