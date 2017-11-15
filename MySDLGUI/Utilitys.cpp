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

inline void  TextureCopy(
	SDL_Renderer * ren,
	SDL_Texture * src,
	SDL_Texture * dest,
	const SDL_Rect *cut,
	const SDL_Rect* paste
	) throw (runtime_error)
{
	if (src == NULL)
		throw runtime_error("Source texture is invalid");

	SDL_SetRenderTarget(ren, dest);
	SDL_RenderCopy(ren, src, cut, paste);
	SDL_SetRenderTarget(ren, NULL);
}