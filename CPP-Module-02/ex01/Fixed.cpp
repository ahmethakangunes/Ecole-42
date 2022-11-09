#include "Fixed.h"

using std::cout;
using std::endl;

Fixed::Fixed() {
    cout << "Default constructor called" << endl;
};

Fixed::Fixed(const int _fixedpoint) {
    cout << "Int constructor called" << endl;
    this->_fixedpoint = (_fixedpoint << _fractionalpoint);
};

Fixed::Fixed(float _floatpoint) {
    cout << "Float constructor called" << endl;
    //gelen float değerini fixedpointe çevir.
    _fixedpoint = _floatpoint * (1 << _fractionalpoint);
};

int Fixed::toInt(void) const {
    return (_fixedpoint >> _fractionalpoint);
}

Fixed::Fixed(const Fixed &obj) {
    cout << "Copy constructor called" << endl;
    (*this) = obj;
}

Fixed &Fixed::operator=(const Fixed &obj) {
    cout << "Copy assignment operator called" << endl;
    return (*this);
}

Fixed::~Fixed() {};

