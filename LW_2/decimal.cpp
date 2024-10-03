#include "Decimal.h"
#include <algorithm>

Decimal::Decimal() {
    digits.push_back(0);
}

Decimal::Decimal(const std::string& number) {
    for (auto it = number.rbegin(); it != number.rend(); ++it) {
        if (*it >= '0' && *it <= '9') {
            digits.push_back(*it - '0');
        } else {
            throw std::invalid_argument("Invalid character in decimal string");
        }
    }
    normalize();
}
Decimal::Decimal(const Decimal& other) : digits(other.digits) {}

Decimal::Decimal(Decimal&& other) noexcept : digits(std::move(other.digits)) {}

Decimal::~Decimal() noexcept {}

Decimal& Decimal::operator=(const Decimal& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

Decimal& Decimal::operator=(Decimal&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
    }
    return *this;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal result;
    result.digits.resize(std::max(digits.size(), other.digits.size()) + 1, 0);

    for (size_t i = 0; i < digits.size(); ++i) {
        result.digits[i] += digits[i];
    }
    for (size_t i = 0; i < other.digits.size(); ++i) {
        result.digits[i] += other.digits[i];
    }

    for (size_t i = 0; i < result.digits.size() - 1; ++i) {
        if (result.digits[i] >= 10) {
            result.digits[i] -= 10;
            result.digits[i + 1] += 1;
        }
    }

    result.normalize();
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const {
    if (*this < other) {
        throw std::invalid_argument("Result of subtraction would be negative");
    }

    Decimal result;
    result.digits.resize(digits.size(), 0);

    for (size_t i = 0; i < digits.size(); ++i) {
        result.digits[i] += digits[i];
        if (i < other.digits.size()) {
            result.digits[i] -= other.digits[i];
        }
    }

    for (size_t i = 0; i < result.digits.size() - 1; ++i) {
        if (result.digits[i] < 0) {
            result.digits[i] += 10;
            result.digits[i + 1] -= 1;
        }
    }

    result.normalize();
    return result;
}

Decimal& Decimal::operator+=(const Decimal& other) {
    *this = *this + other;
    return *this;
}

Decimal& Decimal::operator-=(const Decimal& other) {
    *this = *this - other;
    return *this;
}

bool Decimal::operator==(const Decimal& other) const {
    return digits == other.digits;
}

bool Decimal::operator!=(const Decimal& other) const {
    return !(*this == other);
}

bool Decimal::operator<(const Decimal& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (size_t i = digits.size(); i > 0; --i) {
        if (digits[i - 1] != other.digits[i - 1]) {
            return digits[i - 1] < other.digits[i - 1];
        }
    }
    return false;
}

bool Decimal::operator>(const Decimal& other) const {
    return other < *this;
}

bool Decimal::operator<=(const Decimal& other) const {
    return !(other < *this);
}

bool Decimal::operator>=(const Decimal& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Decimal& decimal) {
    for (auto it = decimal.digits.rbegin(); it != decimal.digits.rend(); ++it) {
        os << static_cast<int>(*it);
    }
    return os;
}

std::string Decimal::toString() const {
    std::string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += std::to_string(static_cast<int>(*it));
    }
    return result;
}

void Decimal::normalize() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}
