#include <graphics.h>
#include <iostream>

using namespace std;

int main()
{
    initwindow(900, 900, "Segments Game");

    // NU MODIFICATI ACEST FISIER (INCA)
    // PUTETI SA IL FOLOSITI SA VA TESTATI PROPRIUL COD PE CARE IL SCRIETI IN CADRUL TASKURILOR
    // DUPA CE ATI TESTAT, STERGETI CE ATI ADAUGAT AICI

    #include "generator.h";
    Generator gen;
    Point p = gen.generatePoint();
    circle(p.getX(), p.getY(), 2);

    getch();
    closegraph();
    return 0;
}
