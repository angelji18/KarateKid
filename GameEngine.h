#ifndef  _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <chrono>
#include <thread>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include "TileMap.h"
#include "SpriteManager.h"
#include "ScreenManager.h"
#include "SoundManager.h"

extern Uint32 frameStart;

extern const int LEVEL_WIDTH;
extern const int LEVEL_HEIGHT;

//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//IMG size constants
extern const int MC_IMG_SRC;
extern const int MC_IMG_DEST;

extern bool flag_left;
extern int leftcount; //for left movement
extern int rightcount; //for right movement
extern int esccount;
extern bool flag_right;

extern int start; // to place the player in starting position
extern bool flag_kick;
extern bool flag_punch; // for player punching
extern bool flag_hit; // for player getting hit
extern bool paused;

//character step on xaxis
extern const int STEPX;
extern SDL_Event input;



class GameEngine
{
	   public:
			  GameEngine();
				~GameEngine();

			  int initGameEngine(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen);
			 	void handleGameEngineEvents();
			  void updateGameEngine(SDL_Rect& cameraRect);
			  void renderGameEngine(SDL_Rect& cameraRect);
				void cleanGameEngine();



			bool running(){ return isRunning;}

			static SDL_Renderer* renderer;

			private:

				bool isRunning = false;
        SDL_Window* window;

};

#endif
