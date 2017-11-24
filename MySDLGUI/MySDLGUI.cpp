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

int Init();

int main(int argc, char *argv[]) {
	if (Init() <0)
	{
		SDL_Log("Init Error");
		return 1;
	}
	SDL_Event event;
	View v(window);
	Surface s(300,300,200,200);
	Surface s1(0.5,0.5,0.5,100);
	
	//s1.SetRelativePos(pos::bottom|pos::right,pos::bottom|pos::right);
	
//	v.AddChild(&s);
//	s.AddChild(&s1);
	
	//while (true)
	/*
	{
	clock_t t=clock();
	SDL_Rect r=s1.GetRelativePos();
	SDL_Log(":%d",clock()-t);
	SDL_Log("%d %d,%d %d",r.x,r.y,r.w,r.h);
	SDL_Delay(1000);
	}
	*/
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