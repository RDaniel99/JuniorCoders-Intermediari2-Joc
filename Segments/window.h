#ifndef WINDOW_H
#define WINDOW_H

#include "config.h"

class Window{
public:
    Window();
    void init();
    void dump();
    int getIndentifier() const;

    virtual void initGraphicElements();

private:
    int identifier;
};

#endif

