#include <iostream>
#include "Polynom.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynom<5> a(2, {4, 0, 7});
    Polynom<5> h(2, { -7, 3, 2 });
    Polynom<5> b(4, {0, 1, 1, -3, 4 });
  
    cout << "1) f(x) = ";
    a.print();
    cout << "f(4) = " << a.evaluate(4) << "\n\n";
    cout << "2) g(x) = ";
    b.print();
    cout << "g(4) = " << b.evaluate(4) << "\n\n";

    Polynom<5> e(1, { 1,5 });
    e.print();
    e.valuate();
    e.print();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom<5> res = a + b;
    cout << "f(x) + g(x) = ";
    res.print();

    Polynom<5> c = a - b;
    cout << "f(x) - g(x) = ";
    c.print();

    Polynom<5> d = a * b;
    cout << "f(x) * g(x) = ";
    d.print();

    Polynom<5> der1 = derivative(a);
    cout << "f(x)' = ";
    der1.print();

    Polynom<5> der2 = derivative(b);
    cout << "g(x)' = ";
    der2.print();

    cout <<"a == h "<< bool(a == h) << endl;
    cout << "h(x) = ";
    h.print();
    h.shift(5); cout << endl;
    cout << "h(x) {shift 5} = ";
    h.print();
    h.copy(a);
    h.print();
    return 0;

}
