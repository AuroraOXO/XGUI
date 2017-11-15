#pragma once
#ifndef __VIEW_H__
#define __VIEW_H__
#include "Widget.h"
class View :
	public Widget
{
public:
	View(SDL_Window *_win);
	~View();
protected:
	SDL_Window *windows;
	SDL_Renderer *renderer;
	void Show();
	void Show(SDL_Renderer*);
	virtual void DoDraw(SDL_Renderer *render);
	virtual bool DoHandleEvent(SDL_Event &event);
};
#endif