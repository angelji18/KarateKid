#include "ScreenManager.h"

ScreenManager::ScreenManager(){
    state = 1;

}

void ScreenManager::initScreen(){
    SDL_Rect start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
    SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(GameEngine::renderer, &start);
    SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
    
}

void ScreenManager::chanageState(int s){
    state = s;
}

int ScreenManager::getState(){
    return state;
}