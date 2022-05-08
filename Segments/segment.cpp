#include "segment.h"
#include "point.h"
#include <graphics.h>

Segment::Segment (Point a, Point b)
{
    this->a = a;
    this->b = b;

Point Segment::getA() const{
    return a;
}

Point Segment::getB() const{
    return b;
}

void Segment::paint(int color) const
{
    line(a.getX(), a.getY(), b.getX(), b.getY());
}

