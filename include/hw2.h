#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <thread>
#ifndef CPP20
#include "barrier.h"
#else
#include <thread>
#include <barrier>
#endif 

#ifndef NUM_THREADS
#define NUM_THREADS 8
#endif // !NUM_THREADS

/* cuoff is used for the quicksort part only */
const int cutoff = 1 << 19;

#ifndef CPP20
CSC413::barrier barrier(NUM_THREADS);
#else
std::barrier barrier(NUM_THREADS);
#endif // !CPP20



template<typename T>
void parScan(std::vector<T>& v) {
	/* Write your code here */
}

template <typename Iter>
Iter partition(Iter start, Iter end) {
	/* Write your code here */
	/* assume the input is random and select the
	* first element as pivot
	*/
	
}

template<typename Iter>
void seqQuicksort(Iter start, Iter end) {
	/* Write your code here */
}


template<typename Iter>
void parQuicksort(Iter start, Iter end) {
	/* Write your code here */
}
