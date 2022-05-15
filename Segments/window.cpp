#include "window.h"

Window::Window() {}

void Window::init() {

    this->identifier = initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    initGraphicElements;
}

void Window::dump() {

    closegraph(this->identifier);
}

void Window::getIdentifier() const{

    return this->identifier;
}

void Window::initGraphicElements() {}
