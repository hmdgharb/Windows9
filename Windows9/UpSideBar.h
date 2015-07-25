#include "Object.h"

#ifndef UPSIDEBAR_H
#define UPSIDEBAR_H

class UpSideBar{
	
	Object *myUp;

	Object *myNewFolder;
	Object *myNewText;
	
public:
	UpSideBar();
	bool setPosition(string name, int x, int y);
	void getPosition(string name, int &x, int &y);
	bool getMouseState(string name);
	void setMouseState(string name, bool state);

	void release();
};
#endif