#include "stdafx.h"
#include "Widget.h"


Widget::Widget()
{
	parent = NULL;
}


Widget::~Widget()
{
}

void Widget::Draw(SDL_Renderer *render) {
	//TextureCopy(render,background,NULL,NULL,(SDL_Rect*)&position);
}
bool Widget::HandleEvent(SDL_Event &_event) {

}
const Widget & Widget::SetRelavitePos(pos::relativepos _corner, pos::relativepos _quadrant) {
	corner = _corner;
	quadrant = _quadrant;
	return *this;
}

void Widget::SetPos(int x, int y, int w, int h){

	position={ x+0.1,y+0.1,w+0.1,h+0.1 };
}
void Widget::SetPos(float x, float y, float w, float h) {

	position={x,y,w,h};
}