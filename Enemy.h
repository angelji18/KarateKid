#ifndef  _ENEMY_H_
#define _ENEMY_H_



#include "GameEngine.h"

extern SDL_Rect cameraRect;

class Enemy{
  public:
    Enemy(int health, int block_chance, int strength);
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
    bool blocked(int &flag);
    bool enemyThrewPunch(); // tell if enemy has thrown a punch
    
  private:
    int health; 
    int block_chance;
    int strength;
    
    bool punching;
    
    bool hitPlayer(int &flag); // try to hit player

};

#endif
