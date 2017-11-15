#pragma once
#ifndef __SURFACE_H__
#define __SURFACE_H__
#include "Widget.h"
class Surface :
	public Widget
{
public:
	SDL_Texture *drawboard;
	Surface();
	~Surface();
	virtual void DoDraw(SDL_Renderer *render);
};
#endif