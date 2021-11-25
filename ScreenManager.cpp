#include "ScreenManager.h"

ScreenManager::ScreenManager(){
    state = 1;

}

void ScreenManager::initScreen(){
    SDL_Rect start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
    SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(GameEngine::renderer, &start);

    SDL_Texture* my_texture = NULL;
    SDL_Surface* temp = IMG_Load("assets/KK_MC.png");
    SDL_Rect src = {MC_IMG_SRC*6, 0, MC_IMG_SRC, MC_IMG_SRC};
    SDL_Rect dst = {150, 150, 100, 100};
    my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
    SDL_FreeSurface(temp);
    SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

    // reset
    SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
    
}

void ScreenManager::chanageState(int s){
    state = s;
}

int ScreenManager::getState(){
    return state;
}