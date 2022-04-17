#include "point.h"

class Segment
{
public:
    Segment(Point a, Point b);
    Point getA() const;
    Point getB() const;

private:
    Point a;   // first point
    Point b;  // second point
};
