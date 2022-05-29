#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include "point.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Generator
{
    public:
        Generator();
        vector<Point> generatePoints(int numberOfPoints);


    private:
        Point generatePoint();
};

#endif // GENERATOR_H
