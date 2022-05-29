#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "window.h"

#include <map>

using namespace std;

class WindowManager{
public:
    WindowManager();
    bool setCurrentWindow(int windowIdentifier);
    void initWindows();

private:
    int initGameWindow();
    map<int, Window> windows;
    int currentWindowIdentifier;
};


#endif // WINDOWMANAGER_H
