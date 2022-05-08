#include "generator.h"
#include "config.h"

using namespace std;

Generator::Generator()
{
    srand(time(NULL));
}

Point Generator::generatePoint()
{
    int randomX = rand() % WINDOW_WIDTH;
    int randomY = rand() % WINDOW_HEIGHT;

    return Point(randomX, randomY);
}

vector <Point> Generator::generatePoint(int numberOfPoints)
{
    vector <Point> points;

    while(numberOfPoints)
    {
        points.push_back(generatePoint());
        numberOfPoints--;
    }

    return points;
}
