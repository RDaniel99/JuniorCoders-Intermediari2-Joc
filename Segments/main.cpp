#include <graphics.h>
#include <iostream>
#include <vector>
#include "generator.h"

using namespace std;

int main()
{
    initwindow(900, 900, "Segments Game");

    // NU MODIFICATI ACEST FISIER (INCA)
    // PUTETI SA IL FOLOSITI SA VA TESTATI PROPRIUL COD PE CARE IL SCRIETI IN CADRUL TASKURILOR
    // DUPA CE ATI TESTAT, STERGETI CE ATI ADAUGAT AICI

    Generator gen;
    vector<Point> p = gen.generatePoints(1);
    circle(p[0].getX(), p[0].getY(), 2);

    getch();
    closegraph();
    return 0;
}
