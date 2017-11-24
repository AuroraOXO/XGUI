#include "stdafx.h"
#include "Widget.h"
#include<typeinfo>
#include <exception>
#define P w->parent->position
#define GP w->parent->parent->position

Widget::Widget():
parent(NULL),
corner(pos::top|pos::left),
quadrant(pos::bottom|pos::right)
{
	
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
/*
void Widget::__SetFun(){
	
	 if (corner & pos::top) {
  	
    if (quadrant & pos::top) {
    	__ColFun=__TopTopFun;
    }
    
    if (quadrant & pos::bottom) {
    	__ColFun=__TopBottomFun;
    }
  }

  if (corner & pos::left) {
    if (quadrant & pos::left) {
    	__RowFun=__LeftLeftFun;
    }
    
    if (quadrant & pos::right) {
    	__RowFun=__LeftRightFun;
    }
  }
  
  if (corner & pos::bottom) {
    if (quadrant & pos::bottom) {
    	__ColFun=__BottomBottomFun;
    }
    
    if (quadrant & pos::top) {
    	__ColFun=__BottomTopFun;
    }
  }
  
  if (corner & pos::right) {
    if (quadrant & pos::right) {
    	__RowFun=__RightRightFun;
    }
    
    if (quadrant & pos::left) {
    	__RowFun=__RightLeftFun;
    }
  }
	
}
*/
const Widget & Widget::SetRelativePos(pos::relativepos _corner, pos::relativepos _quadrant) {
	corner = _corner;
	quadrant = _quadrant;
	return *this;
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
		_tPos.x=position.x;
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
/*
void __Widget::TopLeftFun(Widget* w){
		if (position.x<=1)
		_tPos.x=Pa.w*position.x;
		if (position.w<=1)
		_tPos.w=Pa.w*position.w;
}
void __Widget::TopRightFun(Widget *w){
	
}
void __Widget::BottomLeft(Widget *w){
	
}
void __Widget::BottomRight(Widget* w){
	
}

void Widget::__TopTopFun(Widget* w){
	if (w->position.h<=1)
      w->rela_position.h = P.y * w->position.h;
      
     if (w->position.y>1)  
     w->rela_position.y=P.y-w->rela_position.h-w->position.y ;
     else
      w->rela_position.y = (1 - w->position.y) * (P.y);
      
}

void Widget::__TopBottomFun(Widget *w)
	{
    	if (w->position.h<=1)
      w->rela_position.h = (GP.h - P.y) * w->position.h;
      if (w->position.y>1)
    	w->rela_position.y=P.y+w->position.y;
    	else
      w->rela_position.y = P.y + (GP.h - P.y) * w->position.y;
    
	}
	
	void Widget::__LeftLeftFun(Widget *w){
		
		if (w->position.w<=1)
      w->rela_position.w = P.x * w->position.w;
  
      if (w->position.x>1)
    	w->rela_position.x=P.x-w->rela_position.w-w->position.x;
    	else
      w->rela_position.x = (1 - w->position.x) * (P.x);
	}
	
	void Widget::__LeftRightFun(Widget *w){
		
		if (w->position.w<=1)
      w->rela_position.w = (GP.w - P.x) * w->position.w;
      
      if (w->position.x>1)
    	w->rela_position.x=P.x+w->position.x;
    	else
      w->rela_position.x = P.x + (GP.w - P.x) * w->position.x;
      
	}
	

	void Widget::__BottomBottomFun(Widget *w){
		
		if (w->position.h<=1)
      w->rela_position.h = (GP.h-P.x-P.h)*w->position.h ;
  
      if (w->position.y>1)
    	w->rela_position.h=P.y+P.h+w->position.y;
    	else
      w->rela_position.y =P.y + P.h + (GP.h - P.y - P.h) * w->position.y;
		
	}
	
	
	void Widget::__BottomTopFun(Widget *w){
		
		if (w->position.h<=1)
      w->rela_position.h = (P.h + P.y) * w->position.h;
      if (w->position.y>1)
    	w->rela_position.y=P.y+P.h-w->rela_position.h-w->position.y;
    	else
      w->rela_position.y = (P.y + P.h) * (1 - w->position.y);
		
	}
	
	
	void Widget::__RightRightFun(Widget *w){
		if (w->position.w<=1)
      w->rela_position.w = (GP.w - P.w - P.x) * w->position.w;
      if (w->position.x>1)
    	w->rela_position.x=P.x+P.w+w->position.x;
    	
    	else
      w->rela_position.x = P.x + P.w + (GP.w - P.w - P.x) * w->position.x;
	}
	

	void Widget::__RightLeftFun(Widget *w){
		
		if (w->position.w<=1)
      w->rela_position.w = (P.w + P.x) * w->position.w;
      
      if (w->position.x>1)   	w->rela_position.x=P.w+P.x-w->rela_position.w-w->position.x;
    	else
      w->rela_position.x = (P.w + P.x) * (1 - w->position.x);
		
	}
	
*/