#include "Enemy.h"
#include "SpriteManager.h"
#include <math.h>
#include <string.h>

//SDL_Rect cameraRect;

//SpriteManager *enemySpriteManager = NULL;

bool isAlert = false;
bool isHit = false;
bool isDead = false;

int last_rand; // ensure same number doesn't happen twice in a row
int flag = 0; // for state

Uint32 startAnimTimer; // timer for the animations
Uint32 endAnimTimer;


// strength is the % chance to attempt to hit the player
Enemy::Enemy(int health, int block_chance, int strength){
	this->health = health;
	this->block_chance = block_chance;
	this->strength = strength;
	
	punching = false;
	startAnimTimer = 0;
	endAnimTimer = 2000;
	flag = 0;
	
	enemySpriteManager = NULL; // TEMP?
	
	isAlert = false;
	isHit = false;
	isDead = false;

	flag = 0; // for state
}

Enemy::~Enemy(){

}

// TEMP
void Enemy::setHealth(int health) {
	this->health = health;
	std::cout << this << " , health: " << this->health << std::endl;
}

// ADDED SPRITEMANAGER
void Enemy::initEnemy(int xLoc, const char *sprite)
{
  std::cout << "INIT : " << this << " RENDERER : " << enemySpriteManager << std::endl;
  enemySpriteManager = new SpriteManager(sprite,xLoc,0);
  std::cout << "INIT : " << this << " RENDERER : " << enemySpriteManager << std::endl;
  
}

// Detects if a given game object is within the given range
bool Enemy::objectDetected(int playerX, int range) {
	bool detected = false;
	int xDist = enemySpriteManager->getCharacterXpos() - playerX;
	if (abs(xDist) <= range) detected = true;
	return detected;
}

// checks if playerX is within hit range
bool Enemy::withinHitRange(int playerX) {
	int xDist = enemySpriteManager->getCharacterXpos() - playerX;
	return (abs(xDist) <= 100); // temp
}

// determine if enemy will hit player
bool Enemy::hitPlayer(int &flag) {
	srand(time(0));
	int rand_num = rand() % 100 + 1;
	if (rand_num != last_rand && rand_num < strength) {
		srand(time(0));
		flag = 5;
		std::cout << rand_num << std::endl;
		last_rand = rand_num;
		return true;
	}
	return false;
}

bool Enemy::blocked(int &flag) {
	// if player is punching, % chance to block
	srand(time(0));
	int rand_num = rand() % 100 + 1; // value btwn 1 and 100
	//std::cout << rand_num << std::endl;
	if (rand_num < block_chance) std::cout << "BLOCK" << std::endl;
	return (rand_num < block_chance);
}

// isHit is given to determine if enemy should react to being hit
// flag table:
// 0 - calm
// 1 - moving
// 2 - injured
// 3 - dead
// 4 - block
// 5 - punch
void Enemy::updateEnemy(SDL_Rect& cameraRect, int playerX){
  std::cout << this << " UPDATE: " << this->health << std::endl;
  int step = 0;
  punching = false;
  endAnimTimer = SDL_GetTicks();
  if (!isDead) {
  	  if (endAnimTimer >= startAnimTimer + 300) {
		  // if isHit == true, react to hit
		  if (isHit) {
		       startAnimTimer = SDL_GetTicks();
		  	if (!blocked(flag)) {
		  		//std::cout << "NOT BLOCKED" << std::endl;
			  	flag = 2;
			  	step = 0;
			  	health -= 5;
			  	if (health <= 0) isDead = true;
			  	//std::cout << "HEALTH: " << health << std::endl;
			  } else flag = 4;
			  isHit = false;
		  } else {
			  // if MC within range, follow keeping 50 sprites away
			  isAlert = objectDetected(playerX, 250);
			  if (isAlert) { 
			  	//std::cout << "ALERT" << std::endl;
			  	flag = 1;
			  	// check if within hitting range
			  	// if not, move to player
			  	if (withinHitRange(playerX)) {
			  		// enter fight loop
			  		if (hitPlayer(flag)) {
			  			startAnimTimer = SDL_GetTicks();
			  			std::cout << "THROW PUNCH" << std::endl;
			  			punching = true;
			  		}
			  		
			  	} else {
			  		// move to player
			  		if (getEnemyXpos() - playerX < 0) step = 5;
			  		else step = -5;
			  	}
			  }
		  }
	  }
  } else flag = 3;
  enemySpriteManager-> updateEnemySprite(flag, step);
  
}



void Enemy::renderEnemy(SDL_Rect& cameraRect){
  std::cout << this << " RENDERER: " << enemySpriteManager << std::endl;
  enemySpriteManager -> renderSprite(cameraRect);
}

int Enemy::getEnemyXpos() {
	return enemySpriteManager->getCharacterXpos();
}

int Enemy::getEnemyYpos() {
	return enemySpriteManager->getCharacterYpos();
}

void Enemy::setAlertFlag(bool flag) {
	isAlert = flag;
}

void Enemy::setHitFlag(bool flag) {
	isHit = flag;
}

bool Enemy::enemyIsDead() {
	return isDead;
}

bool Enemy::enemyThrewPunch() {
	return punching;
}




