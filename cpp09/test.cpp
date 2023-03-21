#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

// Define a struct to hold the bitcoin values for a particular date.
struct BitcoinValue
{
    std::string date;
    double value;
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Error: usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    // Open the input file.
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Read the bitcoin values from the input file into a map.
    std::map<std::string, BitcoinValue> bitcoin_values;
    std::string line;
    while (std::getline(input_file, line))
    {
        std::stringstream line_stream(line);
        std::string date_string, value_string, delimiter;
        std::getline(line_stream, date_string, ' ');
        std::getline(line_stream, delimiter, '|');
        std::getline(line_stream, value_string);

        // Convert the date and value strings to their respective types.
        std::stringstream date_stream(date_string);
        int year, month, day;
        char dash1, dash2;
        date_stream >> year >> dash1 >> month >> dash2 >> day;
        if (date_stream.fail() || dash1 != '-' || dash2 != '-')
        {
            std::cerr << "Error: bad input => " << date_string << std::endl;
            continue;
        }
        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            std::cerr << "Error: bad input => " << date_string << std::endl;
            continue;
        }

        std::stringstream value_stream(value_string);
        double value;
        value_stream >> value;
        if (value_stream.fail() || value < 0 || value > 1000)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        // Add the bitcoin value to the map.
        std::string date_key = date_string.substr(0, 10);
        bitcoin_values[date_key] = BitcoinValue();
        bitcoin_values[date_key].date = date_string;
        bitcoin_values[date_key].value = value;
        // bitcoin_values[date_key] = {date_string, value};
        // bitcoin_values[date_key] = BitcoinValue{date_string, value};
    }

    // Read the exchange rates from standard input and output the bitcoin values multiplied by the exchange rate.
    std::string exchange_rate_line;
    while (std::getline(std::cin, exchange_rate_line))
    {
        std::stringstream exchange_rate_stream(exchange_rate_line);
        std::string date_string, delimiter;
        double exchange_rate;
        std::getline(exchange_rate_stream, date_string, ' ');
        std::getline(exchange_rate_stream, delimiter, '|');
        exchange_rate_stream >> exchange_rate;
        if (exchange_rate_stream.fail() || exchange_rate < 0 || exchange_rate > 1000)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        std::string date_key = date_string.substr(0, 10);
        if (bitcoin_values.count(date_key) == 0)
        {
            std::cerr <<"Error: no bitcoin value found for date " << date_key << std::endl;
            continue;
        }
        double bitcoin_value = bitcoin_values[date_key].value;
        double exchange_value = bitcoin_value * exchange_rate;
        if (exchange_value > std::numeric_limits<int>::max())
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::cout << bitcoin_values[date_key].date << " => " << bitcoin_value << " = " << exchange_value << std::endl;
    }
    return 0;
}