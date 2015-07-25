#include <string>
#include <iostream>
using namespace std;

#ifndef OBJECT_H
#define OBJECT_H
class Object{
	char name[256];
	int xPosition;
	int yPosition;
	bool MouseOnIt;

public:
	Object();
	void setName(string n);
	const char * getName();
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	void setMouseState(bool st);
	bool getMouseState();
};
#endif 