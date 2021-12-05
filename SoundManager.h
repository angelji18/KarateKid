#ifndef _SOUNDMANAGER_H_
#define _SOUNDMANAGER_H_

#include "GameEngine.h"

class SoundManager{
    private:
        int lastRand;

    public:
        SoundManager();
        ~SoundManager();
        
        void playSound(int flag);
        
        void closeSoundManager();

};

#endif
