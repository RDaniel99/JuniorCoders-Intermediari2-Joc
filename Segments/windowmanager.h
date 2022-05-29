#ifndef H_WINDOW_MANAGER
#define H_WINDOW_MANAGER

#include "window.h"
#include <map>
using namespace std;
class WindowManager {

    public:
        WindowManager();
        bool SetCurrentWindow(int windowIdentifier);
        void InitWindow();
    private:
        int InitGameWindow();

        map<int, window> windows;
        int CurrentWindowIdentifier;

};


#endif // H_WINDOW_MANAGER
