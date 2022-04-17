#include "segment.h"
#include "point.h"

Segment::Segment (Point a, Point b)
{
    this->a = a;
    this->b = b;
}

Point Segment::getA() const{
    return a;
}

Point Segment::getB() const{
    return b;
}


