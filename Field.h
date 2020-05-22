#pragma once
#include "Polynom.h"

class Field {
private:
	// irreducible polynomial
	Polynom Q;
	// module prime
	int p;
	bool isPrime(int number);
public:
	Field(int p);

	Polynom plus(Polynom& p1, Polynom& p2);
	Polynom minus(Polynom& p1, Polynom& p2);
	Polynom divide(Polynom& p1, Polynom& p2);
	Polynom multiply(Polynom& p1, Polynom& p2);

};