//
// Created by Taisiia on 07.03.2020.
//

/*!
 * \file
 * \brief C++ file with implementation of class Polynom
 * \details Functional of polinoms, mathematical actions
 */

#include <iostream>
#include "cmath"
#include "Polynom.h"

using std::cout;
using std::cin;
using std::endl;

template <int p>
int Polynom<p>::getLastCoefficient()
{
    PElement* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    return temp->key;
}

template <int p>
int Polynom<p>::getCoefficient(int pos) {
    PElement* temp = this->head;
    int counter(0);
    while (temp->next) {
        if (counter == pos) break;
        temp = temp->next;
        counter++;
    }
    return temp->key;
}


template <int p>
void Polynom<p>::cutZeroes() {
    int flag = this->findPower();
    auto* temp = this->head;
    PElement* new_head = makeItem(this->head->key);
    for (size_t i(0); i < flag; i++) {
        temp = temp->next;
        appendItem(new_head, makeItem(temp->key));
    }
    clear();
    setHead(new_head);
    this->power = flag;
}

template <int p>
int Polynom<p>::modInverse(int number)
{
    int x, y;
    int g = gcdExtended(number, p, &x, &y);

    if (g != 1)
        return -1;

    return (x % p + p) % p;
}

template <int p>
int Polynom<p>::gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0, * y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

template <int p>
int Polynom<p>::modDivision(int a, int b)
{
    a = a % p;
    int inv = modInverse(b);
    if (inv == -1)
        cout << "Division not defined";
    else return (inv * a) % p;
}

template <int p>
int Polynom<p>::modMultiply(int a, int b) {
    return (a * b) % p;
}

template <int p>
Polynom<p>::Polynom() {
    head = nullptr;
    power = 0;
}

template <int p>
Polynom<p>::Polynom(int _power, std::vector<int> keys) {
    power = _power;
    head = makeItem(keys[0]);

    for (int i = 1; i < keys.size(); i++) {
        appendItem(head, makeItem(keys[i]));
    }
    makeMod();
    cutZeroes();
}

template <int p>
Polynom<p>::Polynom(int _power, int _field, std::vector<int> keys)
{
}

template <int p>
void Polynom<p>::makeMod() {
    PElement* tmp = head;
    while (tmp != nullptr) {
        if (tmp->key >= p)
            tmp->key = tmp->key % p;
        else while (tmp->key < 0) {
            tmp->key = tmp->key + p;
        }
        tmp = tmp->next;
    }
}

template <int p>
int Polynom<p>::findPower() {
    int flag = 0, counter = 0;
    auto* tmp = this->head;
    while (tmp) {
        if (tmp->key) {
            flag = counter;
            counter++;
        }
        else
            counter++;
        tmp = tmp->next;
    }
    return flag;
}

template <int p>
typename Polynom<p>::PElement* Polynom<p>::makeItem(int value) {
    auto* el = new PElement;
    el->key = value;
    el->next = nullptr;
    return el;
}

template <int p>
void Polynom<p>::appendItem(Polynom<p>::PElement* head, Polynom::PElement* el) {
    PElement* tmp = head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = el;
}

template <int p>
void Polynom<p>::print() {
    PElement* tmp = this->head;

    int i = 0;
    bool isFirst = true;
    while (tmp != nullptr) {
        if (tmp->key == 0) {
            tmp = tmp->next;
            i++;
            continue;
        }
        if (!isFirst) cout << "+";
        else isFirst = false;
        if (tmp->key != 1 || i == 0)
            cout << tmp->key;
        if (i != 0) cout << "x^" << i;
        tmp = tmp->next;
        i++;
    }
    cout << endl;
}

template <int p>
void Polynom<p>::shift(int n) {
    if (n == 0) return;
    PElement* new_head = makeItem(0);
    for (int i(1); i < n; i++) {
        appendItem(new_head, makeItem(0));
    }
    appendItem(new_head, this->head);
    setHead(new_head);
    this->power += n;
}

template <int p>
void Polynom<p>::clear() {
    auto* current = this->head;
    while (current) {
        this->head = this->head->next;
        free(current);
        current = this->head;
    }
    this->power = 0;
}

template <int p>
void Polynom<p>::set(int pos, int key) {
    auto* tmp = this->head;
    if (pos <= this->power) {
        int counter = 0;
        while (tmp) {
            if (counter == pos) break;
            tmp = tmp->next;
            counter++;
        }
        if (this->power == 0)
            this->head = makeItem(key);
        else
            tmp->key = key;
    }
    else {
        int counter = 0;
        if (tmp)
            while (tmp) {
                tmp = tmp->next;
                counter++;
            }
        int j = counter;
        if (counter == 0) { this->head = makeItem(0); counter++; }
        for (int j(counter); j < pos; j++) {
            appendItem(this->head, makeItem(0));
        }
        appendItem(this->head, makeItem(key));
        this->power = pos;
    }
    makeMod();
}

