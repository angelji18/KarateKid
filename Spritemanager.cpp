#include "SpriteManager.h"
//#include "SDL2/SDL_timer.h"

int check = 0;
int lastPosition; // ADDED BY KALEB - last position of the srcRect
int lastSecond = 0; // ADDED BY KALEB - for timing animations



bool punchAction_flag = 0 ;


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
      lastPosition = srcRect.x; // save lastPosition (don't stay on fight anim)
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
        lastPosition = srcRect.x; // save lastPosition (don't stay on fight anim)
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
        lastPosition = srcRect.x; // save lastPosition (don't stay on fight anim)
      }

      // ADDED BY KALEB
      else if (flag_punch == true) {
      	// lastPosition = srcRect.x; // save lastPosition (don't stay on fight anim)
        //
      	// lastSecond = SDL_GetTicks() / 500;
        // gSpriteClips[ 0 ].x =   2800;
        // gSpriteClips[ 0 ].y =   0;
        // gSpriteClips[ 0 ].w =  MC_IMG_SRC;
        // gSpriteClips[ 0 ].h = MC_IMG_SRC;
        //
        // gSpriteClips[ 1 ].x =  2800;
        // gSpriteClips[ 1 ].y =   0;
        // gSpriteClips[ 1 ].w =  MC_IMG_SRC;
        // gSpriteClips[ 1 ].h = MC_IMG_SRC;
        //
        // gSpriteClips[ 2 ].x =   2800;
        // gSpriteClips[ 2 ].y =   0;
        // gSpriteClips[ 2 ].w =  MC_IMG_SRC;
        // gSpriteClips[ 2 ].h = MC_IMG_SRC;
        //
        // gSpriteClips[ 3 ].x =  2800;
        // gSpriteClips[ 3 ].y =   0;
        // gSpriteClips[ 3 ].w =  MC_IMG_SRC;
        // gSpriteClips[ 3 ].h = MC_IMG_SRC;

        punchAction_flag = 1;

      	 srcRect.x = 2800;
      	flag_punch = false;
      	//std::cout << "Flag punch set false" << std::endl;
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
// 2 - injured
// 3 - dead
// 4 - block
// 5 - punch
void SpriteManager::updateEnemySprite(int flag, int step) {
	srcRect.y = 0;
	srcRect.w = MC_IMG_SRC;
	srcRect.h = MC_IMG_SRC;

	// if calm
	if (flag == 0) {
		srcRect.y = 0;
		srcRect.x = 1600;
		xpos = SpriteManager::getCharacterXpos();
	}
	// if moving
	if (flag == 1) {
		srcRect.y = 0;
		// if step < 0, move left
		if (step <= 0) {
			srcRect.x = 1200;
		}
		// else moving right
		else {
			srcRect.x = 1600;
		}
		xpos = SpriteManager::getCharacterXpos() + step;
	}
	// if hit
	// show red
	if (flag == 2) {
		//std::cout << "HIT!" << std::endl;
		//lastPosition = srcRect.x;
		srcRect.y = srcRect.h*2;
		srcRect.x = srcRect.w*3;
	}
	// if dead
	if (flag == 3) {
		srcRect.y = srcRect.h*2;
		srcRect.x = 0;
	}
	// if block
	if (flag == 4) {
		srcRect.y = 0;
		srcRect.x = srcRect.w*2;
	}
	// if punch
	if (flag == 5) {
		srcRect.y = 0;
		srcRect.x = 0;
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
  //when the punch action flag is activated the below code captures the current time and renders the punch texture
  //for 2 seconds
  /*if(punchAction_flag ==1){
    int max = SDL_GetTicks()+2000;

    for(int i = SDL_GetTicks(); i < max; i++){
      std::cout << max << " " << i << std::endl;
      TextureManager::renderTexture(999, destRect.x-camera.x, destRect.y ,objTexture, &srcRect);
    }

      punchAction_flag=0;
  }
  else{
   TextureManager::renderTexture(999, destRect.x-camera.x, destRect.y ,objTexture, &srcRect);
 }*/
 TextureManager::renderTexture(999, destRect.x-camera.x, destRect.y ,objTexture, &srcRect);
   //std::cout << destRect.x-camera.x << ", " << destRect.y << std::endl;

   // ADDED BY KALEB
   // a poor workaround for timing of animations
   int ticks = SDL_GetTicks() / 500;
   if ((ticks) != lastSecond) {
   	srcRect.x = lastPosition;
   	lastSecond = ticks;
   }
}
