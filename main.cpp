#include "GameEngine.h"


GameEngine *gameEngine = NULL;

int main(){
  const int FPS = 60;
  //closests to refresh rate of monitiors
  const float frameDelay = 1000/FPS;
  //maxtime between frames

  Uint32 frameStart;
  int frameTime, lastTime, deltaTime;
  int currentTime = 0;
  SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

  gameEngine = new GameEngine();

  gameEngine->initGameEngine("MY GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,false);
  lastTime = SDL_GetTicks() / 1000.0f;

  while(gameEngine->running()){



    if(!paused){

      deltaTime = SDL_GetTicks() / 1000.0f - lastTime; // time since last update
      currentTime += deltaTime;
      lastTime = SDL_GetTicks() / 1000.0f;
    }
    else{
      lastTime = SDL_GetTicks() / 1000.0f;
    }

    frameStart = SDL_GetTicks();
    gameEngine->handleGameEngineEvents();
    gameEngine->updateGameEngine(cameraRect);
    gameEngine->renderGameEngine(cameraRect);

    frameTime = SDL_GetTicks()-frameStart;
    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }
    std::cout << currentTime << '\n';
  }

  gameEngine->cleanGameEngine();
  return 0;
}