template <int p>
void Polynom<p>::copy(Polynom& pol) {
    clear();
    auto* tmp = pol.head;
    this->head = makeItem(tmp->key);
    tmp = tmp->next;
    while (tmp) {
        appendItem(this->head, makeItem(tmp->key));
        tmp = tmp->next;
    }
    this->power = pol.power;
}

template <int p>
Polynom<p>::~Polynom() {
    //
}

template <int p>
typename Polynom<p>::PElement* Polynom<p>::getHead() const {
    return head;
}

template <int p>
void Polynom<p>::setHead(Polynom<p>::PElement* _head) {
    head = _head;
}

template <int p>
int Polynom<p>::getPower() const {
    return power;
}

template <int p>
void Polynom<p>::setPower(int _power) {
    power = _power;
}

template <int p>
void Polynom<p>::valuate(int coef)
{
    PElement* temp = head;
    while (temp) {
        temp->key = modDivision(temp->key, coef);
        temp = temp->next;
    }

}

template<int p>
void Polynom<p>::makeMonic() {
    int coef = getLastCoefficient();
    valuate(coef);
}

template <int p>
bool Polynom<p>::isMonic() {
    int coef = getLastCoefficient();
    return(coef == 1);
}

template <int p>
bool Polynom<p>::isZero() {
    Polynom<p> zero(0, { 0 });
    return ((*this) == zero);

}

template <int p>
bool Polynom<p>::isIrreducible() {
    Polynom tmp, odd(1, { 0, 1 }),gcd_;
    Polynom one(0, {1});
    makeMonic();
    int power_;
    for (size_t i(1); i <= this->power / 2; i++) {
        tmp.copy(one);
        power_ = pow(p,i);
        tmp.shift(power_);
        if((tmp - odd).power >= this->power)
        gcd_ = gcd((*this), (tmp - odd) % (*this));
        else {
            gcd_ = gcd((*this), tmp - odd);
        }
        if (gcd_ != one) return false;
        tmp.clear();

    }
    return true;
}

template <int p>
int Polynom<p>::evaluate(int x)
{
    PElement* temp = head;
    int result = 0;
    int pp = 0;
    while (temp != nullptr) {
        result = result + temp->key * pow(x, pp);
        pp++;
        temp = temp->next;
    }
    return result;
}

