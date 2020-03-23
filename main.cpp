#include <iostream>
#include "Polynom.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
    ModField* field = new ModField("3");

    Polynom a(2, { LongModInt("-7", field), LongModInt("3", field), LongModInt("2", field) });
    Polynom b(3, { LongModInt("1", field), LongModInt("1", field), LongModInt("-3", field), LongModInt("4", field) });

    cout << "1) f(x) = ";
    a.print();
    cout << "f(4) = " << a.evaluate(LongModInt(4, field)) << "\n\n";
    cout << "2) g(x) = ";
    b.print();
    cout << "g(4) = " << b.evaluate(LongModInt(4, field)) << "\n\n";

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
