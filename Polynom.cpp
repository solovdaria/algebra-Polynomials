//
// Created by Taisiia on 07.03.2020.
//

/*!
 * \file
 * \brief C++ file with implementation of class Polynom
 * \details Functional of polinoms, mathematical actions
 */
#include "Polynom.h"
#include "cmath"

using std::cout;
using std::cin;
using std::endl;

int Polynom::getLastCoefficient()
{
    PElement* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    return temp->key;
}

Polynom::Polynom() {
    head = nullptr;
    power = 0;
}

Polynom::Polynom(int _power, std::vector<int> keys) {
    power = _power;
    head = makeItem(keys[0]);

    for (int i = 1; i < keys.size(); i++) {
        appendItem(head, makeItem(keys[i]));
    }
    makeMod();
}

void Polynom::makeMod() {
    PElement *tmp = head;
    while (tmp != nullptr) {
        if (tmp->key >= field)
            tmp->key = tmp->key%field;
        else while (tmp->key < 0) {
                tmp->key = tmp->key + field;
            }
        tmp = tmp->next;
    }
}

Polynom::PElement *Polynom::makeItem(int value) {
    auto *el = new PElement;
    el->key = value;
    el->next = nullptr;
    return el;
}

void Polynom::appendItem(Polynom::PElement *head, Polynom::PElement *el) {
    PElement *tmp = head;
    while (tmp->next != nullptr) tmp = tmp->next;
    tmp->next = el;
}

void Polynom::print() {
    PElement *tmp = this->head;
    int i = 0;
    while (tmp != nullptr) {
        if (tmp->key == 0) {
            tmp = tmp->next;
            i++;
            continue;
        }
        if ((tmp->key > 0) && (i != 0)) cout << "+";
        cout << tmp->key;
        if (i != 0) cout << "x^" << i;
        tmp = tmp->next;
        i++;
    }
    cout << endl;
}

Polynom::~Polynom() {
    if (head)
        delete head->next;
}

Polynom::PElement *Polynom::getHead() const {
    return head;
}

void Polynom::setHead(Polynom::PElement *_head) {
    head = _head;
}

int Polynom::getPower() const {
    return power;
}

void Polynom::setPower(int _power) {
    power = _power;
}

void Polynom::valuate()
{
    int coeffecient = getLastCoefficient();
    PElement* temp = head;
    while (head) temp->key = temp->key / coeffecient;
}

int Polynom::evaluate(int x)
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

void Polynom::addingPolinoms(Polynom &pol1, Polynom &pol2) {
    power = (pol1.power > pol2.power) ? pol1.power : pol2.power;
    head = makeItem(pol1.head->key + pol2.head->key);

    PElement *tmp1 = pol1.head->next;
    PElement *tmp2 = pol2.head->next;

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

void Polynom::differencePolinom(Polynom &pol1, Polynom &pol2) {
    power = (pol1.power > pol2.power) ? pol1.power : pol2.power;
    head = makeItem(pol1.head->key - pol2.head->key);

    PElement *tmp1 = pol1.head->next;
    PElement *tmp2 = pol2.head->next;

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

void Polynom::multiplicatePolinom(Polynom &pol1, Polynom &pol2) {

    power = pol1.power * pol2.power - 1;
    int pow = power;
    std::vector<int> num(pow + 1);

    PElement *tmp1 = pol1.head;
    PElement *tmp2 = pol2.head;
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

Polynom &derivative(Polynom& pol1)
{
    auto *result = new Polynom();
    Polynom::PElement* temp = pol1.head;
    result->power = pol1.power - 1;

    int power = 0;

    while (temp) {
        if (power != 0) {
            if (result->head != nullptr) Polynom::appendItem(result->head, Polynom::makeItem(temp->key * power));
            else result->head = Polynom::makeItem(temp->key * power);
        }
        temp = temp->next;
        power++;
    }
    result->makeMod();
    return *result;
}

Polynom &operator*(Polynom &p1, Polynom &p2) {
    auto *c = new Polynom();
    c->multiplicatePolinom(p1, p2);
    c->makeMod();
    return *c;
}

Polynom &operator+(Polynom &p1, Polynom &p2) {
    auto *c = new Polynom();
    c->addingPolinoms(p1, p2);
    c->makeMod();
    return *c;
}

Polynom &operator-(Polynom &p1, Polynom &p2) {
    auto *c = new Polynom();
    c->differencePolinom(p1, p2);
    c->makeMod();
    return *c;
}