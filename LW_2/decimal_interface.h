#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Decimal {
public:
 
    Decimal();
    Decimal(const std::string& number);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;
    ~Decimal() noexcept;

  
    Decimal& operator=(const Decimal& other);
    Decimal& operator=(Decimal&& other) noexcept;

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

    
    std::string toString() const;

private:
    std::vector<unsigned char> digits;
    void normalize();
};

#endif // DECIMAL_H
