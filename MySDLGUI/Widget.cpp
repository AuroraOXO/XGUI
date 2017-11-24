#include "stdafx.h"
#include "Widget.h"
#include<typeinfo>
#include <exception>

Widget::Widget() :
	parent(NULL),
	corner(pos::top | pos::left),
	quadrant(pos::bottom | pos::right)
{
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
	if (background!=NULL)
TextureCopy(render,background,drawboard,NULL,NULL);
DoDraw(render);
if (false==child.empty()){
	for (size_t i=0;i<child.size();i++)
	child[i]->Draw(render);
	//copy to drawboard
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

void Widget::UpdatePos() {
	
}

SDL_Rect Widget::GetRelativePos(){
	
	SDL_Rect _tPos={
		(int)position.x,
		(int)position.y
		,(int)position.w,
		(int)position.h};
	SDL_Rect Pa={0};
	SDL_Rect GPa={0};
	if (parent==NULL)
	return _tPos;
	
	Pa=parent->GetRelativePos();
	
if (corner==(pos::top|pos::left)&&(quadrant==pos::bottom|pos::right))
	{
		if (position.x<=1)
		_tPos.x=Pa.w*position.x;
		if (position.y<=1)
		_tPos.y=Pa.h*position.y;
		if (position.w<=1)
		_tPos.w=Pa.w*position.w;
		if (position.h<=1)
		_tPos.h=Pa.h*position.h;
		return _tPos;
	}
	
	if (corner==(pos::bottom|pos::left)&&(quadrant==pos::top|pos::right)){
		_tPos.y=Pa.h-position.h-position.y;
		
		if (position.w<=1)
		_tPos.w=Pa.w*position.w;
		if (position.h<=1)
		_tPos.h=Pa.h*position.h;
		if (position.x<=1)
		_tPos.x=Pa.w*position.x;
		if (position.y<=1)
		_tPos.y=Pa.h-_tPos.h-Pa.h*position.y;
		
		return _tPos;
	}
	
	if (corner==(pos::top|pos::right)&&quadrant==(pos::bottom|pos::left)){
		
		_tPos.x=Pa.w-position.w-position.x;
		_tPos.y=position.y;
		
		if (position.w<=1)
		_tPos.w=Pa.w*position.w;
		if (position.h<=1)
		_tPos.h=Pa.h*position.h;
		
		if (position.x<=1)
		_tPos.x=Pa.w-_tPos.w-(Pa.w*position.x);
		if (position.y<=1)
		_tPos.y=Pa.h*position.y;
		return _tPos;
	}
	if (corner==(pos::bottom|pos::right)&&quadrant==(pos::top|pos::left)){
		
		_tPos.x=Pa.w-position.w-position.x;
		_tPos.y=Pa.h-position.h-position.y;
		
		if (position.w<=1)
		_tPos.w=Pa.w*position.w;
		if (position.h<=1)
		_tPos.h=Pa.h*position.h;
		
		if (position.x<=1)
		_tPos.x=Pa.w-_tPos.w-(Pa.w*position.x);
		if (position.y<=1)
		_tPos.y=Pa.h-_tPos.h-Pa.h*position.y;
		return _tPos;
	}
	
	if (parent->parent==NULL){
		throw runtime_error("Grandfather is NULL");
	}
	GPa=parent->parent->GetRelativePos();
	
  if (corner & pos::top) {
  	
    if (quadrant & pos::top) {
    	if (position.h<=1)
      _tPos.h = Pa.y * position.h;
      if (position.y>1)  
     _tPos.y=Pa.y-_tPos.h-position.y ;
      else
      _tPos.y = (1 - position.y) * (Pa.y);
    }
    
    if (quadrant & pos::bottom) {
    	if (position.h<=1)
      _tPos.h = (GPa.h - Pa.y) * position.h;
      if (position.y>1)
    	_tPos.y=Pa.y+position.y;
    	else
      _tPos.y = Pa.y + (GPa.h - Pa.y) * position.y;
    }
  }

  if (corner & pos::left) {
    if (quadrant & pos::left) {
    	if (position.w<=1)
      _tPos.w = Pa.x * position.w;
      
      if (position.x>1)
    	_tPos.x=Pa.x-_tPos.w-position.x;
    	else
      _tPos.x = (1 - position.x) * (Pa.x);
      
    }
    
    if (quadrant & pos::right) {
    	if (position.w<=1)
      _tPos.w = (GPa.w - Pa.x) * position.w;
      if (position.x>1)
    	_tPos.x=Pa.x+position.x;
    	else
      _tPos.x = Pa.x + (GPa.w - Pa.x) * position.x;
    }
  }
  
  if (corner & pos::bottom) {
    if (quadrant & pos::bottom) {
    	if (position.h<=1)
      _tPos.h = (GPa.h-Pa.x-Pa.h)*position.h ;
  
      if (position.y>1)
    	_tPos.h=Pa.y+Pa.h+position.y;
    	else
      _tPos.y =Pa.y + Pa.h + (GPa.h - Pa.y - Pa.h) * position.y;
      
    }
    
    if (quadrant & pos::top) {
    	if (position.h<=1)
      _tPos.h = (Pa.h +Pa.y) * position.h;
      if (position.y>1)
    	_tPos.y=Pa.y+Pa.h-_tPos.h-position.y;
    	else
      _tPos.y = (Pa.y + Pa.h) * (1 - position.y);
    }
  }
  
  if (corner & pos::right) {
    if (quadrant & pos::right) {
    	if (position.w<=1)
      _tPos.w = (GPa.w - Pa.w - Pa.x) * position.w;
      if (position.x>1)
    	_tPos.x=Pa.x+Pa.w+position.x;
    	else
      _tPos.x = Pa.x + Pa.w + (GPa.w - Pa.w - Pa.x) * position.x;
    }
    
    if (quadrant & pos::left) {
    	if (position.w<=1)
      _tPos.w = (Pa.w + Pa.x) * position.w;
      if (position.x>1)
    	_tPos.x=Pa.w+Pa.x-_tPos.w-position.x;
    	else
      _tPos.x = (Pa.w + Pa.x) * (1 - position.x);
    }
  }
 
	return _tPos;
	
}
	