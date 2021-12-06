#include "TileMap.h"

//1-sky,2-plant,3-rock,4-cloud,5-ground

int lvl1[4][25]={
  {4,1,1,4,4,1,1,1,1,4,1,1,1,4,1,1,1,4,1,4,4,1,1,1,4},
  {1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,4,1,4,1},
  {1,1,2,1,1,2,1,1,3,2,2,1,1,3,1,1,1,1,2,1,3,1,3,2,1},
  {5,6,5,6,5,6,5,6,5,6,5,6,5,6,5,6,5,6,5,6,5,6,5,6,5},
};

TileMap::TileMap(){
  tileMapTexture = TextureManager::loadTexture("EnvTiles.png");
  loadTileMap(lvl1);
  //std::cout << lvl1 << '\n';
  srcRect.w = 400;
  srcRect.h = 400;
}


TileMap::~TileMap(){


}

void TileMap::loadTileMap(int arr[4][25]){
  for(int row = 0 ; row <4; row++){
    for(int col =0 ;col <25 ;col++){
      map[row][col] = arr[row][col];
    }
  }
}

void TileMap::drawTileMap(SDL_Rect& cameraRect){
  int tiletype = 1;
  for(int row = 0 ; row <4; row++){
    for(int col =0 ;col <25 ;col++){
      tiletype = map[row][col];

      destRect.x = col*150; //position of the destRect will be (current col x width per tile)
      destRect.y = row*150;



      switch(tiletype){

        case 1:
          srcRect.x=800;
          srcRect.y=0;

          TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
        break;
        case 2:
          srcRect.x=400;
          srcRect.y=400;

          TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
        break;
        case 3:
          srcRect.x=800;
          srcRect.y=400;

          TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
        break;
        case 4:
          srcRect.x=0;
          srcRect.y=400;

          TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
        break;
        case 5:
          srcRect.x=0;
          srcRect.y=0;

          TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
        break;
          case 6:
            srcRect.x=400;
            srcRect.y=0;

            TextureManager::renderTexture(tiletype, destRect.x-cameraRect.x, destRect.y,tileMapTexture, &srcRect);
          break;

      }

    }
  }

}
