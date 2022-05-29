#include "appmanager.h"

AppManager::AppManager(){
    this -> game = Game();
}

void AppManager::run(){

    this -> initWindow();
    this -> initGame();
    this -> game.play();
}

void AppManager::initWindow{
    this -> WindowManager.initWindow();
}

void AppManager::initGame{
    this -> game.init();
}
