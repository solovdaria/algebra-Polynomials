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
void Polynom<p>::shift(int n = 1) {
    PElement* new_head = makeItem(0);
    for(int i(1); i < n; i++) {
        appendItem(new_head,makeItem(0));
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
    this->head = nullptr;
    this->power = -1;
}

template <int p>
void Polynom<p>::set(int pos, int key) {
    auto* tmp = this->head;
    if (pos <= this->power) {
        int counter = 0;
        while (counter!=pos) {
            if (counter == pos) break;
            tmp = tmp->next;
            counter++;
        }
        tmp->key = key;
    }
    else {
        int counter = 0;
        while (tmp) {
            tmp = tmp->next;
            counter++;
        }
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
        appendItem(this->head,makeItem(tmp->key));
        tmp = tmp->next;
    }
    this->power = pol.power;
}

template <int p>
Polynom<p>::~Polynom() {
    if (head)
        delete head->next;
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
void Polynom<p>::valuate()
{
    int coeffecient = getLastCoefficient();
    PElement* temp = head;
    while (temp) {
        temp->key = modDivision(temp->key, coeffecient);
        temp = temp->next;
    }

}

template <int p>
int Polynom<p>::evaluate(int x)
{
    PElement* temp = head;
    int result = 0;
    int p = 0;
    while (temp != nullptr) {
        result = result + temp->key * pow(x, p);
        p++;
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
    power = (pol1.power > pol2.power) ? pol1.power : pol2.power;
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

    power = pol1.power * pol2.power - 1;
    int pow = power;
    std::vector<int> num(pow + 1);

    PElement* tmp1 = pol1.head;
    PElement* tmp2 = pol2.head;
    int i = 0, j = 0;

    while (tmp1) {
        while (tmp2) {
            if ((i + j) < (power + 1))
                num[i + j] += tmp1->key * tmp2->key;
            j++;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
        i++;
        tmp2 = pol2.head;
        j = 0;
    }
    head = makeItem(num[0]);

    for (int n = 1; n < num.size(); n++) {
        appendItem(head, makeItem(num[n]));
    }
}

template <int p>
void Polynom<p>::quot_rem(Polynom& A, Polynom& B, Polynom& Q, Polynom& R) {

}

template <int p>
auto derivative(Polynom<p>& pol1)
{
    auto* result = new Polynom<p>();
    Polynom<p>::PElement* temp = pol1.head;
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
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator+(Polynom<p>& p1, Polynom<p>& p2) {
    auto* c = new Polynom<p>();
    c->Polynom<p>::addingPolinoms(p1, p2);
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator-(Polynom<p>& p1, Polynom<p>& p2) {
    auto* c = new Polynom<p>();
    c->Polynom<p>::differencePolinom(p1, p2);
    c->Polynom<p>::makeMod();
    return *c;
}

template <int p>
auto operator==(Polynom<p>& p1, Polynom<p>& p2) {
    if (p1.power != p2.power) return false;
    Polynom<p>::PElement* temp1 = p1.head,* temp2 = p2.head;
    while (temp1) {
        if (temp1->key!= temp2->key) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
     return true;
}

template <int p>
auto operator!=(Polynom<p>& p1, Polynom<p>& p2) {
    return !(p1 == p2);
}