#include <iostream>
#include <string>
#include <algorithm>

class BigInteger
{
public:
    // Constructors
    BigInteger() : value("0") {}
    BigInteger(const std::string &str) : value(removeLeadingZeros(str)) {}

    // Overloaded input/output operators
    friend std::istream &operator>>(std::istream &is, BigInteger &num);
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &num);

    // Overloaded equality operator
    bool operator==(const BigInteger &other) const
    {
        return this->value == other.value;
    }

private:
    std::string value;

    // Helper function to remove leading zeros from a string
    static std::string removeLeadingZeros(const std::string &str)
    {
        auto it = std::find_if(str.begin(), str.end(), [](char c)
                               { return !std::isspace(c); });

        return (it != str.end()) ? std::string(it, str.end()) : "0";
    }
};

// Overloaded input operator
std::istream &operator>>(std::istream &is, BigInteger &num)
{
    std::string input;
    is >> input;
    num.value = BigInteger::removeLeadingZeros(input);
    return is;
}

// Overloaded output operator
std::ostream &operator<<(std::ostream &os, const BigInteger &num)
{
    os << num.value;
    return os;
}

int main()
{
    BigInteger n1("1234567891011");
    BigInteger n2;

    std::cout << "Input an integer = ";
    std::cin >> n2;

    if (n1 == n2)
        std::cout << "Equal.\n";
    else
        std::cout << "Not equal.\n";

    return 0;
}