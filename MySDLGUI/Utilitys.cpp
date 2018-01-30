#include "stdafx.h"
#include "Utilitys.h"
#include <SDL.h>
#include <exception>
#include <stdexcept>

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
		throw std::runtime_error("Source texture is invalid");

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

 float GetDisplayDPI() {
	 char value[10] = { 0 };
	 float dpi = 0;
#ifdef __ANDROID__
	 int(*__real_system_property_get)(const char *, char *) = NULL;

		 void *handle = SDL_LoadObject("libc.so");

		 if (!handle) {
			 SDL_Log("Cannot dlopen libc.so: %s. ", SDL_GetError());
			 return -1;
		 }
		 else {
			 __real_system_property_get = (int(*)(const char*, char*)) SDL_LoadFunction(handle, "__system_property_get");
		 }
		 if (!__real_system_property_get) {
			 SDL_Log("Load function failed: %s. ", SDL_GetError());
			 return -1;
		 }
		 (*__real_system_property_get) ("ro.sf.lcd_density", value);
 
	 //sscanf(value, "%f", &dpi);
	 dpi = SDL_atoi(dpi);
	 return dpi;
#endif
	 SDL_GetDisplayDPI(0, &dpi, NULL, NULL);
	 return dpi;

 }
