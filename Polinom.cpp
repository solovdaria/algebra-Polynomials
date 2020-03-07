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
    while ( tmp != NULL ) {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
}

Polinom::~Polinom() {

    PElement * tmp = new PElement;
    PElement * cur = head;
    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = NULL;
    cout << "in destructor" << endl;
}
