#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {}

Board::Board(vector <Point> points){
    this->points = points;
    this->segments.clear();
}

void Board::addSegments(Segment &segment){
    this->segment.push_back(Segment);
}

vector<Point> Board::getPoints() {
    return this->points;
}

bool Board::markpoint(int index. Point:Status status){
    if(index < 0 || index >= this->points.size())
        return false;
    return this->points[index].getStatus();
}

bool Board::existSolutions() const {

    if(this->points.size() - this->segment.size() * 2 <= 1)
        return false;

    for(auto pointOne: this->points){

        for(auto pointTwo: this->points){

        if(pointOne.getX() == pointsTwo.getX() && pointOne.getY() == pointsTwo.getY())
                continue;

       /* if(canUnion(pointOne, pointTwo)) {
            cout << "can union" << pointOne.getX() <<" "<< pointOne.getY() <<" "<< pointTwo.getX() <<" "<<pointTwo.getY()
        } */
        }
    }
}

bool Board::canUnion(const Point& pointOne,const Point& pointTwo)const {
    for(auto segment: this->segments){

        if(doesInteresct(segment, pointOne, pointTwo)){

            return false;
        }
    }
    return true;
}

bool Board::doesIntersect(const Segment& segment, const Point& pointOne, const Point& pointTwo) const{

    int orientationOne = computeOrientation(segment.getA(), segment.getB(), pointOne);
    int orientationTwo = computeOrientation(segment.getA(), segment.getB(), pointTwo);
    int orientationThree = computeOrientation(pointOne, pointTwo, segment.getA());
    int orientationFour = computeOrientation(pointOne, pointTwo, segment.getB());

    if(orientationOne != orientationTwo && orientationThree != orientationFour) return true;

    if(orientationOne == 0 && isPointOnSegment(segment.getA(), segment.getB, pointOne)) return true;
    if(orientationTwo == 0 && isPointOnSegment(segment.getA(), segment.getB, pointTwo)) return true;
    if(orientationThree == 0 && isPointOnSegment(pointOne, pointTwo, segment.getA())) return true;
    if(orientationFour == 0 && isPointOnSegment(pointOne, pointTwo, segment.getB())) return true;

    return false;
}

bool Board::isPointOnSegment(const Point& S1, const Point& S2, const Point& P) const {

    bool ok = true;

    ok = ok && (max(S1.getX(), S2,getX()) >= P.getX);
    ok = ok && (min(S1.getX(), S2,getX()) <= P.getX);
    ok = ok && (max(S1.getY(), S2,getY()) <= P.getY);
    ok = ok && (min(S1.getY(), S2,getY()) <= P.getY);

    return ok;
}

int Board::computeOrientation (const Point& A, const Point& B, const Point C) const {

    int orientation = ((B.getY() - A.getY()) * (C.getX() - B.getX()) - (B.getX() - A.getX()) * (C.getY() - B.getY));

    if(!orientation)
        return 0;

    return orientation / abs(orientation);
}
