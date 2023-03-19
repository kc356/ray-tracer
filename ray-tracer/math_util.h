#pragma once
#include <cmath>
#include <limits>
#include <memory>
#include <random>

#include "ray.h"
#include "vec3.h"

using namespace std;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) 
{
    return degrees * pi / 180.0;
}

inline double random_double()
{
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    static mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}


inline double clmap(double x, double min, double max)
{
    // clamps the value x to the range[min, max]
    if (x < min) return min;
    if (x > max) return max;
    return x;
}