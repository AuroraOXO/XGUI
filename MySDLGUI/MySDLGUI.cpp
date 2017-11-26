// MySDLGUI.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "View.h"
#include "Surface.h"
#ifdef __ANDROID__
extern int Android_ScreenWidth;
extern int Android_ScreenHeight;
#define WIN_W  Android_ScreenWidth
#define WIN_H  Android_ScreenHeight
#else
#define WIN_W 640
#define WIN_H 480
#endif

SDL_Window *window;
SDL_Renderer *renderer;

int Init();

int main(int argc, char *argv[]) {

	if (Init() <0)
	{
		SDL_Log("Init Error");
		return 1;
	}
	View v(window);
	Surface sur(0.5,0.5,300,300);
	Surface s1(0.2, 0.2, 0.2, 0.2);

	v.AddChild(&sur);
	sur.AddChild(&s1);
	//s1.SetRelativePos(pos::top,pos::top);
	sur.UpdatePos();
	SDL_Log("%d %d %d %d ",sur.rela_position.x, sur.rela_position.y, sur.rela_position.w, sur.rela_position.h);
	SDL_Log("%d %d %d %d ", s1.rela_position.x, s1.rela_position.y, s1.rela_position.w, s1.rela_position.h);
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

