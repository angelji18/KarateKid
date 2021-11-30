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


    //currentTime holds the game clock time and is only incremented when the game is not paused
    //the game is paused and resumed using the esc key
    //a variable "esccount" declared in the GameEngine counts the number of times the esc key is pressed.
    //initallly it is set to 0 and on the 1st click it will be set to 1 which will cause the pause screen to appear and the gameClock(currentTime) to stop from further incrementing(since it will cause paused=true)
    //when the second esc key press in detected the esccount is set to 0 which caused the pause screen to disappear and the gameClock to resume
    if(!paused){

      deltaTime = SDL_GetTicks() / 1000.0f - lastTime; // time since last update
      currentTime += deltaTime;
      lastTime = SDL_GetTicks() / 1000.0f;
    }
    else{
      lastTime = SDL_GetTicks() / 1000.0f; //for when the game is paused, we need the last value of the clock in the paused menu
                                          // so here this value is overwritten and lastTime by the end of the pause cyle hold the latest value
    }

    std::cout << currentTime << '\n'; //testing the clock value
    frameStart = SDL_GetTicks();
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
