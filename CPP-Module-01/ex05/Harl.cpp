#include "Harl.h"

void Harl::complain(std::string level) {
    typedef void (*debug2)(void);
    debug2 = debug();
}

void Harl::debug() {
    cout << "test";
}

void Harl::info() {

}

void Harl::warning() {

}

void Harl::error() {

}