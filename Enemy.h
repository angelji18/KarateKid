#ifndef  _ENEMY_H_
#define _ENEMY_H_



#include "GameEngine.h"
#include "SpriteManager.h"
#include <string.h>
extern SDL_Rect cameraRect;

class SpriteManager; // forward-declaration to use SpriteManager types
class SoundManager; // forward-declaration to use SoundManager types

class Enemy{
  public:
    Enemy(int health, int block_chance, int strength);
    ~Enemy();

    void initEnemy(int xLoc, const char *sprite); 
    void updateEnemy(SDL_Rect& cameraRect, int playerX);
    void renderEnemy(SDL_Rect& cameraRect);
    
    // temp
    void setHealth(int health);

    // ADDED FOR ENEMY COLLISION
    int getEnemyXpos();
    int getEnemyYpos();
    
    void setAlertFlag(bool flag);
    void setHitFlag(bool flag);
    void setKickFlag(bool flag);
    
    bool enemyIsDead();
    bool blocked(int &flag);
    bool enemyThrewPunch(); // tell if enemy has thrown a punch
    
  private:
    int health; 
    int block_chance;
    int strength;
    
    bool punching;
    
    bool hitPlayer(int &flag); // try to hit player
    
    bool objectDetected(int playerX, int range);
    
    bool withinHitRange(int playerX);
    
    SpriteManager *enemySpriteManager;
    
    SoundManager *enemySoundManager;
    
    bool isAlert;
    bool isHit;
    bool isKicked;
    bool isDead;

    int last_rand; // ensure same number doesn't happen twice in a row
    int flag; // for state

    Uint32 startAnimTimer; // timer for the animations
    Uint32 endAnimTimer;

    

};

#endif
