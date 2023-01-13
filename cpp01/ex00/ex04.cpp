#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments. Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Error opening input file: " << filename << std::endl;
        return 1;
    }

    std::string newFilename = filename + ".replace";
    std::ofstream outputFile(newFilename);
    if (!outputFile) {
        std::cout << "Error opening output file: " << newFilename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        int pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}