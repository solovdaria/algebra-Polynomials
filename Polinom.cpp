//
// Created by Taisiia on 07.03.2020.
//

#include "Polinom.h"

using std::cout;
using std::cin;
using std::endl;

Polinom::Polinom() {
    head = nullptr;
    power = 0;
}

Polinom::Polinom(int _power, std::vector<int> keys) {
    power = _power;
    head = makeItem(keys[0]);

    for (int i = 1; i < keys.size(); i++) {
        PElement * el = makeItem(keys[i]);

        PElement * tmp = head;
        while ( tmp->next != NULL ) tmp = tmp->next;
        tmp->next = el;
    }
}

Polinom::PElement * Polinom::makeItem(int value) {
    PElement * el = new PElement;
    el->key = value;
    el->next = nullptr;
    return el;
}

void Polinom::printPol() {
    PElement * tmp = this->head;
    int i = 0;
    while ( tmp != nullptr) {
        if (tmp->key == 0) {
            tmp = tmp->next;
            i++;
            continue;
        }
        if (i != 0) cout << " + ";
        cout << tmp->key;
        if (i != 0) cout << "x^" << i;
        tmp = tmp->next;
        i++;
    }
    cout << endl;
}

Polinom::~Polinom() {

    PElement * tmp = new PElement;
    PElement * cur = head;
    while (cur != nullptr) {
        tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
    cout << "in destructor" << endl;
}

Polinom::PElement * Polinom::getHead() const {
    return head;
}

int Polinom::getPower() const {
    return power;
}

void Polinom::setPower(int _power) {
    power = _power;
}


Polinom Polinom::addingPolinoms(Polinom pol1, Polinom pol2) {
    Polinom pol3;

    power = (pol1.power>pol2.power)?pol1.power:pol2.power;
    head = makeItem(pol1.head->key + pol2.head->key);

    PElement * tmp1 = pol1.head->next;
    PElement * tmp2 = pol2.head->next;

    while((tmp1)&&(tmp2)) {

        PElement * el = makeItem(tmp1->key + tmp2->key);
        PElement * tmp = head;
        while ( tmp->next != NULL ) tmp = tmp->next;
        tmp->next = el;

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        tmp = tmp->next;
    }
    cout << tmp1->key << "jkf" << endl;
    while (tmp1) {
        PElement * el = makeItem(tmp1->key);
        PElement * tmp = head;
        while ( tmp->next != NULL ) tmp = tmp->next;
        tmp->next = el;
        tmp1 = tmp1->next;
    }
    while(tmp2) {
        PElement * el = makeItem(tmp2->key);
        PElement * tmp = head;
        while ( tmp->next != NULL ) tmp = tmp->next;
        tmp->next = el;
        tmp2 = tmp2->next;
    }
    return pol3;
}
