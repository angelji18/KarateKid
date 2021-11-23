#include "Enemy.h"
#include <math.h>

//SDL_Rect cameraRect;

SpriteManager *enemySpriteManager = NULL;

bool isAlert = false;



Enemy::Enemy(){

}

Enemy::~Enemy(){

}

void Enemy::initEnemy()
{
  enemySpriteManager = new SpriteManager("assets/KK_ENEMY1.png",500,0);
}

// Detects if a given game object is within the given range
bool objectDetected(int playerX, int range) {
	bool detected = false;
	int xDist = enemySpriteManager->getCharacterXpos() - playerX;
	if (abs(xDist) <= range) detected = true;
	return detected;
}

// checks if playerX is within hit range
bool withinHitRange(int playerX) {
	int xDist = enemySpriteManager->getCharacterXpos() - playerX;
	return (abs(xDist) <= 100); // temp
}

// flag table:
// 0 - calm
// 1 - moving
void Enemy::updateEnemy(SDL_Rect& cameraRect, int playerX){
  int flag = 0;
  int step = 0;
  // if MC within range, follow keeping 50 sprites away
  isAlert = objectDetected(playerX, 250);
  if (isAlert) { 
  	std::cout << "ALERT" << std::endl;
  	flag = 1;
  	// check if within hitting range
  	// if not, move to player
  	if (withinHitRange(playerX)) {
  		// enter fight loop
  	} else {
  		// move to player
  		if (getEnemyXpos() - playerX < 0) step = 10;
  		else step = -10;
  	}
  }
  enemySpriteManager-> updateEnemySprite(flag, step);
}



void Enemy::renderEnemy(SDL_Rect& cameraRect){
  std::cout << "ENEMY: ";
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




