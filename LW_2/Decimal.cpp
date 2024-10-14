#include "Decimal.h"
#include <algorithm>
#include <cctype>
#include <cstring>

Decimal::Decimal() : digits(new unsigned char[1]{0}), size(1) {}

Decimal::Decimal(unsigned long long value) : digits(nullptr), size(0) {
    setValue(value);
}

Decimal::Decimal(const std::string& str) : digits(nullptr), size(0) {
    setValue(str);
}

Decimal::Decimal(const Decimal& other) : digits(new unsigned char[other.size]), size(other.size) {
    std::memcpy(digits, other.digits, size);
}

Decimal::~Decimal() {
    delete[] digits;
}

Decimal& Decimal::operator=(const Decimal& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = new unsigned char[size];
        std::memcpy(digits, other.digits, size);
    }
    return *this;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal result(*this);
    result += other;
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const {
    Decimal result(*this);
    result -= other;
    return result;
}

Decimal& Decimal::operator+=(const Decimal& other) {
    size_t maxSize = std::max(size, other.size);
    resize(maxSize + 1);  

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < size) ? digits[i] : 0;
        unsigned char digit2 = (i < other.size) ? other.digits[i] : 0;
        unsigned char sum = digit1 + digit2 + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        digits[maxSize] = carry;
        ++size;
    }

    normalize();
    return *this;
}

Decimal& Decimal::operator-=(const Decimal& other) {
    if (*this < other) {
        throw std::invalid_argument("Result of subtraction is negative");
    }

    unsigned char borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        unsigned char digit1 = digits[i];
        unsigned char digit2 = (i < other.size) ? other.digits[i] : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        digits[i] = diff;
    }

    normalize();
    return *this;
}

bool Decimal::operator==(const Decimal& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) return false;
    }
    return true;
}

bool Decimal::operator!=(const Decimal& other) const {
    return !(*this == other);
}

bool Decimal::operator<(const Decimal& other) const {
    if (size != other.size) return size < other.size;
    for (size_t i = size - 1; i < size; --i) { 
        if (digits[i] != other.digits[i]) return digits[i] < other.digits[i];
    }
    return false;
}

bool Decimal::operator>(const Decimal& other) const {
    return other < *this;
}

bool Decimal::operator<=(const Decimal& other) const {
    return !(*this > other);
}

bool Decimal::operator>=(const Decimal& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Decimal& decimal) {
    for (size_t i = decimal.size - 1; i < decimal.size; --i) {
        os << static_cast<int>(decimal.digits[i]);
    }
    return os;
}

std::istream& operator>>(std::istream& is, Decimal& decimal) {
    std::string str;
    is >> str;
    decimal.setValue(str);
    return is;
}


std::string Decimal::toString() const {
    std::string result;
    result.reserve(size);
    for (size_t i = size - 1; i < size; --i) {
        result.push_back(digits[i] + '0');
    }
    return result;
}

void Decimal::normalize() {
    size_t newSize = size;
    while (newSize > 1 && digits[newSize - 1] == 0) {
        --newSize;
    }
    if (newSize != size) {
        resize(newSize);
    }
}

void Decimal::resize(size_t newSize) {
    unsigned char* newDigits = new unsigned char[newSize];
    std::memset(newDigits, 0, newSize);
    std::memcpy(newDigits, digits, std::min(size, newSize));
    delete[] digits;
    digits = newDigits;
    size = newSize;
}


void Decimal::setValue(unsigned long long value) {
    size_t newSize = 0;
    unsigned long long temp = value;
    do {
        ++newSize;
        temp /= 10;
    } while (temp > 0);

    delete[] digits;
    digits = new unsigned char[newSize];
    size = newSize;

    for (size_t i = 0; i < size; ++i) {
        digits[i] = value % 10;
        value /= 10;
    }
}

void Decimal::setValue(const std::string& str) {
    size_t newSize = str.size();
    if (newSize == 0) {
        throw std::invalid_argument("Empty string");
    }

    delete[] digits;
    digits = new unsigned char[newSize];
    size = newSize;

    for (size_t i = 0; i < size; ++i) {
        if (!std::isdigit(str[size - 1 - i])) {
            throw std::invalid_argument("Invalid character in string");
        }
        digits[i] = str[size - 1 - i] - '0';
    }
}
