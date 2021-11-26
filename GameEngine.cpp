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
bool flag_punch = false; // ADDED BY KALEB

int leftcount = 0;
int rightcount = 0;
int start = 0;

//object definition
TileMap *tileMap = NULL;
GameObject *karateKid = NULL;
Enemy *enemy1 = NULL;
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
  enemy1 = new Enemy(10);
  tileMap = new TileMap();


  karateKid->initGameObject();
  enemy1->initEnemy();


  return 0;
}


// ADDED BY KALEB
// Tell if player is within given range to an enemy
bool playerAtEnemy(Enemy *enem, int range) {
	int playerX = karateKid->getObjectXpos();
	int enemyX = enem->getEnemyXpos();
	int xDist = playerX - enemyX;
	if (abs(xDist) <= range) return true;
	return false;
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
            flag_left = true; 
            if (leftcount == 2){
              leftcount = 0;
            }
            else{
              leftcount++;
            }
            break;

          case SDLK_RIGHT:
              if (playerAtEnemy(enemy1, 50)) flag_right = false; // added
              else flag_right = true; // modified
              if (rightcount == 2){
                rightcount = 0;
              }
              else{
                rightcount++;
              }
              break;
           // ADDED BY KALEB
           case SDLK_SPACE:
              // player has punched
              flag_punch = true;
              // if the player is within hit range, updateEnemy to react to hit
              if (playerAtEnemy(enemy1, 70)) 
                enemy1->setHitFlag(true); 
          }

        }
    }
}

void GameEngine::updateGameEngine(SDL_Rect& cameraRect){

  karateKid->updateGameObject(cameraRect);
  enemy1->updateEnemy(cameraRect, karateKid->getObjectXpos());
  

}

void GameEngine::renderGameEngine(SDL_Rect& cameraRect){


  SDL_RenderClear(renderer);
  tileMap->drawTileMap(cameraRect);
  karateKid->renderGameObject(cameraRect);
  enemy1->renderEnemy(cameraRect);
  SDL_RenderPresent(renderer);

}

void GameEngine::cleanGameEngine()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
