#include <iostream>
#include "Polynom.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynom<5> a(2, {1,2,1});
    Polynom<5> g(2, {1,3,1});
    Polynom<5> h(1, {1,2});
    Polynom<5> b(1, {1,1});
    Polynom<5> zero(0, {0});

    cout << "1) f(x) = ";
    a.print();
    cout << "f(4) = " << a.evaluate(4) << "\n\n";
    cout << "2) g(x) = ";
    b.print();
    cout << "g(4) = " << b.evaluate(4) << "\n\n";

    Polynom<5> e(1, { 1,5 });
    e.print();
    e.makeMonic();
    e.print();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom<5> res = a + b;
    cout << "f(x) + g(x) = ";
    res.print();
    a.print(); b.print();


    Polynom<5> d = g * h;
    g.print(); h.print();
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

    a.print();
    b.print();
    Polynom<5> div1 = a/b;
    cout << "f(x) / g(x) = ";
    div1.print();
    
    Polynom<5> div2 = a % b;
    cout << "f(x) % g(x) = ";
    div2.print();

    Polynom<5> gcd1 = GCD(b,a);
    cout << "gcd(b,a) = ";
    gcd1.print();

    Polynom<5> gcd2 = GCD(a,b);
    cout << "gcd(a,b) = ";
    gcd2.print();

    return 0;

}
