#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string>
#include <iostream>
#define MAX_INT 2147483647

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        void loadData(const std::string& filename);
        void processInput(const std::string& filename);
        bool isValidDate(const std::string& date) const;
        double findRate(const std::string& date) const;
        void processLine(const std::string& line) const;
};

#endif