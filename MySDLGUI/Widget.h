#pragma once
#ifndef _WIDGET_H__
#define  _WIDGET_H__
#include <vector>
#include <SDL.h>
#include <map>
#include "config.h"
#include "Utilitys.h"
#include "RelativePos.h"

class Widget
{
private:
	int update;
	pos::relativepos corner;
	pos::relativepos quadrant;
	struct { float x; float y; float w; float h; } position;
	SDL_Rect abs_positon;
	std::multimap<int, DrawFunction> DrawFunc;
	std::multimap<SDL_EventType, EventFunction > EventFunc;
protected:
	Widget();
	Widget *parent;
	std::vector <Widget *> child;
public:
	~Widget();
	void RegisterFunc(int layer, DrawFunction func);
	void RegisterFunc(SDL_EventType type, EventFunction func);
	void SetFrameTimer(int interval, int num);
	void Draw(SDL_Renderer *render);
	bool HandleEvent(SDL_Event &event);
	virtual void DoDraw(SDL_Renderer *render) = 0;
	virtual bool DoHandleEvent(SDL_Event &event) = 0;
	const Widget & SetRelativePos(pos::relativepos _corner, pos::relativepos _quadrant);
	void SetPosition(const char* x,const char *y,const char* w,const char* h);
	void UpdatePos();
	friend void  TextureCopy(
		SDL_Renderer *,
		SDL_Texture *,
		SDL_Texture *,
		const SDL_Rect *,
		const SDL_Rect*
	);
	friend int main(int, char **);
	friend struct PluginLibrary;
};

#endif
