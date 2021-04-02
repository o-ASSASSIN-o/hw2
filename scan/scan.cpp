// scan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "utilities.h"
#include "hw2.h"

int main()
{
	const long long n = 1<<26;
	std::vector<float> v(n);
	std::fill(v.begin(), v.end(), 1.);
	std::vector<float> u(n);
	std::fill(u.begin(), u.end(), 1.);

	Duration par_d;
	TIMEIT(par_d,
		parScan(v);
	)

	
	Duration seq_d;
	TIMEIT(seq_d,
		std::inclusive_scan(u.begin(), u.end(), u.begin(), std::plus{},0.0);
	)
		//std::cout << v[v.size() - 1] << "\n";
		//std::cout << u[u.size()-1] << "\n";
		std::cout << "parallel " << par_d.count() << "\n";
		std::cout << "seq " << seq_d.count() << "\n";

	

}
