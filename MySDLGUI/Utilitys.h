#pragma once
#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <SDL.h>
#include <exception>
#include <stdexcept>
using namespace std;

struct  __f_position
{
	float x, y, w, h;
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
	
#endif