/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:30:01 by atarchou          #+#    #+#             */
/*   Updated: 2023/01/16 15:30:36 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
// check if enough parameters are passed
if (argc != 4) {
std::cerr << "Error: Incorrect number of parameters. Please provide a filename, s1 and s2." << std::endl;
return 1;
}

// open the input file
std::ifstream inputFile(argv[1]);
if (!inputFile.is_open()) {
std::cerr << "Error: Unable to open input file " << argv[1] << std::endl;
return 1;
}

// create the output file
std::ofstream outputFile(std::string(argv[1]) + ".replace");
if (!outputFile.is_open()) {
std::cerr << "Error: Unable to create output file " << argv[1] << ".replace" << std::endl;
return 1;
}

// read the input file line by line and replace s1 with s2
std::string line;
std::string s1(argv[2]);
std::string s2(argv[3]);
while (std::getline(inputFile, line)) {
size_t pos = 0;
while ((pos = line.find(s1, pos)) != std::string::npos) {
line.replace(pos, s1.length(), s2);
pos += s2.length();
}
outputFile << line << std::endl;
}

// close the input and output files
inputFile.close();
outputFile.close();

return 0;
}