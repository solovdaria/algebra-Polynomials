#pragma once
#include "Ring.h"
#include "Polynom.h"

template <int p>//Template parameter p (module)

class Field :public Ring<p> {
private:

	int mobius(int n);
	//Q is reducible
	//p is prime
public:
	Field(int);
	auto buildCircularPolynom(int n);
	// /
	// %
	// gcd
	// inverse
};