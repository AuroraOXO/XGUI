// MySDLGUI.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
SDL_Window *window;
SDL_Renderer *renderer;

int Init();

#define WIN_W 640
#define WIN_H 480

int main(int argc, char *argv[]) {
	if (Init() > 0)
	{
		SDL_Log("Init Error");
		return 1;
	}
	SDL_Event event;
	while ( true){
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			return 0;
	}
	atexit(SDL_Quit);
	return 0;
}

int Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return -1;
	}
	if (SDL_CreateWindowAndRenderer(WIN_W, WIN_H, SDL_WINDOW_RESIZABLE, &window, &renderer)<0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return -1;
	}

	return 0;
}

