#include "Fixed.h"

Fixed::Fixed() {
    _fixedpoint = 0;
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &obj) {
    cout << "Copy constructor called" << endl;
    (*this) = obj;
}

Fixed &Fixed::operator=(const Fixed &obj){
    cout << "Copy assignment operator called" << endl;
    _fixedpoint = obj.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const {
    cout << "getRawBits member function called" << endl;
    return (_fixedpoint);
}

void Fixed::setRawBits(const int raw) {
    _fixedpoint = raw;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}