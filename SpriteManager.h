#ifndef  _SPRITEMANGER_H_
#define _SPRITEMANGER_H_
#include "GameEngine.h"

class SpriteManager{

public:
  SpriteManager(const char* texture, int x, int y);
  ~SpriteManager();


  void updateSprite();
  void updateEnemySprite(int flag, int step); // ADDED FOR ENEMY
  void renderSprite(SDL_Rect& cameraRect);

  //Position accessors
  int getCharacterXpos();
  int getCharacterYpos();


  private:

  SDL_Texture* objTexture;
  SDL_Rect srcRect, destRect;
  int xpos, ypos;




};


#endif
