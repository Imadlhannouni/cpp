#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return (*this);
}

static bool isChar(const std::string &s) {
    return (s.length() == 1 && !isdigit(s[0]));
}

static bool isPseudo(const std::string &s) {
    return (s == "nan" || s == "nanf"
        || s == "+inf" || s == "+inff"
        || s == "-inf" || s == "-inff"
        || s == "inf" || s == "inff");
}

static bool isValidNumber(const std::string &s, bool allowDot, bool allowF) {
    if (s.empty())
        return false;
    size_t i = 0;
    bool dot = false;
    if (s[i] == '-' || s[i] == '+')
        i++;
    if (i >= s.length())
        return false;
    for (; i < s.length(); i++) {
        if (s[i] == '.' && allowDot && !dot)
            dot = true;
        else if (s[i] == 'f' && allowF && i == s.length() - 1)
            return dot;
        else if (!isdigit(s[i]))
            return false;
    }
    if (allowDot && !dot)
        return false;
    return true;
}

static void printChar(double d) {
    if (d != d || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (static_cast<int>(d) < 32 || static_cast<int>(d) == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d) {
    if (d != d || d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d) {
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f) && f > -1000000 && f < 1000000)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d) && d > -1000000 && d < 1000000)
        std::cout << ".0";
    std::cout << std::endl;
}

static void convertFromPseudo(const std::string &s) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (s == "nan" || s == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (s[0] == '-') {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string str) {
    if (str.empty()) {
        std::cerr << "Error: empty string" << std::endl;
        return ;
    }
    if (isPseudo(str)) {
        convertFromPseudo(str);
    } else {
        double d;
        if (isChar(str))
            d = static_cast<double>(str[0]);
        else if (isValidNumber(str, false, false))
            d = strtod(str.c_str(), NULL);
        else if (isValidNumber(str, true, false))
            d = strtod(str.c_str(), NULL);
        else if (isValidNumber(str, true, true))
            d = strtod(str.substr(0, str.length() - 1).c_str(), NULL);
        else {
            std::cerr << "Error: invalid input" << std::endl;
            return ;
        }
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    }
}
