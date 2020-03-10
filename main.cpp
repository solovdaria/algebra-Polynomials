#include <iostream>
#include "Polinom.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polinom a(2, {-7, 4, 2});
    Polinom b(3, {1, 1, -3, 4});
    a.printPol();
    b.printPol();

    //!before each action, re-declare the variable (for each action - new variable)
    Polinom res = a+b;
    res.printPol();

    Polinom c = a-b;
    c.printPol();

    Polinom d = a*b;
    d.printPol();

    return 0;
}
