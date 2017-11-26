#include "stdafx.h"
#include "View.h"


View::View(SDL_Window *_win)
{
	SDL_GetWindowSize(_win,&rela_position.w,&rela_position.h);
	renderer=SDL_GetRenderer(_win);
	abs_position = rela_position;
	 position={0,0,rela_position.w+0.1,rela_position.h+0.1};
}


View::~View()
{
}

void View::DoDraw(SDL_Renderer *render) {


}
bool View::DoHandleEvent(SDL_Event &event) {
	return false;
}

void View::Show() {
	Draw(renderer);
}