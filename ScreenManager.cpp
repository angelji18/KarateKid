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
    SDL_Rect dst = {100, 150, 100, 100};
    my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
    SDL_FreeSurface(temp);
    SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

    // reset
    SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
    TTF_Init();

    TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
    SDL_Color white = {255, 255, 255};
    temp = TTF_RenderText_Solid(font, "KarateKid", white);
    my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
    SDL_Rect title_dest = {200, 150, 500, 100};
    SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
    SDL_FreeSurface(temp);

    font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 15);
    SDL_Color gold = {245, 200, 66};
    temp = TTF_RenderText_Solid(font, "Press Enter to Start", gold);
    my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
    SDL_Rect text_dest = {100, 400, 600, 50};
    SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &text_dest);
    SDL_FreeSurface(temp);
    
}

void ScreenManager::chanageState(int s){
    state = s;
}

int ScreenManager::getState(){
    return state;
}