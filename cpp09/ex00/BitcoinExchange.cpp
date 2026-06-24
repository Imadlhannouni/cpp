#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}

void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (std::getline(iss, date, ',') && iss >> rate)
        {
            data[date] = rate;
        }
    }
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        processLine(line);
    }
}

double BitcoinExchange::findRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it= data.lower_bound(date);

    if (it == data.end())
    {
        --it;
        return it->second;
    }
    if (it->first == date)
    {
        return it->second;
    }
    if (it == data.begin())
        throw std::out_of_range("Error: date before database");
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (const std::invalid_argument&) {
        return false;
    }

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
            return false;
    }

    return true;
}

void BitcoinExchange::processLine(const std::string& line) const
{
    if (line == "date | value") return ;

    size_t sep = line.find(" | ");
    if (sep == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);

    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    double value;
    std::istringstream iss(valueStr);
    if (!(iss >> value))
    {
        std::cerr << "Error: Bad input => " << line << std::endl;
        return ;
    }

    if (value < 0)
    {
        std::cerr << "Error: Not a positive number" << std::endl; return;
    }
    else if (value > MAX_INT)
    {
        std::cerr << "Error: too large number" << std::endl; return;
    }
    
    try {
        double rate = findRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
