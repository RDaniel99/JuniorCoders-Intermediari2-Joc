#include "point.h"

Point::Point(){
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
    this->status = FREE;
}

PointStatus Point::getStatus() const {
    return status;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setStatus(PointStatus status) {
    this->status = status;
}
