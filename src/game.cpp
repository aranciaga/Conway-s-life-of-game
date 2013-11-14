#include "game.h"
#include <cstdlib>
#include <iostream>

SDL_Surface* screen;

int a=rand()%2;
void* data;

using namespace std;

int randomNumber;
int randomNumber2;

Uint32 colors[4] = {0xCC99FF,0x99CC33,0xCC6699,0xCC3333};

bool rainbowMode = false; //turn true it if you want to go crazy
 
void Game::initGraphics(){
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_WM_SetCaption("Conway's game of life", "Conway's game of life");
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 24,SDL_SWSURFACE);
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format,51,46,46));
}

void Game::checkNeighbors(){
	for(int i=1; i<SCREEN_WIDTH-1; i++){
		for(int j=1; j<SCREEN_HEIGHT-1; j++){
			int result = gameTable[i][j+1]+gameTable[i][j-1]+gameTable[i+1][j]+gameTable[i-1][j]+gameTable[i-1][j-1]+gameTable[i+1][j-1]+gameTable[i+1][j+1]+gameTable[i-1][j+1];
			if (gameTable[i][j]==0 && result==3){
				gameTableTMP[i][j] = 1; // born
			} else if(gameTable[i][j]>0 && result==2 || result==3){
				gameTableTMP[i][j] = 1;
			} else if(gameTable[i][j]>0 && result>=4){
				gameTableTMP[i][j] = 0;
			} else {
				gameTableTMP[i][j] = 0;
			}
		}
	}


	for(int i=1; i<SCREEN_WIDTH-1;i++){
		for(int j=1; j<SCREEN_HEIGHT-1; j++){
			gameTable[i][j] = gameTableTMP[i][j];
		}
	}


}

void Game::initBoard(){
	for(int i=0; i<SCREEN_WIDTH; i++){
		for(int j=0; j<SCREEN_HEIGHT; j++){
			 	randomNumber= (rand()%10)+1; 
				if (randomNumber<cellsLevel){
					gameTable[i][j] =  1;
				} else {
					gameTable[i][j] = 0;
				}
		}
	}
}

void Game::updateBoard(){	
	for(int i=0; i<SCREEN_WIDTH; i++){
		for(int j=0; j<SCREEN_HEIGHT; j++){
			if (gameTable[i][j]==1){
				randomNumber2 = (rand()%4)+1;
				SDL_Rect rect = {i*5,j*5,5,5};
				if (rainbowMode){
					SDL_FillRect(screen, &rect, colors[randomNumber2]);
				} else {
					SDL_FillRect(screen, &rect, 0x66FFCC);
				}
			} else {
				SDL_Rect rect = {i*5,j*5,5,5};
				SDL_FillRect(screen, &rect, 0x333366);
			}
		}
	}

	SDL_Flip(screen);
}