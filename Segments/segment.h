#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"
#include "graphics.h"

class Segment
{
    public:
        Segment();
        Segment(Point a,Point b);
        Point getA() const;
        Point getB() const;

        void paint(int color = DEFAULT_COLOR) const;


    private:
        Point a,b;
};

#endif // SEGMENT_H
