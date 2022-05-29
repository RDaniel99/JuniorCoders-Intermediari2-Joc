#include "windowmanager.h"

WindowManager: WindowManager(){

    window.clear();
    this -> currentWindowIdentifier = -2;

}

bool WindowManager::setcurrentwindow(int WindowIdentifier) {

    if(this -> currentWindowIdentifier != windowIdentifier && windowIdentifier != -2){

        this -> windows[currentWindowIdentifier].dump();
        this -> windows[windowIdentifier].init();

        setcurrentwindow(windowIdentifier);
        this -> currentWindowIdentifier = windowIdentifier

        return true;
    }
    return false;

}


void WindowManager::initWindow() {

    int StartWindow;
    StartWindow = initGameWindow();
    this -> setCurrentWindow(StartWindow);
}


int WindowManager::InitGameWindow() {

    Window GameWindow;
    GameWindow.init();
    GameWindow.dump();

    this -> windows[gameWindow.getIdentifier()] = gameWindow;
    return GameWindow.getIdentifier();
}
