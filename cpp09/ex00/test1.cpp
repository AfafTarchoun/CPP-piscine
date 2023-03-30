#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
    // Check if file argument is provided
    if (argc < 2) {
        std::cerr << "Error: no file provided." << std::endl;
        return 1;
    }

    // Open bitcoin price database
    std::ifstream btc_file("btc.csv");
    if (!btc_file.is_open()) {
        std::cerr << "Error: could not open bitcoin price database." << std::endl;
        return 1;
    }

    // Parse bitcoin price database and store in map
    std::map<std::string, double> btc_map;
    std::string line;
    std::getline(btc_file, line); // Skip header line
    while (std::getline(btc_file, line)) {
        std::stringstream ss(line);
        std::string date_str;
        std::getline(ss, date_str, ',');
        double price;
        ss >> price;
        btc_map[date_str] = price;
    }

    // Open input file and process each line
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string date_str;
        double value;
        std::getline(ss, date_str, '|');
        ss >> value;
        if (ss.fail() || value <= 0 || value > 1000) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        std::map<std::string, double>::const_iterator iter = btc_map.find(date_str);
        if (iter == btc_map.end())
        {
            std::cerr << "Error: no bitcoin price available for date " << date_str << std::endl;
            continue;
        }
        double btc_price = iter->second;
        double result = value * btc_price;
        if (result <= 0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::cout << date_str << " => " << value << " = " << result << std::endl;
    }

    return 0;
}
