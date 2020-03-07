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
    Polinom(int pow, std::vector<int> keys);
    ~Polinom();


    void printPol();
    PElement * makeItem(int val);
};


#endif //POLINOMS_POLINOM_H
