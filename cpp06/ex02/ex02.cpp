/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:48:13 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/17 03:49:52 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    A* a = dynamic_cast<A*>(&p);
    B* b = dynamic_cast<B*>(&p);
    C* c = dynamic_cast<C*>(&p);
    if (a != nullptr) {
        std::cout << "A" << std::endl;
    } else if (b != nullptr) {
        std::cout << "B" << std::endl;
    } else if (c != nullptr) {
        std::cout << "C" << std::endl;
    }
}