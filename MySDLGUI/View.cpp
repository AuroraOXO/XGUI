#include "stdafx.h"
#include "View.h"


View::View(SDL_Window *_win)
{
	int _w,_h;
	SDL_GetWindowSize(_win,&_w,&_h);
	position={0,0,_w+0.1,_h+0.1};
}


View::~View()
{
}

void View::DoDraw(SDL_Renderer *render) {


}
bool View::DoHandleEvent(SDL_Event &event) {
	return false;
}