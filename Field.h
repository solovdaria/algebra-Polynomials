#pragma once
#include "Polynom.h"

template <int p>//Template parameter p (module)

class Field {
private:
	// irreducible polynomial
	Polynom Q;
	// module prime
	int p;
	bool isPrime(int);
public:
	Field(int);

	Polynom plus(Polynom&, Polynom& );
	Polynom minus(Polynom& , Polynom& );
	Polynom divide(Polynom& , Polynom& );
	Polynom multiply(Polynom& , Polynom& );

};