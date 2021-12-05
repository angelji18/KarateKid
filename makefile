all:
	g++ main.cpp GameEngine.cpp TextureManager.cpp GameObject.cpp Enemy.cpp TileMap.cpp Spritemanager.cpp ScreenManager.cpp SoundManager.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer -std=c++11 -o KarateKid
