#include "Object.h"
#ifndef LEFTSIDEBAR_H
#define LEFTSIDEBAR_H
class LeftSideBar{
	Object* Desktop;
	Object* Computer;
public:
	LeftSideBar();
	bool setPosition(string name, int x, int y);
	void getPosition(string name, int &x, int &y);
	bool getMouseState(string name);
	void setMouseState(string name, bool state);
	void release();
};
#endif