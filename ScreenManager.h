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
        void winScreen();
        void introScreen(int sequence); // ADDED BY KALEB
        void chanageState(int);
        void displayHealth(int health); // ADDED BY KALEB
        int getState();
};

#endif
