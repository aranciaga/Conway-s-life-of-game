#include <SDL/SDL.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 400
#define cellsLevel 4 // 1-10. 1=null, 10=max

class Game{
	public:
		int gameTable[SCREEN_WIDTH][SCREEN_HEIGHT];
		int gameTableTMP[SCREEN_WIDTH][SCREEN_HEIGHT];
		void initGraphics();
		void updateBoard();
		void initBoard();
		void checkNeighbors(); 
};