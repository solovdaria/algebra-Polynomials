#include "Field.h"

template <int p>
bool Field<p>::isPrime(int number)
{
	int root = sqrt(number);
	for (int i = 2; i <= root; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

template <int p>
Field<p>::Field(int p) {
	assert(p > 0 && isPrime(p));
	//TODO find irreducible polynomial for the given p
}
