//
// Created by Taisiia on 07.03.2020.
//

/*!
 * \file
 * \brief C++ file with implementation of class Polynom
 * \details Functional of polinoms, mathematical actions
 */
#include "Polynom.h"

using std::cout;
using std::cin;
using std::endl;

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

void Polynom::printPol() {
    PElement *tmp = this->head;
    int i = 0, firstElIs0;
    while (tmp != nullptr) {
        //firstElIs0 = tmp->key;
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

Polynom Polynom::addingPolinoms(Polynom &pol1, Polynom &pol2) {
    Polynom pol3;

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
    return pol3;
}

Polynom Polynom::differencePolinom(Polynom &pol1, Polynom &pol2) {
    Polynom pol3;

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
    return pol3;
}

Polynom Polynom::multiplicatePolinom(Polynom &pol1, Polynom &pol2) {

    int pow = pol1.power * pol2.power - 1;
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

    return Polynom(pow, num);
}

Polynom operator*(Polynom &p1, Polynom &p2) {
    Polynom c = c.multiplicatePolinom(p1, p2);
    return c;
}

Polynom operator+(Polynom &p1, Polynom &p2) {
    Polynom c = c.addingPolinoms(p1, p2);
    return c;
}

Polynom operator-(Polynom &p1, Polynom &p2) {
    Polynom c = c.differencePolinom(p1, p2);
    return c;
}