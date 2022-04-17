#ifndef H_POINT
#define H_POINT

enum PointStatus {
    FREE = 0,
    SELECTED,
    BLOCKED
};

class Point {

public:
    Point();
    Point(int x, int y);
    void setStatus(PointStatus status);
    int getX() const;
    int getY() const;
    PointStatus getStatus() const;

private:
    int x, y;
    PointStatus status;
};

#endif // H_POINT
