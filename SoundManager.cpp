#include "SoundManager.h"
#include "math.h"

Mix_Chunk *death = NULL;
Mix_Chunk *hit = NULL;
Mix_Chunk *steps[3];
Mix_Chunk *deaths[3];
Mix_Chunk *alerts[3];
Mix_Chunk *blocks[2];
Mix_Chunk *intro[4];
Mix_Chunk *lose = NULL;
Mix_Chunk *win = NULL;

Mix_Music *startingMusic = NULL;
Mix_Music *world = NULL;
Mix_Music *introMusic = NULL;

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
    
    intro[0] = Mix_LoadWAV("assets/sounds/dialogue1.wav");
    intro[1] = Mix_LoadWAV("assets/sounds/dialogue2.wav");
    intro[2] = Mix_LoadWAV("assets/sounds/dialogue3.wav");
    intro[3] = Mix_LoadWAV("assets/sounds/dialogue4.wav");
    
    lose = Mix_LoadWAV("assets/sounds/Lose.wav");
    win = Mix_LoadWAV("assets/sounds/Win.wav");
    
    startingMusic = Mix_LoadMUS("assets/sounds/Start.wav");
    world = Mix_LoadMUS("assets/sounds/World_Quiet.wav");
    introMusic = Mix_LoadMUS("assets/sounds/Jiji.wav");
    
}

SoundManager::~SoundManager() {

}

/* Flag table:
1 - enemy death
2 - enemy hit
3 - walk
4 - enemy alert
5 - enemy block
6 - lose jingle
7 - win jingle
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
		case 6 :
			Mix_PlayChannel(-1, lose, 0);
			break;
		case 7 :
			Mix_PlayChannel(-1, win, 0);
			break;
	}
}

/* Flag table:
1 - starting music
2 - world music
3 - intro music (Jiji calm)
*/
void SoundManager::playMusic(int flag) {
	switch (flag) {
		case 1:
			Mix_PlayMusic(startingMusic, 1);
			break;
		case 2:
			Mix_PlayMusic(world, 1);
			break;
		case 3:
			Mix_PlayMusic(introMusic, 1);
	}
}

void SoundManager::playIntroDialogue(int sequence) {
	Mix_PlayChannel(-1, intro[sequence], 0); 
}

void SoundManager::pauseMusic() {
	Mix_PauseMusic();
} 

void SoundManager::resumeMusic() {
	Mix_ResumeMusic();
}

void SoundManager::stopMusic() {
	Mix_HaltMusic();
}

void SoundManager::closeSoundManager() {
	Mix_FreeChunk(death);
	Mix_FreeChunk(hit);
	// TODO: free all chunks
	Mix_FreeMusic(startingMusic);
	Mix_FreeMusic(world);
	startingMusic = NULL;
	world = NULL;
	Mix_Quit();
}















