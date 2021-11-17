#include "GameObject.h"

SDL_Rect cameraRect;

SpriteManager *spriteManager = NULL;



GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::initGameObject()
{
  spriteManager = new SpriteManager("assets/KK_MC.png",0,0);
}

void GameObject::updateGameObject(SDL_Rect& cameraRect){

  spriteManager-> updateSprite();
  GameObject::setCamera(cameraRect);
}



void GameObject::renderGameObject(SDL_Rect& cameraRect){

  spriteManager -> renderSprite(cameraRect);
}


void GameObject::setCamera( SDL_Rect& cameraRect )
{
    //Center the camera
    cameraRect.x = (spriteManager->getCharacterXpos() + 150 / 2) - SCREEN_WIDTH / 2;
    cameraRect.y = (spriteManager->getCharacterYpos() + 150 / 2) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds
    if(cameraRect.x < 0)
    {
        cameraRect.x = 0;
    }
    if(cameraRect.y < 0)
    {
        cameraRect.y = 0;
    }
    if(cameraRect.x > LEVEL_WIDTH - cameraRect.w)
    {
        cameraRect.x = LEVEL_WIDTH - cameraRect.w;
    }
    if(cameraRect.y > LEVEL_HEIGHT - cameraRect.h)
    {
        cameraRect.y = LEVEL_HEIGHT - cameraRect.h;
    }

}
