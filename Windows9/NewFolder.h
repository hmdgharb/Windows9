#include "Object.h"
#include <Windows.h>
#include <fstream>

#ifndef NEWFOLDER_H
#define NEWFOLDER_H
class NewFolder{
	Object * messageBox;
	Object * cancel;
	Object * save;
	Object * message;
	bool allCreated;
	bool isActive;
	bool messageChanged;
	string Name;
public:
	NewFolder();
	bool getActivation();
	void setActivation(bool state);
	bool isAnyThingCreated();
	void setupViewPosition();
	bool getMessageChanged();
	void setMessageChanged(bool st);
	void getViewPosition(string name, int &x, int &y);
	bool getMouseState(string name);
	void setMouseState(string name, bool st);
	void release();
	string getName();
	void setName(string t);
	void createFolder(string path);
	void createTextFile(string path);
};
#endif