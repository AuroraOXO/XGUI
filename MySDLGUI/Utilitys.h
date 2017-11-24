#pragma once
#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <SDL.h>
#include <exception>
#include <stdexcept>

using namespace std;

struct  __f_position
{
	double x, y, w, h;
};

bool CheckColl(int px, int py, int rx, int ry, int rw, int rh);
bool CheckColl(const SDL_Point &p, const SDL_Rect &rect);
bool CheckColl(int px, int py, const SDL_Rect &rect);

void TextureCopy(
	SDL_Renderer * ren,
	SDL_Texture * src,
	SDL_Texture * dest=NULL,
	const SDL_Rect *cut=NULL,
	const SDL_Rect* paste=NULL
	
	) ;
	
	/*
	template<class  _T1>
	void __TopTopFun(_T1* w){
		if (w->position.h<=1);
   w->rela_position.h ;
   w->parent->position.x;
   // P.x;
    // w->position.h;
      
      if (w->position.y>1)  
     w->rela_position.y=P.y-w->rela_position.h-w->position.y ;
      else
    w->rela_position.y = (1 - w->position.y) * (P.y);
    
	}

	template<class _T2>
	void __TopBottomFun(_T2 w)
	{
    	if (position.h<=1)
      rela_position.h = (GP.h - P.y) * position.h;
      if (position.y>1)
    	rela_position.y=P.y+position.y;
    	else
      rela_position.y = P.y + (GP.h - P.y) * position.y;
    
	}
	
	template<class _T3>
	void __LeftLeftFun(_T3 w){
		
		if (position.w<=1)
      rela_position.w = P.x * position.w;
  
      if (position.x>1)
    	rela_position.x=P.x-rela_position.w-position.x;
    	else
      rela_position.x = (1 - position.x) * (P.x);
	}
	
	template<class _T4>
	
	void __LeftRightFun(_T4 w){
		if (position.w<=1)
      rela_position.w = (GP.w - P.x) * position.w;
      if (position.x>1)
    	rela_position.x=P.x+position.x;
    	else
      rela_position.x = P.x + (GP.w - P.x) * position.x;
	}
	
	template<class _T5>
	void __BottomBottom(_T5 w){
		
		if (position.h<=1)
      rela_position.h = (GP.h-P.x-P.h)*position.h ;
  
      if (position.y>1)
    	rela_position.h=P.y+P.h+position.y;
    	else
      rela_position.y =P.y + P.h + (GP.h - P.y - P.h) * position.
		
	}
	
	template<class _T6>
	void __BottomTop(_T6 w){
		
		if (position.h<=1)
      rela_position.h = (P.h + P.y) * position.h;
      if (position.y>1)
    	rela_position.y=P.y+P.h-rela_position.h-position.y;
    	else
      rela_position.y = (P.y + P.h) * (1 - position.y);
		
	}
	
	template<class _T7>
	void __RightRight(_T7 w){
		if (position.w<=1)
      rela_position.w = (GP.w - P.w - P.x) * position.w;
      if (position.x>1)
    	rela_position.x=P.x+P.w+position.x;
    	else
      rela_position.x = P.x + P.w + (GP.w - P.w - P.x) * position.x;
	}
	
	template<class _T8>
	void __RightLeft(_T8 w){
		if (position.w<=1)
      rela_position.w = (P.w + P.x) * position.w;
      if (position.x>1)
    	rela_position.x=P.w+P.x-rela_position.w-position.x;
    	else
      rela_position.x = (P.w + P.x) * (1 - position.x);
		
	}
	*/
#endif