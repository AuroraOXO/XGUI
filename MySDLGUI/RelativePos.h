#pragma once
#ifndef __RELATIVE_POS_H__
#define  __RELATIVE_POS_H__
#include <stdio.h>
struct pos
{
	typedef unsigned int relativepos;
	static const relativepos top = 0x1;
	static const relativepos bottom = 0x2;
	static const relativepos left = 0x4;
	static const relativepos right = 0x8;
	static const relativepos wcenter = 0x20;
	static const relativepos hcenter = 0x40;
	static const relativepos center = wcenter | hcenter;
	//private :
	pos() = delete;
};

#endif

/*
void foo(pos::relativepos p)
{
printf ("%d\n",p);
if (p&pos::top)
puts("top");

if (p&pos::bottom)
puts("bottom");

if (p&pos::left)
puts("left");

if (p&pos::right)
puts("right");

if (p&pos::center)
puts("center");

}

int main (int argc,char *argv[])
{

foo(pos::right|pos::left|pos::center);
printf ("%d\n",pos::right|pos::left);
}

*/