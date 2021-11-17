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

#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "SpriteManager.h"



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
extern bool flag_right;
extern int start; // to place the player in starting position

//character step on xaxis
extern const int STEPX;


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
			static SDL_Event input;

			private:

				bool isRunning = false;
        SDL_Window* window;

};

#endif
