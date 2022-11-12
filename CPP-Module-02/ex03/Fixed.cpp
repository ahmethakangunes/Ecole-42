#include "Fixed.h"

Fixed::Fixed() {
    cout << "Default constructor called" << endl;
    _fixednumber = 0;
}

Fixed::Fixed(const Fixed &fixed) {
    (*this) = fixed;
}

Fixed::Fixed(const int number) {
    _fixednumber = number << _fractional;
}

Fixed::Fixed(const float fnumber) {
    _fixednumber = (roundf((float)fnumber * (1 << _fractional)));
}

Fixed &Fixed::operator=(const Fixed &fixed){
    return (*this);
}

bool Fixed::operator>(const Fixed &fixed){
    return (this->_fixednumber) > fixed._fixednumber;
}

bool Fixed::operator<(const Fixed &fixed){
    return (this->_fixednumber) < fixed._fixednumber;
}

bool Fixed::operator>=(const Fixed &fixed){
    return (this->_fixednumber >= fixed._fixednumber);
}

bool Fixed::operator<=(const Fixed &fixed){
    return (this->_fixednumber <= fixed._fixednumber);
}

bool Fixed::operator==(const Fixed &fixed){
    return (this->_fixednumber == fixed._fixednumber);
}

Fixed Fixed::operator+(const Fixed &fixed){
    Fixed temp(this->toFloat() + fixed.toFloat());
    return (temp);
}

Fixed Fixed::operator-(const Fixed &fixed){
    Fixed temp(this->toFloat() - fixed.toFloat());
    return (temp);
}

Fixed Fixed::operator*(const Fixed &fixed){
    Fixed temp(this->toFloat() * fixed.toFloat());
    return (temp);
}

Fixed Fixed::operator/(const Fixed &fixed){
    Fixed temp(this->toFloat() / fixed.toFloat());
    return (temp);
}

float Fixed::toFloat() const {
    return (roundf(_fixednumber) / (1 << _fractional));
}

Fixed Fixed::operator++() {
    Fixed temp = *this;
    this->_fixednumber++;
    return (temp);
}

void Fixed::operator++(int) {
    this->_fixednumber++;
}

Fixed Fixed::operator--(){
    Fixed temp = *this;
    this->_fixednumber--;
    return (temp);
}

void Fixed::operator--(int) {
    this->_fixednumber--;
}

std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}


Fixed::~Fixed() {};