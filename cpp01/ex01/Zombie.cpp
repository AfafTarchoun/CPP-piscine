/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:18:29 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/24 03:20:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void announce(Zombie &zombie)
{
    std::cout << zombie.getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}