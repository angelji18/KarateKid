#include "SoundManager.h"

Mix_Chunk *death = NULL;

SoundManager::SoundManager(){
    state = 1;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    death = Mix_LoadWAV("assets/sounds/test.wav");
}

SoundManager::~SoundManager() {

}

void SoundManager::playSound(int flag) {
	switch (flag) {
		case 1 :
			Mix_PlayChannel(-1, death, 0);
			break;
	
	}
}

void SoundManager::closeSoundManager() {
	Mix_FreeChunk(death);
	Mix_Quit();
}















