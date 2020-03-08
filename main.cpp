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

    Polinom c;
    c.addingPolinoms(a, b);
    c.printPol();

    Polinom d;
    d.differencePolinom(a, b);
    d.printPol();

    //Polinom e;
    cout << "step 1" << endl;
    Polinom e = e.multiplicatePolinom(a, b);
    e.printPol();

    return 0;
}
