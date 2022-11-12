#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

using std::endl;
using std::cout;

class Fixed{
private:
    int _fixednumber;
    const static int _fractional = 8;
public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(const int number);
    Fixed(const float fnumber);
    Fixed &operator=(const Fixed &fixed);
    bool operator>(const Fixed &fixed);
    bool operator<(const Fixed &fixed);
    bool operator>=(const Fixed &fixed);
    bool operator<=(const Fixed &fixed);
    bool operator==(const Fixed &fixed);
    Fixed operator+(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed);
    Fixed operator/(const Fixed &fixed);
    Fixed operator++();
    void operator++(int);
    Fixed operator--();
    void operator--(int);
    float toFloat(void) const;
    int getRawBits() const;
    void setRawBits(const int raw);
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);


#endif