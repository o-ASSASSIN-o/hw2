/*****************************************************************//**
 * @file   quicksort.cpp
 * @brief  Sequential and Parallel Quicksort
 * 
 * @author Hikmat Farhat
 * @date   April 2021
 *********************************************************************/
#include <iostream>
#include "utilities.h"
#include "hw2.h"

int main()
{
	const int n = 1 << 24;
	std::vector<float> v;
	std::random_device rd;
	std::uniform_real_distribution<float> dist(1, 100);
	std::generate_n(std::back_inserter(v), n,
		[&]() {
			return dist(rd);
		}
	);
	std::vector<float> u = v;
	std::cout<<"is sorted ="<<std::is_sorted(v.begin(), v.end());
	std::cout << "\n";
	Duration par_d;
	TIMEIT(par_d,
	parQuicksort(v.begin(), v.end());
	)
	std::cout << "par duration = " << par_d.count() << "\n";

	std::cout << "is sorted =" << std::is_sorted(v.begin(), v.end());
	std::cout << "\n";
	Duration seq_d;
	TIMEIT(seq_d,
		seqQuicksort(u.begin(), u.end());
	)
		std::cout << "seq duration = " << seq_d.count() << "\n";
}
