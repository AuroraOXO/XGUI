#pragma once
#ifndef _WIDGET_H__
#define  _WIDGET_H__
#include <vector>
#include <SDL.h>
#include <assert.h>
#include "Utilitys.h"
#include "RelativePos.h"
using namespace std;
class Widget
{
public:
	
protected:
	SDL_Texture *background;
	__f_position position;
	pos::relativepos corner;
	pos::relativepos quadrant;
	Widget *parent;
	vector <Widget *> child;
	Widget();
	~Widget();
	const Widget & SetRelavitePos(pos::relativepos _corner,pos::relativepos _quadrant) ;
	void SetPos(int x, int y, int w, int h);
	void SetPos(float x, float y, float w, float h);
	SDL_Rect GetAbsPos();
	void Draw( SDL_Renderer *render);
	bool HandleEvent(SDL_Event &event);
	virtual void DoDraw(SDL_Renderer *render)=0;
	virtual bool DoHandleEvent(SDL_Event &event) = 0;
	friend void  TextureCopy(
		SDL_Renderer * ren,
		SDL_Texture * src,
		SDL_Texture * dest,
		const SDL_Rect *cut,
		const SDL_Rect* paste
		);
};

#endif