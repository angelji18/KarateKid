#include "GameEngine.h"
#include <string.h>

const int LEVEL_WIDTH = 3750;
const int LEVEL_HEIGHT = 960;

//Screen dimension constants
 const int SCREEN_WIDTH = 800;
 const int SCREEN_HEIGHT = 600;

//size constants
 const int MC_IMG_SRC = 400; //height and width for source Rectangle
 const int MC_IMG_DEST = 150; // height and width for destination rectangle

 const int STEPX = 10;

 SDL_Event input;

bool flag_left = false;
bool flag_right = false;
bool flag_kick = false;
bool flag_punch = false; // ADDED BY KALEB
bool flag_hit = false; // ADDED BY KALEB

bool paused = false;


int leftcount = 0;
int rightcount = 0;
int esccount = 0;
int introcount = 0; // for dialogue during intro
int start = 0;

int enemyCount = 4;

int score = 500;
int score_start = 0;
int t = 0;

//object definition
TileMap *tileMap = NULL;
GameObject *karateKid = NULL;
Enemy *enemy1 = NULL;
Enemy *enemy2 = NULL;
Enemy *enemy3 = NULL;
Enemy *boss = NULL;
SDL_Renderer* GameEngine::renderer = NULL;
ScreenManager *startScreen = NULL;
SoundManager *sound = NULL;

Enemy *enemies[4];


GameEngine::GameEngine(){
}

GameEngine::~GameEngine(){
}

int GameEngine::initGameEngine(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen){
  int flags = 0;

  if(isFullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }

  SDL_Init(SDL_INIT_TIMER);
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    return 0;
  }

  window = SDL_CreateWindow(title, xpos, ypos, width, height, isFullscreen);
  if(window){
    std::cout << "Windown created successfully" << std::endl;
  }

  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  if(renderer){
    std::cout << "Renderer created successfully" << std::endl;
  }
  startScreen = new ScreenManager();
  isRunning =true;


  SDL_SetRenderDrawColor(renderer, 192, 238, 254, 1);


  //object initialization
  karateKid = new GameObject();


  enemy1 = new Enemy(15, 20, 20); // enemy w/ health = 10, block_chance = 20%, strength = 50%
  //std::cout << enemy1 << std::endl;
  enemy2 = new Enemy(20, 30, 30); // enemy w/ health = 20, block_chance = 30%, strength = 50%
  //std::cout << enemy2 << std::endl;
  enemy3 = new Enemy(20, 40, 40); // enemy w/ health = 20, block_chance = 40%, strength = 40%
  boss = new Enemy(30, 50, 50); // enemy w/ health = 30, block_chance = 50%, strength = 50%

  tileMap = new TileMap();


  karateKid->initGameObject();

  //char *basicEnemySprite = "assets/KK_ENEMY1_HIT2.png";
  enemy1->initEnemy(500, "assets/KK_ENEMY1_HIT2.png");
  enemy2->initEnemy(900, "assets/KK_ENEMY1_HIT2.png");
  enemy3->initEnemy(1400, "assets/KK_ENEMY1_HIT2.png");
  boss->initEnemy(2000, "assets/KK_BOSS.png");


  // put enemies into container (array)
  enemies[0] = enemy1;
  enemies[1] = enemy2;
  enemies[2] = enemy3;
  enemies[3] = boss;


  // init sound
  sound = new SoundManager();
  sound->playMusic(1);

  return 0;
}


// ADDED BY KALEB
// Tell if player is within given range to an enemy
// returns false if enemy is dead
bool playerAtEnemy(Enemy *enem, int range) {
	if (!enem->enemyIsDead()) {
		int playerX = karateKid->getObjectXpos();
		int enemyX = enem->getEnemyXpos();
		int xDist = playerX - enemyX;
		if (abs(xDist) <= range) return true;
	}
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
                     for (int i = 0; i < enemyCount; i++)
		      	if (playerAtEnemy(enemies[i], 50)) flag_right = false; // added
		      else {
		      	flag_right = true; // modified
		      }
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
              sound->stopMusic();
              startScreen->chanageState(5);
              sound->playMusic(3);
            } else if (startScreen->getState() == 5) {
              //sound->stopMusic();
              if (introcount < 4) {
		      //startScreen->chanageState(introcount);
		      sound->playIntroDialogue(introcount);
		      introcount++;
	      } else {
	      	sound->stopMusic();
	        startScreen->chanageState(0);
	        sound->playMusic(2);
	        score_start = SDL_GetTicks() / 500;
	      }
            }
            break;
           // ADDED BY KALEB
           case SDLK_SPACE:
              // player has punched
              flag_punch = true;
              // if the player is within hit range, updateEnemy to react to hit
              for (int i = 0; i < enemyCount; i++) {
		      if (playerAtEnemy(enemies[i], 70))
		        enemies[i]->setHitFlag(true);
	      }
              break;

              case SDLK_LSHIFT:
                 // player has punched
                 flag_kick = true;
                 // if the player is within hit range, updateEnemy to react to hit
                 for (int i = 0; i < enemyCount; i++) {
   		      if (playerAtEnemy(enemies[i], 70))
   		        enemies[i]->setHitFlag(true);
   	      }
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
    if(score_start && !paused) t = score_start + SDL_GetTicks()/500;
    score = 500 - t;
}

// ADDED BY KALEB
void doBattle(GameObject *karateKid, Enemy *enem) {
	// if enemy has punched, decrement health
	if (enem->enemyThrewPunch()) {
		karateKid->alterHealth(-20);
		flag_hit = true;
	}
}

// ADDED BY KALEB
void gameOver() {
	sound->stopMusic();
	startScreen->chanageState(2);
	sound->playSound(6);
	paused = true;
}

// ADDED BY KALEB
void win() {
	sound->stopMusic();
	startScreen->chanageState(4);
	sound->playSound(7);
	paused = true;
}

void GameEngine::updateGameEngine(SDL_Rect& cameraRect){

  if (!paused) {
  	  if (karateKid->isDead()) gameOver();
  	  else if (boss->enemyIsDead()) win();
  	  else {
		  karateKid->updateGameObject(cameraRect);
		  //enemy1->updateEnemy(cameraRect, karateKid->getObjectXpos());
		  for (int i = 0; i < enemyCount; i++) {
		  	enemies[i]->updateEnemy(cameraRect, karateKid->getObjectXpos());
		  	doBattle(karateKid, enemies[i]); // temp(?) function for handling battle between player and enemy
		  }
	  }
  }
}

void GameEngine::renderGameEngine(SDL_Rect& cameraRect){

  SDL_RenderClear(renderer);
  tileMap->drawTileMap(cameraRect);
  startScreen->displayHealth(karateKid->getObjectHealth());
  startScreen->displayScore(score);
  karateKid->renderGameObject(cameraRect);
  //enemy1->renderEnemy(cameraRect);
  for (int i = 0; i < enemyCount; i++) {
  	enemies[i]->renderEnemy(cameraRect);
  }

  /* screen manager actions */

  switch (startScreen->getState()) {
  	case 1:
  		startScreen->initScreen();
  		break;
  	case 2:
  		startScreen->endScreen();
  		break;
  	case 3:
  		startScreen->pauseScreen();
  		break;
  	case 4:
  		startScreen->winScreen();
  		break;
  	case 5:
  		startScreen->introScreen(introcount);
  		break;
  }

  /* end screen manager actions */



  SDL_RenderPresent(renderer);

}

void GameEngine::cleanGameEngine()
{
  sound->closeSoundManager();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
