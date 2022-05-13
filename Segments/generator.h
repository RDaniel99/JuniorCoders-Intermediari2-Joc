#ifndef H_GENERATOR
#define H_GENERATOR

#include "point.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Generator{
public:
    Generator();
    vector <Point> generatePoints(int numberOfPoints);
private:
    Point generatePoint();
};

#endif // H.GENERATOR
