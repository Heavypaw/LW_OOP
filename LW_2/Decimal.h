#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
#include <stdexcept>

class Decimal {
public:
    Decimal();
    Decimal(unsigned long long value);
    Decimal(const std::string& str);
    Decimal(const Decimal& other);
    ~Decimal();

    Decimal& operator=(const Decimal& other);

    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;
    Decimal& operator+=(const Decimal& other);
    Decimal& operator-=(const Decimal& other);

    bool operator==(const Decimal& other) const;
    bool operator!=(const Decimal& other) const;
    bool operator<(const Decimal& other) const;
    bool operator>(const Decimal& other) const;
    bool operator<=(const Decimal& other) const;
    bool operator>=(const Decimal& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Decimal& decimal);
    friend std::istream& operator>>(std::istream& is, Decimal& decimal);

private:
    unsigned char* digits;  
    size_t size;           

    void normalize();
    void resize(size_t newSize);
    void setValue(unsigned long long value);
    void setValue(const std::string& str);
};

#endif // DECIMAL_H
