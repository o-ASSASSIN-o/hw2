#pragma once
#include <chrono>
using Duration = std::chrono::duration<double, std::milli>;

#define TIMEIT(dur,...)\
   {\
    auto start = std::chrono::high_resolution_clock::now();\
    __VA_ARGS__\
    auto end = std::chrono::high_resolution_clock::now();\
     dur = std::chrono::duration<double, std::milli>(end - start);\
}

#pragma once
#pragma once
