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
        void playMusic(int flag);
        void playIntroDialogue(int sequence);
        void pauseMusic();
        void resumeMusic();
        void stopMusic();
        
        void closeSoundManager();

};

#endif
