#include "GameEngine.h"

const int LEVEL_WIDTH = 3750;
const int LEVEL_HEIGHT = 960;

//Screen dimension constants
 const int SCREEN_WIDTH = 800;
 const int SCREEN_HEIGHT = 600;

//size constants
 const int IMG_SRC = 400; //height and width for source Rectangle
 const int IMG_DEST = 150; // height and width for destination rectangle

bool flag_left = false;
bool flag_right = false;

//object definition
TileMap *tileMap = NULL;
GameObject *karateKid = NULL;
SDL_Renderer* GameEngine::renderer = NULL;



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
        std::cout<<"Key Pressed"<<std::endl;


        switch(input.key.keysym.sym)
        {
          case SDLK_LEFT:
            flag_left = true;
            break;

          case SDLK_RIGHT:
              flag_right = true;
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
  SDL_RenderPresent(renderer);

}

void GameEngine::cleanGameEngine()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
