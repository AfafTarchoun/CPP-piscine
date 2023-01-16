/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:37:57 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/02 10:48:13 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    size_t i = 0;
    if (argc == 1)
    {        
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << "\n";
        return (0);
    }
    while (--argc)
    {
        argv++;
        while (i < strlen(*argv))
        {
            (*argv)[i] = std::toupper((*argv)[i]);
            i++;
        }
        i = 0;
        std::cout << (*argv);
    }
    std::cout<<std::endl;
    return 0;
}
