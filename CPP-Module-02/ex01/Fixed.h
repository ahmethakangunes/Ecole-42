#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
    int _fixedpoint;
    const static int _fractionalpoint = 8;
public:
    Fixed();
    Fixed(const int _fixedpoint);
    Fixed(const float _floatpoint);
    Fixed(const Fixed &obj);
    Fixed &operator=(const Fixed &obj);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
};


#endif
