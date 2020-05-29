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
    
    cout << "1) f(x) = " << f;
    cout << "f(4) = " << f.evaluate(4) << "\n\n";


    cout << "2) g(x) = " << g;
    cout << "h(4) = " << g.evaluate(4) << "\n\n";


    cout << "3) h(x) = " << h;
    cout << "b(4) = " << h.evaluate(4) << "\n\n";

    cout << "4) b(x) = " << b;
    cout << "b(4) = " << b.evaluate(4) << "\n\n";


    cout << "\n\nMaking polynomial monic\n";
    Polynom<5> e(3, { 1, 3, 5, 5 });
    cout << "e(x) = " << e;
    e.makeMonic();
    cout << "e(x) {monic} = " << e;

    //!before each action, re-declare the variable (for each action - new variable)
    cout << "--------------------------------------------------------------------\n";
    Polynom<5> res = f + g;
    cout << "\nf(x) + g(x) = " << res;


    Polynom<5> d = f * g;
    cout << "f(x) * g(x) = " << d;

    Polynom<5> der1 = derivative(f);
    cout << "f(x)' = " << der1;

    Polynom<5> der2 = derivative(g);
    cout << "g(x)' = " << der2;

    cout << "\nf == h "<< bool(f == h) << endl;
    cout << "h(x) = " << h;
    h.shift(5); 
    cout << endl;
    cout << "h(x) {shift 5} = " << h;
    cout << "--------------------------------------------------------------------\n";

    cout << "f(x) = " << f;
    cout << "g(x) = " << g;
    Polynom<5> div1 = f / g;
    cout << "f(x) / g(x) = " << div1;
    
    Polynom<5> div2 = f % g;
    cout << "f(x) % g(x) = " << div2;

    cout << "-------------------------------- GCD ------------------------------\n";

    Polynom<2> p1(7, { 1, 0, 0, 0, 0, 0, 0, 1 });
    Polynom<2> p2(5, { 1, 1, 0, 1, 0, 1 });

    cout << "p1(x) = " << p1;
    cout << "p2(x) = " << p2;
    cout << "gcd(p1, p2) = " << GCD(p1, p2); // 1+x^1

    cout << "---" << endl;

    p1 = Polynom<2>(5, { 1, 1, 0, 0, 0, 1 });
    p2 = Polynom<2>(5, { 1, 0, 0, 1, 1, 1 });

    cout << "p1(x) = " << p1;
    cout << "p2(x) = " << p2;
    cout << "gcd(p1, p2) = " << GCD(p1, p2); // 1+x^2+x^3

    cout << "---" << endl;

    Polynom<3> p3(8, { 1, 0, 1, 1, 0, 2, 0, 0, 1 });
    Polynom<3> p4(6, { 2, 0, 2, 2, 0, 1, 2 });
    cout << "p3(x) = " << p3;
    cout << "p4(x) = " << p4;
    Polynom<3> gcd1 = GCD(p3, p4);
    cout << "gcd(p3, p4) = " << gcd1; // 2+x^2

    cout << "---" << endl;

    cout << "h(x) = " << h;
    cout << "g(x) = " << g;
    Polynom<5> gcd2 = GCD(h, g);
    cout << "gcd(h, g) = " << gcd2; // 1

    cout << "--------------------------------------------------------------------\n";

    Polynom<5> x(1, { 2,1 }), field(3, { 2,3,0,1 });
    cout << "x = " << x;
    cout << "field = " << field;
    Polynom<5> inv = inverse(x, field);
    cout << "inverse(x, field) = " << inv;

    cout << "--------------------------------------------------------------------\n";

    Polynom<2> pol1(4, {1,0,0,1,1});
    cout << "1) pol1(x) = " << pol1;
    cout << "Irreducible : ";
    if (pol1.isIrreducible())
        cout << "Yes\n\n";
             else cout << "No\n\n";


    Polynom<5> pol2(3, { 1,0,1,1 });
    cout << "2) pol2(x) = " << pol2;
    cout << "Irreducible : ";
    if (pol2.isIrreducible())
        cout << "Yes\n\n";
    else cout << "No\n\n";



    Polynom<3> irred(6, { 1, 0, 0, 1, 1, 0, 1 });
    Polynom<3> irred2(2, { 1, 0, 1 });
    Polynom<3> irred3(5, { 1, 0, 1, 1, 1, 3 });
   // Polynom<4> red(2, { 1, 2, 1 });
   // Polynom<4> red2(6, { 1, 1, 3, 0, 3, 0, 1 });

    cout << "\n\n\n";

    cout << "3) irred(x) = " << irred;
    cout << "4) irred2(x) = " << irred2;
    cout << "5) irred3(x) = " << irred3;
   // cout << "6) red(x) = " << red;
    cout << "pol1 Order: " << pol1.irrPolynomOrder() << "\n";
    cout << "pol2 Order: " << pol2.irrPolynomOrder() << "\n";
    cout << "irred Order: " << irred.irrPolynomOrder() << "\n";
    cout << "irred2 Order: " << irred2.irrPolynomOrder() << "\n";
    cout << "irred3 Order: " << irred3.irrPolynomOrder() << "\n";
   // cout << "red Order: " << red.irrPolynomOrder() << "\n";

    cout << "--------------------------------------------------------------------\n";

    Polynom<2> test(8, {1,0,0,1,1,0,1,0,1});
    cout << test;
    cout << derivative(test);
   cout << GCD(test,derivative(test));
    return 0;

}
