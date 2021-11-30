#include "ScreenManager.h"

ScreenManager::ScreenManager(){
    state = 1;
}

// state 0 - no screen
// state 1 - start screen
// state 2 - end screen
void ScreenManager::chanageState(int s){
    state = s;
}

int ScreenManager::getState(){
    return state;
}

void ScreenManager::initScreen(){
    if(state == 1){
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
        temp = TTF_RenderText_Solid(font, "Karate  Kid", white);
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

}

void ScreenManager::endScreen(){
    if(state == 2){
        TTF_Init();
        SDL_Rect end = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
        SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(GameEngine::renderer, &end);

        SDL_Texture* my_texture = NULL;
        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 30);
        SDL_Color gold = {245, 200, 66};
        SDL_Surface* temp = TTF_RenderText_Solid(font, "Game Over!", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {175, 250, 500, 100};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);

        SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
        SDL_FreeSurface(temp);
    }
}

void ScreenManager::pauseScreen(){
    if(state == 3){
        TTF_Init();
        SDL_Rect end = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
        SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(GameEngine::renderer, &end);

        SDL_Texture* my_texture = NULL;
        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 30);
        SDL_Color gold = {245, 200, 66};
        SDL_Surface* temp = TTF_RenderText_Solid(font, "Game Paused!", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {175, 250, 500, 100};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);

        SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
        SDL_FreeSurface(temp);

        font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 15);
        SDL_Color white = {255, 255, 255};
        temp = TTF_RenderText_Solid(font, "Press Esc to Resume", white);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect text_dest = {100, 400, 600, 50};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &text_dest);
        SDL_FreeSurface(temp);
    }
}
