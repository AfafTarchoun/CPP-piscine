/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:37:06 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:06:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void announce(Zombie &zombie)
{
    std::cout << zombie.getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
