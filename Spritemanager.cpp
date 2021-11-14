#include "SpriteManager.h"

int check = 0;

SpriteManager::SpriteManager(const char* texture,int x, int y)
{
  objTexture = TextureManager::loadTexture(texture);
  xpos = x;
  ypos = y;
}

SpriteManager::~SpriteManager()
{

}

void SpriteManager::updateSprite(){

    srcRect.x = 800;
    srcRect.y = 0;
    srcRect.w = 400;
    srcRect.h = 400;



    if(flag_right == true){
      xpos = SpriteManager::getCharacterXpos()+50;
      destRect.x = xpos;
      flag_right =false;
    }

    else if(flag_left == true){
      xpos = SpriteManager::getCharacterXpos()-50;
      destRect.x = xpos;
      flag_left =false;
    }
    else{
      xpos = SpriteManager::getCharacterXpos();
      destRect.x = xpos;
    }

    destRect.y = 200;

}

int SpriteManager::getCharacterXpos()
{
	return xpos;
}

int SpriteManager::getCharacterYpos()
{
	return ypos;
}

void SpriteManager::renderSprite(SDL_Rect& camera )
{
  //edge collision prevention
  if(destRect.x>LEVEL_WIDTH-150){
    destRect.x = LEVEL_WIDTH-150;
  }
   TextureManager::renderTexture(999, destRect.x-camera.x, destRect.y ,objTexture, &srcRect);

}
