// hexagonal_number.cpp : Defines the entry point for the console application.
//


#include <math.h>

#include <iostream>

/*
Given n,    P[n] = 2n*n-n
Given P[n], n    = (sqrt(8 * P[n] + 1) + 1) / 4
*/

uint64_t p(uint64_t n)
{
	return 2 * n*n - n;
}

int main()
{
	uint64_t x;

	do {
		std::cin >> x;
		if (std::cin.eof())
			break;

		uint64_t n = (uint64_t)((sqrt(8 * x + 1) + 1) / 4);

		uint64_t x1 = p(n);
		uint64_t x2 = p(n + 1);
		if (x2 - x > x - x1)
			std::cout << x1 /*<< " " << n*/ << std::endl;
		else
			std::cout << x2 /*<< " " << n + 1*/ << std::endl;
	} while (1);
	return 0;
}