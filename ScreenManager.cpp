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
        SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
        TTF_Init();

        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
        SDL_Color white = {255, 255, 255};
        temp = TTF_RenderText_Solid(font, "Karate  Kid", white);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {200, 150, 500, 100};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);

        font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 15);
        SDL_Color gold = {245, 200, 66};
        temp = TTF_RenderText_Solid(font, "Press Enter to Start", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect text_dest = {100, 400, 600, 50};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &text_dest);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);
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

        SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);
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

        SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);

        font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 15);
        SDL_Color white = {255, 255, 255};
        temp = TTF_RenderText_Solid(font, "Press Esc to Resume", white);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect text_dest = {100, 400, 600, 50};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &text_dest);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);
    }
}

// ADDED BY KALEB
void ScreenManager::winScreen(){
    if(state == 4){
        TTF_Init();
        SDL_Rect end = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
        SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(GameEngine::renderer, &end);

        SDL_Texture* my_texture = NULL;
        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 30);
        SDL_Color gold = {245, 200, 66};
        SDL_Surface* temp = TTF_RenderText_Solid(font, "You Win!", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {175, 250, 500, 100};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);

        SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);
    }
}
  
// ADDED BY KALEB
void ScreenManager::displayHealth(int health) {
	TTF_Init();
	
	// render outline for health
	SDL_Rect outline = {10, 20, 300, 25};
	SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(GameEngine::renderer, &outline);
	
	// render health bar
        SDL_Rect bar = {10, 20, health*3, 25};
        SDL_SetRenderDrawColor(GameEngine::renderer, 255, 0, 0, 0);
        SDL_RenderFillRect(GameEngine::renderer, &bar);
        
        // render background for health text
        SDL_Rect text_background = {10, 0, 40, 20};
        SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(GameEngine::renderer, &text_background);
        
        // render health text
        SDL_Texture* my_texture = NULL;
        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 30);
        SDL_Color gold = {245, 200, 66};
        SDL_Surface* temp = TTF_RenderText_Solid(font, "HEALTH", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {15, 0, 25, 25};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
        
        // cleanup
        //SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
        SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);

        /*SDL_Texture* my_texture = NULL;
        TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 30);
        SDL_Color gold = {245, 200, 66};
        SDL_Surface* temp = TTF_RenderText_Solid(font, "Game Paused!", gold);
        my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
        SDL_Rect title_dest = {175, 250, 500, 100};
        SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);

        SDL_SetRenderDrawColor(GameEngine::renderer, 192, 238, 254, 1);
        SDL_FreeSurface(temp);
        TTF_CloseFont(font);*/
} 

void ScreenManager::introScreen(int sequence){

    SDL_Rect start;
    TTF_Font* font;
    SDL_Color white;
    SDL_Surface* temp;
    SDL_Texture* my_texture;
    SDL_Rect title_dest;
    SDL_Rect src;
    SDL_Rect dst;
    
    if(state == 5){
    	switch (sequence) {
    		case 0 :
    			start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
			SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(GameEngine::renderer, &start);


			// reset
			SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
			TTF_Init();

			font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
			white = {255, 255, 255};
			temp = TTF_RenderText_Solid(font, "One  beautiful  day . . .", white);
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			title_dest = {260, 300, 300, 50};
			SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
			SDL_FreeSurface(temp);
			TTF_CloseFont(font);
			
			break;
		case 1 :
			start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
			SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(GameEngine::renderer, &start);

			my_texture = NULL;
			temp = IMG_Load("assets/KK_MC_PROFILE1.png");
			src = {0, 0, MC_IMG_SRC, MC_IMG_SRC};
			dst = {225, 50, 300, 300};
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			SDL_FreeSurface(temp);
			SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

			// reset
			SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
			TTF_Init();

			font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
			white = {255, 255, 255};
			temp = TTF_RenderText_Solid(font, "What  a  lovely  day  to  go  to  the  park!", white);
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			title_dest = {260, 300, 300, 50};
			SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
			SDL_FreeSurface(temp);
			TTF_CloseFont(font);
			
			break;
		case 2 :
			start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
			SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(GameEngine::renderer, &start);

			my_texture = NULL;
			temp = IMG_Load("assets/KK_ENEMY_PROFILE.png");
			src = {0, 0, MC_IMG_SRC, MC_IMG_SRC};
			dst = {225, 50, 300, 300};
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			SDL_FreeSurface(temp);
			SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

			// reset
			SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
			TTF_Init();

			font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
			white = {255, 255, 255};
			temp = TTF_RenderText_Solid(font, "Not  so  fast!", white);
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			title_dest = {260, 300, 300, 50};
			SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
			SDL_FreeSurface(temp);
			TTF_CloseFont(font);
			
			break;
		case 3 :
			start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
			SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(GameEngine::renderer, &start);

			my_texture = NULL;
			temp = IMG_Load("assets/KK_BOSS_PROFILE2.png");
			src = {0, 0, MC_IMG_SRC, MC_IMG_SRC};
			dst = {225, 50, 300, 300};
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			SDL_FreeSurface(temp);
			SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

			// reset
			SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
			TTF_Init();

			font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
			white = {255, 255, 255};
			temp = TTF_RenderText_Solid(font, "Go  away  kid!", white);
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			title_dest = {260, 300, 300, 50};
			SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
			SDL_FreeSurface(temp);
			TTF_CloseFont(font);
			
			break;
			
		case 4 :
			start = {50, 50, SCREEN_WIDTH-100, SCREEN_HEIGHT-100};
			SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(GameEngine::renderer, &start);

			my_texture = NULL;
			temp = IMG_Load("assets/KK_MC_PROFILE_MAD.png");
			src = {0, 0, MC_IMG_SRC, MC_IMG_SRC};
			dst = {225, 50, 300, 300};
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			SDL_FreeSurface(temp);
			SDL_RenderCopy(GameEngine::renderer, my_texture, &src, &dst);

			// reset
			SDL_SetRenderDrawColor(GameEngine::renderer, 45, 180, 243, 1);
			TTF_Init();

			font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 50);
			white = {255, 255, 255};
			temp = TTF_RenderText_Solid(font, "OH!", white);
			my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
			title_dest = {260, 300, 300, 50};
			SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &title_dest);
			SDL_FreeSurface(temp);
			TTF_CloseFont(font);
			
			break;
			
    	}

    }
}

void ScreenManager::displayScore(int score){
    TTF_Init();

    SDL_Color white = {255, 255, 255};
    SDL_Texture* my_texture = NULL;
    TTF_Font* font = TTF_OpenFont("assets/arcadeclassic.regular.ttf", 20);
    std::string s = "Score " + std::to_string(score);
    char const *text = s.c_str();
    SDL_Surface* temp = TTF_RenderText_Solid(font, text, white);
    my_texture = SDL_CreateTextureFromSurface(GameEngine::renderer, temp);
    SDL_Rect score_dest = {650, 10, 140, 40};
    SDL_RenderCopy(GameEngine::renderer, my_texture, NULL, &score_dest);

    SDL_FreeSurface(temp);
    TTF_CloseFont(font);
    
}


















