//
// Created by Taisiia on 07.03.2020.
//

#ifndef POLINOMS_POLINOM_H
#define POLINOMS_POLINOM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Polinom {
private:
    int power;
    struct PElement {
        int key;
        PElement * next;
    };
    PElement * head;

public:
    Polinom();
    Polinom(int _power, std::vector<int> keys);
    ~Polinom();

    PElement * getHead()const;
    int getPower() const;
    void setPower(int _power);
    void printPol();
    PElement * makeItem(int val);

    Polinom addingPolinoms(Polinom pol1, Polinom pol2);
};



#endif //POLINOMS_POLINOM_H
