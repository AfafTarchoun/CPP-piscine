#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: file argument missing." << std::endl;
        return 1;
    }

    // Open the CSV file containing the bitcoin price history
    std::ifstream csv(argv[1]);
    if (!csv.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Read the CSV file into a map, where the key is the date and the value is the bitcoin price
    std::map<std::string, float> bitcoin_prices;
    std::string line;
    while (std::getline(csv, line)) {
        std::stringstream ss(line);
        std::string date_str;
        std::string price_str;
        std::getline(ss, date_str, '|');
        std::getline(ss, price_str);
        if (!price_str.empty()) {
            try {
                float price = std::stof(price_str);
                bitcoin_prices[date_str] = price;
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Error: not a valid price." << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cerr << "Error: price out of range." << std::endl;
            }
        }
    }

    // Process each line of the input file
    std::ifstream input(argv[1]);
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string date_str;
        std::string value_str;
        std::getline(ss, date_str, '|');
        std::getline(ss, value_str);
        if (!value_str.empty()) {
            try {
                float value = std::stof(value_str);
                std::map<std::string, float>::iterator it = bitcoin_prices.find(date_str);
                if (it != bitcoin_prices.end()) {
                    float rate = it->second / 1000.0f;
                    std::cout << date_str << " => " << std::fixed << std::setprecision(2) << value << " = " << rate * value << std::endl;
                }
                else {
                    std::cerr << "Error: no bitcoin price found for date " << date_str << std::endl;
                }
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Error: not a valid number." << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cerr << "Error: number out of range." << std::endl;
            }
        }
    }

    return 0;
}
