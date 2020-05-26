#pragma once
#include "Ring.h"

template <int p>//Template parameter p (module)

class Field :public Ring<p> {
private:
	bool isPrime(int);
public:
	Field(int);
	// /
	// %
	// gcd
	// inverse
};