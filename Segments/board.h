#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "point.h"
#include "segment.h"

using namespace std;

class Board
{
    public:
        Board();
        Board(vector<Point> points);
        void addSegment(Segment &segment);
        bool existSolutions() const;
        vector<Point> getPoints() const;
        bool markPoint(int index,Point::Status status);
        Point::Status getPointStatus(int index) const;
        bool canUnion(const Point& pointOne, const Point& pointTwo) const;

    private:
        bool doesInteracts(const Segment& segment, const Point& pointOne, const Point& pointTwo) const;
        int computerOrientaion(const Point& A, const Point& B, const Point& C) const;
        bool isPointOnSegment(const Point& S1,const Point& S2, const Point& S3) const;

        vector<Point> points;
        vector<Segment> segments;
};

#endif // BOARD_H
