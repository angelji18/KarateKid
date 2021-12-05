#include "SoundManager.h"
#include "math.h"

Mix_Chunk *death = NULL;
Mix_Chunk *hit = NULL;
Mix_Chunk *steps[3];
Mix_Chunk *deaths[3];
Mix_Chunk *alerts[3];
Mix_Chunk *blocks[2];

SoundManager::SoundManager(){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    death = Mix_LoadWAV("assets/sounds/test.wav");
    hit = Mix_LoadWAV("assets/sounds/hit.wav");
    
    steps[0] = Mix_LoadWAV("assets/sounds/step1.wav");
    steps[1] = Mix_LoadWAV("assets/sounds/step2.wav");
    steps[2] = Mix_LoadWAV("assets/sounds/step3.wav");
    
    deaths[0] = Mix_LoadWAV("assets/sounds/die1.wav");
    deaths[1] = Mix_LoadWAV("assets/sounds/die2.wav");
    deaths[2] = Mix_LoadWAV("assets/sounds/die3.wav");
    
    alerts[0] = Mix_LoadWAV("assets/sounds/alert1.wav");
    alerts[1] = Mix_LoadWAV("assets/sounds/alert2.wav");
    alerts[2] = Mix_LoadWAV("assets/sounds/alert3.wav");
    
    blocks[0] = Mix_LoadWAV("assets/sounds/block2.wav");
    blocks[1] = Mix_LoadWAV("assets/sounds/block3.wav");
}

SoundManager::~SoundManager() {

}

void playWalk() {
	
	
	
	
}

/* Flag table:
1 - enemy death
2 - enemy hit
3 - walk
4 - enemy alert
5 - enemy block
*/
void SoundManager::playSound(int flag) {
	switch (flag) {
		case 1 :
			//Mix_PlayChannel(-1, death, 0);
			srand(time(NULL));
			Mix_PlayChannel(-1, deaths[rand()%3], 0); // play random death
			break;
		case 2 :
			Mix_PlayChannel(-1, hit, 0);
			break;
		case 3 :
			srand(time(NULL));
			Mix_PlayChannel(-1, steps[rand()%3], 0); // play random step
			break;
		case 4 :
			srand(time(NULL));
			Mix_PlayChannel(-1, alerts[rand()%3], 0); // play random alert
			break;
		case 5 :
			srand(time(NULL));
			Mix_PlayChannel(-1, blocks[rand()%2], 0); // play random block
			break;
	}
}

void SoundManager::closeSoundManager() {
	Mix_FreeChunk(death);
	Mix_FreeChunk(hit);
	Mix_Quit();
}















