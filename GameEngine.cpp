#include "GameEngine.h"

const int LEVEL_WIDTH = 3750;
const int LEVEL_HEIGHT = 960;

//Screen dimension constants
 const int SCREEN_WIDTH = 800;
 const int SCREEN_HEIGHT = 600;

//size constants
 const int MC_IMG_SRC = 400; //height and width for source Rectangle
 const int MC_IMG_DEST = 150; // height and width for destination rectangle

 const int STEPX = 10;

bool flag_left = false;
bool flag_right = false;
bool paused = false;

int leftcount = 0;
int rightcount = 0;
int esccount = 0;
int start = 0;

//object definition
TileMap *tileMap = NULL;
GameObject *karateKid = NULL;
SDL_Renderer* GameEngine::renderer = NULL;
ScreenManager *startScreen = NULL;



GameEngine::GameEngine(){
}

GameEngine::~GameEngine(){
}

int GameEngine::initGameEngine(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen){
  int flags = 0;

  if(isFullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }


  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    return 0;
  }

  window = SDL_CreateWindow(title, xpos, ypos, width, height, isFullscreen);
  if(window){
    std::cout << "Windown created successfully" << std::endl;
  }

  renderer = SDL_CreateRenderer(window,-1,0);
  if(renderer){
    std::cout << "Renderer created successfully" << std::endl;
  }

  startScreen = new ScreenManager();
  isRunning =true;


  SDL_SetRenderDrawColor(renderer, 192, 238, 254, 1);
  //object initialization
  karateKid = new GameObject();
  tileMap = new TileMap();


  karateKid->initGameObject();


  return 0;
}


void GameEngine::handleGameEngineEvents(){
  SDL_Event input;

  while(SDL_PollEvent(&input) != 0){
      if(input.type == SDL_QUIT)
      isRunning = false;

      if(input.type == SDL_KEYDOWN)
      {
        //std::cout<<"Key Pressed"<<std::endl;


        switch(input.key.keysym.sym)
        {
          case SDLK_LEFT:
            if(startScreen->getState() == 0){
                flag_left = true;
              if (leftcount == 2){
                leftcount = 0;
              }
              else{
                leftcount++;
              }
            }
            break;

          case SDLK_RIGHT:
            if(startScreen->getState() == 0){
              flag_right = true;
              if (rightcount == 2){
                rightcount = 0;
              }
              else{
                rightcount++;
              }
            }
              break;
          case SDLK_RETURN:
            if(startScreen->getState() == 1){
              startScreen->chanageState(0);
            }
            break;

          //TODO: temp until we have a way to end the game
          case SDLK_SPACE:
            startScreen->chanageState(2);
            break;

          case SDLK_ESCAPE:
              if(esccount == 0)
              {
                esccount = 1;
              }
              if(esccount == 1)
              {
                startScreen->chanageState(3);
                paused = true;
                esccount = 2;
              }
              else{
                startScreen->chanageState(0);
                esccount = 0;
                paused = false;

              }

              break;
        }

      }
    }
}

void GameEngine::updateGameEngine(SDL_Rect& cameraRect){

  karateKid->updateGameObject(cameraRect);

}

void GameEngine::renderGameEngine(SDL_Rect& cameraRect){


  SDL_RenderClear(renderer);
  tileMap->drawTileMap(cameraRect);
  karateKid->renderGameObject(cameraRect);
  if(startScreen->getState() == 1){
    startScreen->initScreen();
  } else if(startScreen->getState() == 2){
    startScreen->endScreen();
  }
  else if(startScreen->getState() == 3){
    startScreen->pauseScreen();
  }
  SDL_RenderPresent(renderer);

}

void GameEngine::cleanGameEngine()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
