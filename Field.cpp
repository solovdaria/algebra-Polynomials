#include "Field.h"


template <int p>
Field<p>::Field(int p) {
	
	//TODO find irreducible polynomial for the given p
}
template <int p>
int Field<p>::mobius(int n)
{
    // Base Case 
    if (n == 1)
        return 1;

    // For a prime factor i check if i^2 is also 
    // a factor. 
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {

            // Check if N is divisible by i^2 
            if (n % (i * i) == 0)
                return 0;
            else

                // i occurs only once, increase f 
                m++;
        }
    }

    // All prime factors are contained only once 
    // Return 1 if p is even else -1 
    return (m % 2 != 0) ? -1 : 1;
}

template <int p>
auto Field<p>::buildCircularPolynom(int n)
{
    Polynom<p> one(0, { 1 }); //1
     std::vector<int> dividers; //делители
    std::vector<Polynom<p>> polynoms;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            dividers.push_back(i);
    }
    int j = dividers.size() - 1;
    for (int i = 0; i < dividers.size(); i++)
    {
        if (mobius(dividers[i]) == 0)
            polynoms.push_back(one);
        else if (mobius(dividers[i]) == 1)
        {
            Polynom<p> b;
            Polynom<p> tmp=one;
            tmp.shift(dividers[j]);
            b = tmp - one;

            polynoms.push_back(b);
            j--;
        }
        else
        {
            Polynom<p> b;
            Polynom<p> tmp = one;
            tmp.shift(dividers[j]);
            b = tmp - one;

            polynoms.push_back(inverse(b, one));
            j--;
        }
    }
    Polynom<p> circular;
    circular = one;
    for (int k = 0; k < polynoms.size(); k++)
    {
        circular = circular*polynoms[k];
    }
    return circular;
}