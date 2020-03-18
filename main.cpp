#include <iostream>
#include "Polynom.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynom a(2, {-7, 4, 2});
    Polynom b(3, {1, 1, -3, 4});
    a.printPol();
    b.printPol();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom res = a + b;
    res.printPol();

    Polynom c = a - b;
    c.printPol();

    Polynom d = a * b;
    d.printPol();

    return 0;
}
