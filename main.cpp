#include <iostream>
#include "Polinom.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polinom a(4, {2, 5, 0, 7, 4});
    Polinom b(3, {2, 4, 6, 3});
    a.printPol();
    b.printPol();
    //a.printPol();
    Polinom c;
    c.addingPolinoms(a, b);
    c.printPol();

    return 0;
}
