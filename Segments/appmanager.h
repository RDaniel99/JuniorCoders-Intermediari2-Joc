#ifndef H_APP_MANAGER
#define H_APP_MANAGER

#include "game.h"
#include "windowmanager.h"

class AppManager {

    public:
        AppManager();
        void run();
    private:
        WindowManager windowManager;
};
#endif //H_APP_MANAGER
