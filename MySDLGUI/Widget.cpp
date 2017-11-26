 #include "stdafx.h"
#include "Widget.h"
#include<typeinfo>
#include <exception>

Widget::Widget() :
	parent(NULL),
	corner(pos::top | pos::left),
	quadrant(pos::bottom | pos::right)
{
	position = { 0 };
	rela_position = { 0 };
	abs_position = { 0 };
	SDL_Log("Widget");
}


Widget::~Widget()
{
}

void Widget::AddChild(Widget *w){
	child.push_back(w);
	w->parent=this;
}

void Widget::Draw(SDL_Renderer *render) {
	if (rela_position.w <= 0)
		UpdatePos();
	DoDraw(render);
	for (size_t i = 0; i < child.size(); i++) {
		child[i]->Draw(render);
	}
	
	if (drawboard != NULL) {
	TextureCopy(render, drawboard, parent ? parent->drawboard : NULL, NULL, &rela_position);
}
}
bool Widget::HandleEvent(SDL_Event &event) {
	return false;
}

const Widget & Widget::SetRelativePos(pos::relativepos _corner, pos::relativepos _quadrant) {
	corner = _corner;
	quadrant = _quadrant;
	return *this;
}

void Widget::SetBackground(SDL_Texture* bg) {
	background = bg;
}

void Widget::UpdatePos() {
	abs_position= rela_position = {
		(int)position.x,
		(int)position.y
		,(int)position.w,
		(int)position.h };
	SDL_Rect Pa = { 0 };
	SDL_Rect GPa = { 0 };
	if (parent == NULL)
		goto loop;

	Pa = parent->rela_position;

	if (!(corner & quadrant)) {
		if (corner& pos::top) {
			if (position.y <= 1)
				rela_position.y = Pa.h*position.y;
			if (position.h <= 1)
				rela_position.h = Pa.h*position.h;
		}

		if (corner&pos::bottom) {
			rela_position.y = Pa.h - position.h - position.y;
			if (position.h <= 1)
				rela_position.h = Pa.h*position.h;
			if (position.y <= 1)
				rela_position.y = Pa.h - rela_position.h - Pa.h*position.y;
		}
		if (corner&pos::left) {
			if (position.x <= 1)
				rela_position.x = Pa.w*position.x;
			if (position.w <= 1)
				rela_position.w = Pa.w*position.w;
		}
		if (corner&pos::right) {
			rela_position.x = Pa.w - position.w - position.x;
			if (position.x <= 1)
				rela_position.x = Pa.w - rela_position.w - (Pa.w*position.x);
			if (position.w <= 1)
				rela_position.w = Pa.w*position.w;
		}
		abs_position = { parent->abs_position.x + rela_position.x,parent->abs_position.y + rela_position.y,rela_position.w,rela_position.h };
		SDL_Log("in rectangle");
		
		goto loop;
	}
	
	SDL_Log("out");

	if (parent->parent == NULL) {
		throw runtime_error("Grandfather is NULL");
	}
	GPa = parent->parent->rela_position;

	if (corner & pos::top) {

		if (quadrant & pos::top) {
			if (position.h <= 1)
				rela_position.h = Pa.y * position.h;
			if (position.y>1)
				rela_position.y = Pa.y - rela_position.h - position.y;
			else
				rela_position.y = (1 - position.y) * (Pa.y);
		}

		if (quadrant & pos::bottom) {
			if (position.h <= 1)
				rela_position.h = (GPa.h - Pa.y) * position.h;
			if (position.y>1)
				rela_position.y = Pa.y + position.y;
			else
				rela_position.y = Pa.y + (GPa.h - Pa.y) * position.y;
		}
	}

	if (corner & pos::left) {
		if (quadrant & pos::left) {
			if (position.w <= 1)
				rela_position.w = Pa.x * position.w;

			if (position.x>1)
				rela_position.x = Pa.x - rela_position.w - position.x;
			else
				rela_position.x = (1 - position.x) * (Pa.x);

		}

		if (quadrant & pos::right) {
			if (position.w <= 1)
				rela_position.w = (GPa.w - Pa.x) * position.w;
			if (position.x>1)
				rela_position.x = Pa.x + position.x;
			else
				rela_position.x = Pa.x + (GPa.w - Pa.x) * position.x;
		}
	}

	if (corner & pos::bottom) {
		if (quadrant & pos::bottom) {
			if (position.h <= 1)
				rela_position.h = (GPa.h - Pa.x - Pa.h)*position.h;

			if (position.y>1)
				rela_position.h = Pa.y + Pa.h + position.y;
			else
				rela_position.y = Pa.y + Pa.h + (GPa.h - Pa.y - Pa.h) * position.y;

		}

		if (quadrant & pos::top) {
			if (position.h <= 1)
				rela_position.h = (Pa.h + Pa.y) * position.h;
			if (position.y>1)
				rela_position.y = Pa.y + Pa.h - rela_position.h - position.y;
			else
				rela_position.y = (Pa.y + Pa.h) * (1 - position.y);
		}
	}

	if (corner & pos::right) {
		if (quadrant & pos::right) {
			if (position.w <= 1)
				rela_position.w = (GPa.w - Pa.w - Pa.x) * position.w;
			if (position.x>1)
				rela_position.x = Pa.x + Pa.w + position.x;
			else
				rela_position.x = Pa.x + Pa.w + (GPa.w - Pa.w - Pa.x) * position.x;
		}

		if (quadrant & pos::left) {
			if (position.w <= 1)
				rela_position.w = (Pa.w + Pa.x) * position.w;
			if (position.x>1)
				rela_position.x = Pa.w + Pa.x - rela_position.w - position.x;
			else
				rela_position.x = (Pa.w + Pa.x) * (1 - position.x);
		}
	}

	abs_position = {parent->parent->abs_position.x + rela_position.x,parent->parent->abs_position.y + rela_position.y,rela_position.w,rela_position.h };

	loop:
	for (size_t i = 0; i<child.size(); i++) {
		child[i]->UpdatePos();
	}

}