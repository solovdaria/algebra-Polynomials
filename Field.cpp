#include "Field.h"

bool Field::isPrime(int number)
{
	int root = sqrt(number);
	for (int i = 2; i <= root; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

Field::Field(int p) {
	assert(p > 0 && isPrime(p));
	//TODO find irreducible polynomial for the given p
}

Polynom Field::plus(Polynom& p1, Polynom& p2)
{

	return Polynom();
}

Polynom Field::minus(Polynom& p1, Polynom& p2)
{
	return Polynom();
}

Polynom Field::multiply(Polynom& p1, Polynom& p2)
{
	return Polynom();
}

Polynom Field::divide(Polynom& p1, Polynom& p2)
{
	return Polynom();
}
