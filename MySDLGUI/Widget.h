#pragma once
#ifndef _WIDGET_H__
#define  _WIDGET_H__
#include <vector>
#include <SDL.h>
#include <assert.h>
#include <typeinfo>
#include "Utilitys.h"
#include "RelativePos.h"
using namespace std;
class Widget
{
private:
	pos::relativepos corner;
	pos::relativepos quadrant;
	
protected:
	SDL_Texture *drawboard;
	SDL_Texture *background;
	__f_position position;
	SDL_Rect rela_position;
	SDL_Rect abs_position;
	Widget *parent;
	vector <Widget *> child;
public:
	//SDL_Rect GetRelativePos();
	void UpdatePos();
	
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
	Widget();
	~Widget();
	SDL_Texture* GetDrawboard();
	const Widget & SetRelativePos(pos::relativepos _corner,pos::relativepos _quadrant) ;
	void Draw( SDL_Renderer *render);
	bool HandleEvent(SDL_Event &event);
	void AddChild(Widget *w);
	virtual void DoDraw(SDL_Renderer *render)=0;
	virtual bool DoHandleEvent(SDL_Event &event) = 0;

	friend void  TextureCopy(
		SDL_Renderer * ren,
		SDL_Texture * src,
		SDL_Texture * dest,
		const SDL_Rect *cut,
		const SDL_Rect* paste
		);
	friend int main(int ,char **);
};


#endif