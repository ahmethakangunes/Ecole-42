#ifndef FIXED_H
#define FIXED_H

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
private:
    int _fixedpoint;
    static const int _fractional = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed &operator=(const Fixed &obj);
    void operator++();
    ~Fixed();
};


#endif
