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

    // srcRect.x = 1600;
    srcRect.y = 0;
    srcRect.w = MC_IMG_SRC;
    srcRect.h = MC_IMG_SRC;
  
    if(start == 0){
      srcRect.x = 1600;
      xpos = SpriteManager::getCharacterXpos() + STEPX;
      destRect.x = xpos;
      start = 1 ;

    }
    else{
      if(flag_right == true){
        if(rightcount == 0){
          srcRect.x = 1600;
        }
        else{
          srcRect.x = 2000;
        }

        xpos = SpriteManager::getCharacterXpos() + STEPX;
        destRect.x = xpos;
        flag_right =false;
      }

      else if(flag_left == true){
        if(leftcount == 0){
          srcRect.x = 1200;
        }
        else{
          srcRect.x = 800;
        }
        xpos = SpriteManager::getCharacterXpos() - STEPX;
        destRect.x = xpos;
        flag_left =false;
      }


    }

    // else{
    //   srcRect.x = 1000;
    //   xpos = SpriteManager::getCharacterXpos();
    //   destRect.x = xpos;
    // }

    destRect.y = 320;

}

// ADDED BY KALEB
// Updates enemy sprite based on flag given and step
// step is the x-direction movement
// flag table:
// 0 - calm
// 1 - moving
void SpriteManager::updateEnemySprite(int flag, int step) {
	srcRect.y = 0;
	srcRect.w = MC_IMG_SRC;
	srcRect.h = MC_IMG_SRC;
	
	// if calm
	if (flag == 0) {
		srcRect.x = 1600;
		xpos = SpriteManager::getCharacterXpos();
	}
	// if moving
	if (flag == 1) {
		// if step < 0, move left
		if (step < 0) {
			srcRect.x = 1200;
		}
		// else moving right
		else {
			srcRect.x = 1600;
		}
		xpos = SpriteManager::getCharacterXpos() + step;
	}
	destRect.x = xpos;
	destRect.y = 320;
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
   std::cout << destRect.x-camera.x << ", " << destRect.y << std::endl;

}

