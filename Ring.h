#pragma once
#include "Polynom.h"

template <int p>//Template parameter p (module)

class Ring : public Polynom <p> {
private:
	// a vector of irreducible polynomials
	std::vector<Polynom> polynomials;
	Polynom Q;
	// module (can be not prime)
public:
	//+
	//-
	//*
	//==
	//!=
	
};