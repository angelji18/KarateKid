#include "TextureManager.h"


SDL_Texture* TextureManager::loadTexture(const char* texture){
  SDL_Surface*  imgAsSurface = IMG_Load(texture);
  SDL_Texture* imgAsTexture = SDL_CreateTextureFromSurface(GameEngine::renderer,imgAsSurface);
  SDL_FreeSurface(imgAsSurface);
  return imgAsTexture;
}


void TextureManager::renderTexture(int tiletype, int x, int y,SDL_Texture* texture, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, 150, 150 };


  if( clip != NULL )
  {
    if(tiletype == 999){
      //size of player charachter larger
      renderQuad.w = MC_IMG_DEST;
      renderQuad.h = MC_IMG_DEST;

    }
    else{ //bacckground smaller (150)
    renderQuad.w = 150;
    renderQuad.h = 150;
  }
}

  SDL_RenderCopy( GameEngine::renderer, texture, clip, &renderQuad);

	}
