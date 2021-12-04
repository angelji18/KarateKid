#ifndef _SCREENMANAGER_H_
#define _SCREENMANAGER_H_

#include "GameEngine.h"

class ScreenManager{
    private:
        int state;

    public:
        ScreenManager();
        ~ScreenManager();

        void initScreen();
        void endScreen();
        void pauseScreen();
        void chanageState(int);
        int getState();
};

#endif
