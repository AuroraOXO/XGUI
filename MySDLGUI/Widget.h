#pragma once
#ifndef _WIDGET_H__
#define  _WIDGET_H__
#include <vector>
#include <SDL.h>
#include <assert.h>
#include "Utilitys.h"
#include "RelativePos.h"
using namespace std;
class Widget
{
private:
	pos::relativepos corner;
	pos::relativepos quadrant;
	
	void (*__RowFun)(Widget *);
	void (*__ColFun)(Widget *);
	void __SetFun();
	
protected:
	SDL_Texture *drawboard;
	SDL_Texture *background;
	__f_position position;
	SDL_Rect rela_position;
	SDL_Rect abs_position;
	Widget *parent;
	vector <Widget *> child;
public:
	SDL_Rect GetRelativePos();
	SDL_Rect GetAbsPos();
	
public:
template <class A,class B ,class C,class D>
	void SetPos(A x, B y, C w, D h){
	position={(double )x,(double )y,(double )w,(double )h};
	if (typeid(x)==typeid(int))
	position.x+=0.1;
	
	if (typeid(y)==typeid(int))
	position.y+=0.1;
	
	if (typeid(w)==typeid(int))
	position.w+=0.1;
	
	if (typeid(h)==typeid(int))
	position.h+=0.1;
	}
	
	const Widget & SetRelativePos(pos::relativepos _corner,pos::relativepos _quadrant) ;
	void Draw( SDL_Renderer *render);
	bool HandleEvent(SDL_Event &event);
	void AddChild(Widget *w);
	virtual void DoDraw(SDL_Renderer *render)=0;
	virtual bool DoHandleEvent(SDL_Event &event) = 0;
	Widget();
	~Widget();
	friend void  TextureCopy(
		SDL_Renderer * ren,
		SDL_Texture * src,
		SDL_Texture * dest,
		const SDL_Rect *cut,
		const SDL_Rect* paste
		);
		/*
	static void __TopLeftFun(Widget* w);
	static void __TopRightFun(Widget *w);
	static void __BottomLeft(Widget *w);
	static void __BottomRight(Widget* w);
	
	static void __TopTopFun(Widget *w);
	static void __TopBottomFun(Widget *w);
	static void __LeftLeftFun(Widget *w);
	static void __LeftRightFun(Widget *w);
	static void __BottomBottomFun(Widget *w);
	static void __BottomTopFun(Widget *w);
	static void __RightRightFun(Widget *w);
	static void __RightLeftFun(Widget *w);
	*/
};


#endif