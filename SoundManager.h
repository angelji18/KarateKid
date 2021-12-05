#ifndef _SOUNDMANAGER_H_
#define _SOUNDMANAGER_H_

#include "GameEngine.h"

class SoundManager{
    private:
        int state;

    public:
        SoundManager();
        ~SoundManager();
        
        void playSound(int flag);
        
        void closeSoundManager();

};

#endif
