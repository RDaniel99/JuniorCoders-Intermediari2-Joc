#ifndef POINT_H
#define POINT_H

#include "config.h"

#include <string>

class Point
{
    public:
      enum Status{
          FREE,
          SELECTED,
          BLOCKED
      };
      Point();
      Point(int x,int y);
      int getX() const;
      int getY() const;
      Status getStatus() const;
      void setStatus(Status status);
      bool isClicked(int x, int y) const;

      void paint(int color=DEFAULT_COLOR) const;




    private:
        int x,y;
        Status status;
};

#endif // POINT_H
