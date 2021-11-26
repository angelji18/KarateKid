#ifndef  _ENEMY_H_
#define _ENEMY_H_



#include "GameEngine.h"

extern SDL_Rect cameraRect;

class Enemy{
  public:
    Enemy(int health);
    ~Enemy();

    void initEnemy();
    void updateEnemy(SDL_Rect& cameraRect, int playerX);
    void renderEnemy(SDL_Rect& cameraRect);

    // ADDED FOR ENEMY COLLISION
    int getEnemyXpos();
    int getEnemyYpos();
    
    void setAlertFlag(bool flag);
    void setHitFlag(bool flag);
    
    bool enemyIsDead();
    
  private:
    int health; 

};

#endif
