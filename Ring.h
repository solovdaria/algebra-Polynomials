#pragma once
#include "Polynom.h"

template <int p>//Template parameter p (module can be not prime)

class Ring : public Polynom <p> {
private:

protected:
	// a vector of irreducible polynomials
	std::vector<Polynom> polynomials;
	// R(p^n)[x]/Q
	Polynom Q;//could be irreducible
	//p could be prime or not
public:
	//+
	//-
	//*
	//==
	//!=
};