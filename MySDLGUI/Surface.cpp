#include "stdafx.h"
#include "Surface.h"

Surface::~Surface()
{
}

void Surface::DoDraw(SDL_Renderer *render) {

	if (drawboard == NULL&&position.w>0&&position.h>0) 
		drawboard=CreateTexture(render,rela_position.w, rela_position.h);
	if (background != NULL)
		TextureCopy(render, background, drawboard, NULL, NULL);
}

bool Surface::DoHandleEvent(SDL_Event& event) {

	return false;
}
