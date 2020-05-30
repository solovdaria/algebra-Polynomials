#include "Field.h"

int Field::mobius(int n)
{
    if (n == 1)
        return 1;

    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            if (n % (i * i) == 0)
                return 0;
            else
                m++;
        }
    }
    return (m % 2 != 0) ? -1 : 1;
}

Polynom Field::buildCircularPolynom(int n, int p)
{
    Polynom one(p, 0, { 1 }); //1
    std::vector<int> dividers; //делители
    std::vector<Polynom> polynoms;
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
            Polynom b = one;
            Polynom tmp = one;
            tmp.shift(dividers[j]);
            b = tmp - one;

            polynoms.push_back(b);
            j--;
        }
        else
        {
            Polynom b = one;
            Polynom tmp = one;
            tmp.shift(dividers[j]);
            b = tmp - one;

            polynoms.push_back(inverse(b, one));
            j--;
        }
    }
    Polynom circular = one;

    for (int k = 0; k < polynoms.size(); k++)
    {
        circular = circular * polynoms[k];
    }
    return circular;
}