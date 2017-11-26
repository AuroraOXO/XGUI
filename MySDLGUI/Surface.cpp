#include "stdafx.h"
#include "Surface.h"

Surface::~Surface()
{
}

void Surface::DoDraw(SDL_Renderer *render) {
	SDL_Rect pos;
	if (drawboard == NULL&&position.w>0&&position.h>0) {
		drawboard=CreateTexture(render,rela_position.w, rela_position.h);
	}
	
}

bool Surface::DoHandleEvent(SDL_Event& event) {

	return false;
}
