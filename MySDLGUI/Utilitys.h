#pragma once
#ifndef __UTILITY_H__
#define __UTILITY_H__
//#include <SDL.h>
#include <functional>

extern struct SDL_Point;
extern struct SDL_Rect;
extern struct SDL_Renderer;
extern struct SDL_Texture;
extern union SDL_Event;

using DrawFunction = std::function<void(SDL_Renderer *)>;
using EventFunction = std::function<bool(SDL_Event &)>;


struct  __f_position
{
	double x, y, w, h;
};

bool CheckColl(int px, int py, int rx, int ry, int rw, int rh);
bool CheckColl(const SDL_Point &p, const SDL_Rect &rect);
bool CheckColl(int px, int py, const SDL_Rect &rect);

void TextureCopy(
	SDL_Renderer * ren,
	SDL_Texture * src,
	SDL_Texture * dest=NULL,
	const SDL_Rect *cut=NULL,
	const SDL_Rect* paste=NULL
	
	) ;
	
SDL_Texture* CreateTexture(SDL_Renderer *render,int w, int h);

float GetDisplayDPI();
#endif