#pragma once
#include "Polynom.h"


class Ring {
private:
	// a vector of irreducible polynomials
	std::vector<Polynom> polynomials;
	Polynom Q;
	// module (can be not prime)
	int p;

public:
	
};