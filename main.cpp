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


    cout << "\n\nMaking polynomial monic\n";
    Polynom<5> e(3, { 1, 3, 5, 5 });
    cout << "e(x) = ";
    e.print();
    e.makeMonic();
    cout << "e(x) {monic} = "; e.print();

    //!before each action, re-declare the variable (for each action - new variable)
    Polynom<5> res = f + g;
    cout << "\nf(x) + g(x) = ";
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

    Polynom<5> gcd3 = GCD(f, f);
    cout << "gcd(f, f) = ";
    gcd3.print(); 

    Polynom<5> gcd4 = GCD(h, g);
    cout << "gcd(h, g) = ";
    gcd4.print();

    Polynom<3> x(1, {0,1}), field(3, {1,0,1,1});
    Polynom<3> inv = inverse(x, field);
    cout << "inverse(x, field) = ";
    inv.print();

    Polynom<3> irr(3, {1,2,0,1});
    Polynom<3> tar(2, {1,1,1});

    Polynom<3> div3 = irr / tar ;
    cout << "irr / tar = ";
    div3.print();

    Polynom<3> div4 = irr % tar ;
    cout << "irr % tar = ";
    div4.print();

    Polynom<3> gcd5 = GCD(irr, tar);
    cout << "gcd(irr, tar) = ";
    gcd4.print();


    Polynom<3> irred(7, { 1, 0, 0, 1, 1, 0, 1 });
    Polynom<3> irred2(3, { 1, 0, 1 });
    Polynom<3> irred3(6, { 1, 0, 1, 1, 1, 3 });
    Polynom<3> irred4(7, { 1, 0, 3, 1, 1, 2, });

    cout << "\n\n\n";

    cout << "1) irred(x) = ";
    irred.print();
    cout << "1) irred2(x) = ";
    irred2.print();
    cout << "1) irred3(x) = ";
    irred3.print();
    cout << "1) irred4(x) = ";
    irred4.print();
    cout << "irred Order: " << irred.irrPolynomOrder() << "\n";
    cout << "irred2 Order: " << irred3.irrPolynomOrder() << "\n";
    cout << "irred3 Order: " << irred3.irrPolynomOrder() << "\n";
    cout << "irred4 Order: " << irred4.irrPolynomOrder() << "\n";



    return 0;

}
