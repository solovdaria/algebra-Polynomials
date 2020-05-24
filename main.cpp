#include <iostream>
#include "Polynom.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynom<5> f(2, {1,2,1});
    Polynom<5> g(2, {1,3,1});
    Polynom<5> h(1, {1,2});
    Polynom<5> b(1, {1,1});
    Polynom<5> zero(0, {0});

    cout << "1) f(x) = ";
    f.print();
    cout << "f(4) = " << f.evaluate(4) << "\n\n";


    cout << "2) g(x) = ";
    g.print();
    cout << "h(4) = " << g.evaluate(4) << "\n\n";


    cout << "3) h(x) = ";
    h.print();
    cout << "b(4) = " << h.evaluate(4) << "\n\n";

    cout << "4) b(x) = ";
    b.print();
    cout << "b(4) = " << b.evaluate(4) << "\n\n";


    cout << "\n\nMake monic\n";
    Polynom<5> e(1, { 1,3,5 });
    e.print();
    e.makeMonic();
    e.print();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom<5> res = f + g;
    cout << "f(x) + g(x) = ";
    res.print();


    Polynom<5> d = f * g;
    cout << "f(x) * g(x) = ";
    d.print();

    Polynom<5> der1 = derivative(f);
    cout << "f(x)' = ";
    der1.print();

    Polynom<5> der2 = derivative(g);
    cout << "g(x)' = ";
    der2.print();

    cout << "\nf == h "<< bool(f == h) << endl;
    cout << "h(x) = ";
    
    h.print();
    h.shift(5); 
    cout << endl;
    cout << "h(x) {shift 5} = ";
    h.print();

    Polynom<5> div1 = f / g;
    cout << "f(x) / g(x) = ";
    div1.print();
    
    Polynom<5> div2 = f % g;
    cout << "f(x) % g(x) = ";
    div2.print();

    Polynom<5> gcd1 = GCD(b, f);
    cout << "gcd(b, f) = ";
    gcd1.print();

    Polynom<5> gcd2 = GCD(f, b);
    cout << "gcd(f, b) = ";
    gcd2.print();

    return 0;

}
