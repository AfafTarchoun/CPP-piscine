/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:42:19 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/27 21:42:21 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <class T >
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return std::stack<T>::c.begin();
        }
        iterator end()
        {
            return std::stack<T>::c.end();
        }
        MutantStack();
        MutantStack(const MutantStack &obj);
        MutantStack &operator=(const MutantStack &a);
        ~MutantStack();
};