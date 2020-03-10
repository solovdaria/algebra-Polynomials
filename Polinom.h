//
// Created by Taisiia on 07.03.2020.
//
/*!
 * \file
 * \brief Header file containing class Polinom
 * \details This file contains definition of the class Polinom
 */

#ifndef POLINOMS_POLINOM_H
#define POLINOMS_POLINOM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*!
 * \brief class Polinom contains fields that describe polinom
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
class Polinom {
private:
    //!polynomial degree (maximum degree that a variable can have)
    int power;
    //!Structure that shows every term of every object of class "Polinom"
    struct PElement {
        //!coefficient of terms of polinom
        int key;
        //!pointer to next term
        PElement * next;
    };
    //!Pointer to the first term of every object of class "Polinom"
    PElement * head;

public:
    //!empty constructor
    Polinom();
    //!constructor that take power of polinom and vector of coefficients of this polinom
    Polinom(int _power, std::vector<int> keys);
    ~Polinom();

    //!Getter and Setters (for me they are useless, but still...they are)
    PElement * getHead()const;
    void setHead(PElement * _head);
    int getPower() const;
    void setPower(int _power);

    //!output polinom
    void printPol();
    //!Making term of structure "PElement" (element of polinom) using the value of coefficient
    static PElement * makeItem(int val);
    //!Adding term to the end of the polinom
    static void appendItem(PElement * head, PElement * el);

    Polinom addingPolinoms(Polinom& pol1, Polinom& pol2);
    Polinom differencePolinom(Polinom& pol1, Polinom& pol2);
    Polinom multiplicatePolinom(Polinom& pol1, Polinom& pol2);

    friend Polinom operator *(Polinom& p1, Polinom& p2);
    friend Polinom operator -(Polinom& p1, Polinom& p2);
    friend Polinom operator +(Polinom& p1, Polinom& p2);
};


#endif //POLINOMS_POLINOM_H