template <int p>
void Polynom<p>::addingPolinoms(Polynom& pol1, Polynom& pol2) {
    power = (pol1.power > pol2.power) ? pol1.power : pol2.power;
    head = makeItem(pol1.head->key + pol2.head->key);

    PElement* tmp1 = pol1.head->next;
    PElement* tmp2 = pol2.head->next;

    while ((tmp1) && (tmp2)) {
        appendItem(head, makeItem(tmp1->key + tmp2->key));
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    while (tmp1) {
        appendItem(head, makeItem(tmp1->key));
        tmp1 = tmp1->next;
    }
    while (tmp2) {
        appendItem(head, makeItem(tmp2->key));
        tmp2 = tmp2->next;
    }
}

template <int p>
void Polynom<p>::differencePolinom(Polynom& pol1, Polynom& pol2) {
    this->power = (pol1.power > pol2.power) ? pol1.power : pol2.power;
    head = makeItem(pol1.head->key - pol2.head->key);

    PElement* tmp1 = pol1.head->next;
    PElement* tmp2 = pol2.head->next;

    while ((tmp1) && (tmp2)) {
        appendItem(head, makeItem(tmp1->key - tmp2->key));
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    while (tmp1) {
        appendItem(head, makeItem(tmp1->key));
        tmp1 = tmp1->next;
    }
    while (tmp2) {
        appendItem(head, makeItem(tmp2->key * (-1)));
        tmp2 = tmp2->next;
    }
}

template <int p>
void Polynom<p>::multiplicatePolinom(Polynom& pol1, Polynom& pol2) {
    if (pol1.isZero() || pol2.isZero()) return;

    int pow = pol1.power + pol2.power;
    for (size_t k(0); k <= pow; k++) {
        int c(0);
        for (size_t j(0); j <= k; j++) {
            if ((j <= pol1.power) && (k - j <= pol2.power))
                c += modMultiply(pol1.getCoefficient(j), pol2.getCoefficient(k - j));
        }
        this->set(k, c);
    }
}

template <int p>
void Polynom<p>::quot_rem(Polynom& A, Polynom& B, Polynom& Q, Polynom& R) {
    Polynom<p> A_copy; A_copy.copy(A);
    Q.clear(); R.clear();
    while (A_copy.power >= B.power) {
        int k = A_copy.power - B.power;
        Polynom<p> B_copy; B_copy.copy(B);
        if (k)
            B_copy.shift(k);
        int a_lead = A_copy.getLastCoefficient();
        int b_lead = B_copy.getLastCoefficient();

        for (size_t j(0); j <= B_copy.power; j++) {
            int set_value = modMultiply(B_copy.getCoefficient(j), modDivision(a_lead, b_lead));
            B_copy.set(j, set_value);
        }
        Polynom<p> temp = A_copy - B_copy;
        A_copy = temp;
        A_copy.cutZeroes();
        Q.set(k, modDivision(a_lead, b_lead));
    }
    Polynom<p> temp = Q * B;
    temp.cutZeroes();
    R = A - temp;
}

template <int p>
auto Polynom<p>::gcd(Polynom& pol1, Polynom& pol2) {
    if (pol2.isZero()) {
        if (pol1.isMonic()) return pol1;
        Polynom<p> pol1_copy; pol1_copy.copy(pol1);
        pol1_copy.makeMonic();
        return pol1_copy;
    }
    Polynom<p> odd = pol1 % pol2;
    if (odd.power == 0 && odd.head->key != 0) return Polynom(0, { 1 });
    return gcd(pol2, odd);
}

template <int p>
auto Polynom<p>::gcdExtended(Polynom& A, Polynom& B) {
    Polynom S, R, V(0, {0}), U(0, {1});//U is inverse of A mod B(p^m)
    Polynom Rshift, Ushift,temp;

    S.copy(B); R.copy(A);

    while (R.power) {
        int s = S.power - R.power;
        if (s < 0) {
            temp.copy(S); S.copy(R); R.copy(temp);
            temp.copy(V); V.copy(U); U.copy(temp);
            s *= -1;
        }
        Rshift.copy(R); Ushift.copy(U);
        Rshift.shift(s); Ushift.shift(s);
        S = S - Rshift;
        V = V - Ushift;
    }

    U.makeMonic();
    return U;
}

template <int p>
auto GCD(Polynom<p>& p1, Polynom<p>& p2) {
    if (p1.power < p2.power) {
        Polynom<p> temp = p1;
        p1 = p2;
        p2 = temp;
    }
    Polynom<p>c = p1.Polynom<p>::gcd(p1, p2);
    c.Polynom<p>::makeMod();
    return c;
}

template <int p>
auto derivative(Polynom<p>& pol1)
{
    auto* result = new Polynom<p>();
    auto temp = pol1.head;
    result->power = pol1.power - 1;

    int power = 0;

    while (temp) {
        if (power != 0) {
            if (result->head != nullptr) Polynom<p>::appendItem(result->head, Polynom<p>::makeItem(temp->key * power));
            else result->head = Polynom<p>::makeItem(temp->key * power);
        }
        temp = temp->next;
        power++;
    }
    result->Polynom<p>::makeMod();
    return *result;
}

template <int p>
auto operator*(Polynom<p>& p1, Polynom<p>& p2) {
    auto* c = new Polynom<p>();
    c->Polynom<p>::multiplicatePolinom(p1, p2);
    c->Polynom<p>::cutZeroes();
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator+(Polynom<p>& p1, Polynom<p>& p2) {
    auto* c = new Polynom<p>();
    c->Polynom<p>::addingPolinoms(p1, p2);
    c->Polynom<p>::cutZeroes();
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator-(Polynom<p>& p1, Polynom<p>& p2) {
    auto* c = new Polynom<p>();
    c->Polynom<p>::differencePolinom(p1, p2);
    c->Polynom<p>::cutZeroes();
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator/(Polynom<p>& p1, Polynom<p>& p2) {
    if (p1.power < p2.power) { cout << "Can`t divide! The degree of dividend is always greater than divisor!\n\n"; return Polynom<p>(); }
    if (p2.isZero()) { cout << "Can't divide by 0!\n"; return Polynom<p>(); }
    Polynom<p> Q, R;
    if (p2.power == 0) {
        p1.valuate(p2.head->key);
        Q.copy(p1);
    }
    else
        p1.Polynom<p>::quot_rem(p1, p2, Q, R);
    return Q;
}

template <int p>
auto operator%(Polynom<p>& p1, Polynom<p>& p2) {
    if (p1.power < p2.power) { cout << "Can`t divide! The degree of dividend is always greater than divisor!\n\n"; return Polynom<p>(); }
    if (p2.isZero()) { cout << "Can't divide by 0!\n"; return Polynom<p>(); }
    Polynom<p> Q, R;
    if (p2.power == 0) {
        return Polynom<p>(0, { 0 });
    }
    else
        p1.Polynom<p>::quot_rem(p1, p2, Q, R);
    return R;
}

template <int p>
auto operator==(Polynom<p>& p1, Polynom<p>& p2) {
    if (p1.power != p2.power) return false;
    auto temp1 = p1.head, temp2 = p2.head;
    while (temp1) {
        if (temp1->key != temp2->key) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <int p>
auto operator!=(Polynom<p>& p1, Polynom<p>& p2) {
    return !(p1 == p2);
}

template <int p>
auto inverse(Polynom<p>& pol, Polynom<p>& field) {
    Polynom<p> result = pol.Polynom<p>::gcdExtended(pol, field);
    return result;
}
