#pragma once
#ifndef __SURFACE_H__
#define __SURFACE_H__
#include "Widget.h"
class Surface :
	public Widget
{

public:
	SDL_Texture *drawboard;
	
	template <class A1,class B1 ,class C1,class D1>
    Surface(A1 x,B1 y,C1 w,D1 h){
		SDL_Log("surface");
		SetPos(x,y,w,h);
	}
	~Surface();
	virtual void DoDraw(SDL_Renderer *render);
	virtual bool DoHandleEvent(SDL_Event &event);
	
};

#endif