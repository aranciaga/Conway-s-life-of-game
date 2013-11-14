#include "game.h"
#include <iostream>
Game c;
using namespace std;
SDL_Event event;

bool life = true;

Uint32 doSomething(Uint32 interval, void *parm)
{
	c.checkNeighbors();
    char *msg;
    if(parm)
        msg = (char *)parm;
    cout << msg << endl;
    return interval;
}


int main(){
	c.initGraphics();
	c.initBoard();
	SDL_TimerID timer_id = SDL_AddTimer(300,doSomething,(void *)"Updating screen");
	while(life){
		c.updateBoard();
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				life=false;
			}
		}
	}
	SDL_Quit();
	return 0;
}