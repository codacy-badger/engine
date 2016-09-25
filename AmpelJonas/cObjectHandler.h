#pragma once
#include "stdafx.h"

//movemodes
#define _MOVE_RELATIVE	0
#define _MOVE_ABSOULUTE	1

class cObject; //Circular dependency break (Bad practice. I Know.)

class cObjectHandler
{
public:
	cObjectHandler(cRender *_render);

	int createObject(cObject *_object);
	//Adds _object to managed objects vector
	//returns Identifier for newly created vector

	int moveObject(int _object, sPos _pos, int _mode);
	//Alters position of _object by _pos either relative to old position or Absolute
	//Depending on selected _mode (_MOVE_RELATIVE / _MOVE_ABSOLUTE). 

	int destroyObject(int _object);
	//removes _object from vector after deleting it

	int write();
	//writes all objects in objects[] to render buffer

private:
	vector<cObject*> objects;
	cRender *render;
};