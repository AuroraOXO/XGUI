#include "stdafx.h"
#include "Utilitys.h"
bool CheckColl(int px, int py, int rx, int ry, int rw, int rh)
{
	return ((px - rx) >= 0 && (px - rx)<rw && (py - ry) >= 0 && (py - ry)<rh) ? true : false;

}

bool CheckColl(const SDL_Point &p, const SDL_Rect &rect)
{
	return CheckColl(p.x, p.y, rect.x, rect.y, rect.w, rect.h);
}

bool CheckColl(int px, int py, const SDL_Rect &rect)
{
	return CheckColl(px, py, rect.x, rect.y, rect.w, rect.h);
}

 void  TextureCopy(

	SDL_Renderer * ren,
	SDL_Texture * src,
	SDL_Texture * dest,
	const SDL_Rect *cut,
	const SDL_Rect* paste
	) 
{
	
	if (src == NULL)
		throw runtime_error("Source texture is invalid");

	SDL_SetRenderTarget(ren, dest);
	SDL_RenderCopy(ren, src, cut, paste);
	SDL_SetRenderTarget(ren, NULL);
	
}
 SDL_Texture* CreateTexture(SDL_Renderer *render,int w, int h) {

	 SDL_Texture * tmpT;
	 tmpT = SDL_CreateTexture(render,
		 SDL_PIXELFORMAT_RGBA8888,
		 SDL_TEXTUREACCESS_TARGET, w, h);
	 SDL_SetTextureBlendMode(tmpT, SDL_BLENDMODE_BLEND);

	 SDL_SetRenderTarget(render, tmpT);
	 SDL_RenderClear(render);
	 SDL_SetRenderTarget(render, NULL);
	 return tmpT;
 }