#include "GameEngine.h"


GameEngine *gameEngine = NULL;

int main(){
  const int FPS = 60;
  //closests to refresh rate of monitiors
  const float frameDelay = 1000/FPS;
  //maxtime between frames

  Uint32 frameStart;
  int frameTime;
  SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

  gameEngine = new GameEngine();

  gameEngine->initGameEngine("MY GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,false);

  while(gameEngine->running()){

    frameStart = SDL_GetTicks(); // time since we first initialized SDL

    gameEngine->handleGameEngineEvents();
    gameEngine->updateGameEngine(cameraRect);
    gameEngine->renderGameEngine(cameraRect);

    frameTime = SDL_GetTicks()-frameStart;
    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }
  }

  gameEngine->cleanGameEngine();
  return 0;
}
