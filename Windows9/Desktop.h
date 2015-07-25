#include "Folder.h"
#include "File.h"

#ifndef DESKTOP_H
#define DESKTOP_H
class Desktop{
	Object * myComputer;
	bool isActive;
	bool allCreated;

public:
	Desktop();
	void setActivation(bool activation);
	void setupViewPosition();
	void getViewPosition(string name, int &x, int &y);
	void setMouseState(string name, bool state);
	bool getMouseState(string name);
	bool getActivation();
	bool isAnyThingCreated();
	void release();
};
#endif