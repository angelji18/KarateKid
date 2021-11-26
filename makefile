all:
	g++ main.cpp GameEngine.cpp TextureManager.cpp GameObject.cpp TileMap.cpp SpriteManager.cpp ScreenManager.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -std=c++11
