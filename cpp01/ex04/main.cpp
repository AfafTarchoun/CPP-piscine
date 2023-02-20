/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:30:01 by atarchou          #+#    #+#             */
/*   Updated: 2023/02/07 05:06:28 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream input(filename);
    if (!input.good())
    {
        std::cout << "Error opening file " << filename << std::endl;
        return 2;
    }
    std::string output_filename = filename + ".replace";
    std::ofstream output(output_filename);
    if (!output.good())
    {
        std::cout << "Error opening file " << output_filename << std::endl;
        return 3;
    }
    std::string line;
    while (std::getline(input, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        output << line << std::endl;
    }
    input.close();
    output.close();
    return 0;
}
