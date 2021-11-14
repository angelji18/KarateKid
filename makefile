all:
	g++ main.cpp GameEngine.cpp TextureManager.cpp GameObject.cpp TileMap.cpp SpriteManager.cpp `sdl2-config --cflags --libs` -lSDL2_image -std=c++11
