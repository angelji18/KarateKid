#ifndef  _TEXTUREMANGER_H_
#define _TEXTUREMANGER_H_

#include "GameEngine.h"

class TextureManager{

  public:

    static SDL_Texture* loadTexture(const char* filename);

    static void renderTexture(int tiletype, int x, int y,SDL_Texture* texture, SDL_Rect* clip );
};

#endif
