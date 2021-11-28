#ifndef  _GAMEOBJECT_H_
#define _GAMEOBJECT_H_



#include "GameEngine.h"

extern SDL_Rect cameraRect;

class GameObject{
  public:
    GameObject();
    ~GameObject();

    void initGameObject();
    void updateGameObject(SDL_Rect& cameraRect);
    void renderGameObject(SDL_Rect& cameraRect);

    void setCamera( SDL_Rect& cameraRect );
    
    // ADDED FOR ENEMY COLLISION
    int getObjectXpos();
    int getObjectYpos();
    int getObjectHealth();
    
    // ADDED BY KALEB
    void alterHealth(int val); // increment/decrement health by given value
    
  private:
    int health; // ADDED BY KALEB
    

};

#endif
