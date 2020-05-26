//
// Created by Taisiia on 07.03.2020.
//
/*!
 * \file
 * \brief Header file containing class Polynom
 * \details This file contains definition of the class Polynom
 */


#ifndef POLINOMS_POLYNOM_H
#define POLINOMS_POLYNOM_H

#include <vector>
#include <string>

/*!
 * \brief class Polynom contains fields that describe polinom
 * \details Every object of this class describe separate polinom
 *
 * a + bx + cx^2
 * power of this polinom - 2
 * a, b, c - coefficients of polinom (key)
 *
 * Every object of this class have structure "PElement"
 * Every structure "PElement" have objects that contains fields "key" and "next"
 * key - coefficient of term
 * next - pointer to next object of structure "PElement"
 */

//forward declaration 
template <int p>//Template parameter p(field)
class Polynom;

//forward declaration
template <int p>
auto GCD(Polynom<p>&, Polynom<p>&);
template <int p>
auto derivative(Polynom<p>& );
template <int p>
auto operator*(Polynom<p>&, Polynom<p>& );
template <int p>
auto operator+(Polynom<p>& , Polynom<p>& );
template <int p>
auto operator-(Polynom<p>& , Polynom<p>& );
template <int p>
auto operator !=(Polynom<p>& , Polynom<p>& );
template <int p>
auto operator ==(Polynom<p>& , Polynom<p>& );
template <int p>
auto operator /(Polynom<p>&, Polynom<p>&);
template <int p>
auto operator %(Polynom<p>&, Polynom<p>&);
template <int p>
auto inverse(Polynom<p>& , Polynom<p>&);


template <int p>//!Template parameter p(field)
class Polynom {
private:
    //!polynomial degree (maximum degree that a variable can have)
    int power;
    //!Structure that shows every term of every object of class "Polynom"
    struct PElement {
        //!coefficient of terms of polinom
        int key;
        //!pointer to next term
        PElement *next;
    };
    //!Mod of polynom
    void makeMod();
    //!Pointer to the first term of every object of class "Polynom"
    PElement *head = nullptr;
    //Clear PElement list
   
    //!Set the coefficient coef. on position pos equal to the value key
    void set(int pos, int key);
    
    void clear();
    
  
    int getLastCoefficient();
    int getCoefficient(int pos);
    int modInverse(int x);
    int gcdExtended(int a, int b, int* x, int* y);
    int modDivision(int a, int b);
    int modMultiply(int a, int b);
    //!Find real power after each operation
    int findPower();
    //!Cut last zeroes and update power
    void cutZeroes();
    //!Copy polynom
    void copy(Polynom& pol);
    bool isPrime(int number);

protected:
    //!A polynomial whose leading coefficientis 1 is called monic
    bool isMonic();
    //!Compare the polynomial with f(x) = 0
    bool isZero();
   
public:
    //!empty constructor
    Polynom();
    //!constructor that take power of polinom and vector of coefficients of this polinom
    explicit Polynom(int _power, std::vector<int> keys);
    ~Polynom();

    //!Getter and Setters (for me they are useless, but still...they are)
    PElement* getHead()const;
    void setHead(PElement* _head);
    int getPower() const;
    void setPower(int _power);

    //!Making term of structure "PElement" (element of polinom) using the value of coefficient
    static PElement* makeItem(int val);
    //!Adding term to the end of the polinom
    static void appendItem(PElement* head, PElement* el);
    //!Each coefficient is shifting upwards
    void shift(int n);
    // Valuation of the polynom
    void valuate(int coef);
    //!A polynomial whose leading coefficientis 1 is called monic
    void makeMonic();
    //!Ben-Or Irreducibility Test
    bool isIrreducible();
    int evaluate(int x);

    //Calculates order of Irreducible polynom
    //returns -1 if Polynom is reducible or f(0) = 0
    int irrPolynomOrder();


    //!Find the quotient and remainder A = Q * B + R
    void quot_rem(Polynom& A, Polynom& B, Polynom& Q, Polynom& R);

    void addingPolinoms(Polynom& pol1, Polynom& pol2);
    void differencePolinom(Polynom& pol1, Polynom& pol2);
    void multiplicatePolinom(Polynom& pol1, Polynom& pol2);
    auto gcd(Polynom& pol1, Polynom& pol2);
    //!find A^(-1) in field B(p^m)
    auto gcdExtended(Polynom& A, Polynom& B);
   
    //!Algorithm for Inversion in field GF(p^m) based on Extended Euclid’s Algorithm
    friend auto inverse<p>(Polynom<p>& pol, Polynom<p>& field );
    friend auto GCD<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto derivative<p>(Polynom<p>& pol1);
    friend auto operator *<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto operator -<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto operator +<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto operator /<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto operator %<p>(Polynom<p>& p1, Polynom<p>& p2);

    //!output polynomial
    template <int p>
    friend std::ostream& operator <<(std::ostream& stream, Polynom<p>& polynomial);
    
    //!equality operators
    friend auto operator ==<p>(Polynom<p>& p1, Polynom<p>& p2);
    friend auto operator !=<p>(Polynom<p>& p1, Polynom<p>& p2);
};

#endif //POLINOMS_POLYNOM_H
