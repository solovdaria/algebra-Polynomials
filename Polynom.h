//
// Created by Taisiia on 07.03.2020.
//
/*!
 * \file
 * \brief Header file containing class Polynom
 * \details This file contains definition of the class Polynom
 */

#ifndef POLINOMS_POLYNOM_H
#define POLINOMS_POLYNOM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*!
 * \brief class Polynom contains fields that describe polinom
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
class Polynom {
private:
    //!polynomial degree (maximum degree that a variable can have)
    int power;
    //!Structure that shows every term of every object of class "Polynom"
    struct PElement {
        //!coefficient of terms of polinom
        int key;
        //!pointer to next term
        PElement *next;
    };
    //!Pointer to the first term of every object of class "Polynom"
    PElement *head;

    int getLastCoefficient();
public:
    //!empty constructor
    Polynom();
    //!constructor that take power of polinom and vector of coefficients of this polinom
    Polynom(int _power, std::vector<int> keys);
    ~Polynom();

    //!Getter and Setters (for me they are useless, but still...they are)
    PElement *getHead()const;
    void setHead(PElement * _head);
    int getPower() const;
    void setPower(int _power);

    //!output polinom
    void print();
    //!Making term of structure "PElement" (element of polinom) using the value of coefficient
    static PElement * makeItem(int val);
    //!Adding term to the end of the polinom
    static void appendItem(PElement * head, PElement * el);

    // Norming (valuation) of the polynom
    void valuate();
    int evaluate(int x);

    void addingPolinoms(Polynom& pol1, Polynom& pol2);
    void differencePolinom(Polynom& pol1, Polynom& pol2);
    void multiplicatePolinom(Polynom& pol1, Polynom& pol2);

    friend Polynom derivative(Polynom& pol1);
    friend Polynom operator *(Polynom& p1, Polynom& p2);
    friend Polynom operator -(Polynom& p1, Polynom& p2);
    friend Polynom operator +(Polynom& p1, Polynom& p2);
};


#endif //POLINOMS_POLYNOM_H
