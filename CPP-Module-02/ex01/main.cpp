#include "Fixed.h"

int main( void ) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    std::cout << c.toInt();
}