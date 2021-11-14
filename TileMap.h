#ifndef  _TILEMAP_H_
#define _TILEMAP_H_

#include "GameEngine.h"


class TileMap{
  public:
    TileMap();
    ~TileMap();

    void loadTileMap(int arr[4][25]);
    void drawTileMap(SDL_Rect& cameraRect);


  private:

    SDL_Rect srcRect ,destRect;
    SDL_Texture* tileMapTexture;
    int map[4][25];


};

#endif
