#include <iostream>
#include "Polynom.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynom a(2, { -7, 3, 2 });
    Polynom b(3, { 1, 1, -3, 4 });

    cout << "1) f(x) = ";
    a.print();
    cout << "f(4) = " << a.evaluate(4) << "\n\n";
    cout << "2) g(x) = ";
    b.print();
    cout << "g(4) = " << b.evaluate(4) << "\n\n";

    a.valuate();
    a.print();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom res = a + b;
    cout << "f(x) + g(x) = ";
    res.print();

    Polynom c = a - b;
    cout << "f(x) - g(x) = ";
    c.print();

    Polynom d = a * b;
    cout << "f(x) * g(x) = ";
    d.print();

    Polynom der1 = derivative(a);
    cout << "f(x)' = ";
    der1.print();

    Polynom der2 = derivative(b);
    cout << "g(x)' = ";
    der2.print();

    return 0;

}
