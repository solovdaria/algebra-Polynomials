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
        appendItem(head, makeItem(keys[i]));
    }
}

Polinom::PElement *Polinom::makeItem(int value) {
    auto *el = new PElement;
    el->key = value;
    el->next = nullptr;
    return el;
}

void Polinom::appendItem(Polinom::PElement *head, Polinom::PElement *el) {
    PElement *tmp = head;
    while (tmp->next != nullptr) tmp = tmp->next;
    tmp->next = el;
}

void Polinom::printPol() {
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

Polinom::~Polinom() {
    if (head)
        delete head->next;
    cout << "in destructor" << endl;
}

Polinom::PElement *Polinom::getHead() const {
    return head;
}

void Polinom::setHead(Polinom::PElement *_head) {
    head = _head;
}

int Polinom::getPower() const {
    return power;
}

void Polinom::setPower(int _power) {
    power = _power;
}

Polinom Polinom::addingPolinoms(Polinom &pol1, Polinom &pol2) {
    Polinom pol3;

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

Polinom Polinom::differencePolinom(Polinom &pol1, Polinom &pol2) {
    Polinom pol3;

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

Polinom Polinom::multiplicatePolinom(Polinom &pol1, Polinom &pol2) {

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

    Polinom pol3(pow, num);
    return pol3;
}
