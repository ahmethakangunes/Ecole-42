#include "Fixed.h"

Fixed::Fixed() {
    cout << "Default constructor called" << endl;
    _fixednumber = 0;
}

Fixed::Fixed(const int number) {
    cout << "Int constructor called" << endl;
    _fixednumber = number << _fractionalpoint;
}

Fixed::Fixed(const float number) {
    cout << "Float constructor called" << endl;
    _fixednumber = (roundf((number * (1 << _fractionalpoint))));
}

Fixed::Fixed(const Fixed &obj) {
    cout << "Copy constructor called" << endl;
    (*this) = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
    cout << "Copy assignment operator called" << endl;
    _fixednumber = obj._fixednumber;
    return (*this);
}

float Fixed::toFloat() const {
    return (roundf(_fixednumber) / (1 << _fractionalpoint));
}

int Fixed::toInt() const {
    return (_fixednumber >> _fractionalpoint);
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}

Fixed::~Fixed() {};
