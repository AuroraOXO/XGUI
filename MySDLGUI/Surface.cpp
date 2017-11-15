#include "stdafx.h"
#include "Surface.h"


Surface::Surface()
{
}


Surface::~Surface()
{
}

void Surface::DoDraw(SDL_Renderer *render) {
	if (drawboard == NULL&&position.w>0&&position.h>0) {
		drawboard = SDL_CreateTexture(render,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, position.w, position.h);
		SDL_SetTextureBlendMode(drawboard, SDL_BLENDMODE_BLEND);
	
		SDL_SetRenderTarget(render, drawboard);
		SDL_RenderClear(render);
		SDL_SetRenderTarget(render, NULL);
	}
}