#include "Object.h"
Object::Object(){
	xPosition = 0;
	yPosition = 0;
	MouseOnIt = false;
	strcpy(name, "");
}
void Object::setName(string n){
	strcpy(name, n.c_str());
}
const char * Object::getName(){
	return name;
}
void Object::setPosition(int x, int y){
	xPosition = x;
	yPosition = y;
}
void Object::getPosition(int &x, int &y){
	x = xPosition;
	y = yPosition;
}
void Object::setMouseState(bool st){
	MouseOnIt = st;
}

bool Object::getMouseState(){
	return MouseOnIt;
}
