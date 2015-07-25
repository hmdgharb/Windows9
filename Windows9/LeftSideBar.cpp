#include "LeftSideBar.h"

LeftSideBar::LeftSideBar(){
	Desktop = new Object;
	Computer = new Object;

	Desktop->setName("Desktop");
	Computer->setName("Computer");
}

bool LeftSideBar::setPosition(string name, int x, int y){
	if("Desktop" == name){
		Desktop->setPosition(x, y);
		return true;
	} else if("Computer" == name){
		Computer->setPosition(x, y);
		return true;
	}
	return false;
}

void LeftSideBar::getPosition(string name, int &x, int &y){
	if("Desktop" == name){
		Desktop->getPosition(x, y);
	} else if("Computer" == name){
		Computer->getPosition(x, y);
	}
	else{
		cout << "getPosition for: " << name << " cannot be done, because the name is not exist" << endl;
		x = 0;
		y = 0;
	}
}

bool LeftSideBar::getMouseState(string name){

	if("Desktop" == name){
		return Desktop->getMouseState();
	} else if("Computer" == name){
		return Computer->getMouseState();
	}
	else{
		cout << "left side bar cannot get mouse state for : " << name << endl;
		return false;
	}
}

void LeftSideBar::setMouseState(string name, bool state){

	if("Desktop" == name){
		Desktop->setMouseState(state);
	} else if("Computer" == name){
		Computer->setMouseState(state);
	}
	else{
		cout << "left side bar cannot set mouse state for : " << name << "in state: " << state << endl;
	}
}

void LeftSideBar::release(){
	if(Desktop != NULL){
		delete Desktop;
		Desktop = NULL;
	}
	if(Computer != NULL){
		delete Computer;
		Computer = NULL;
	}

	cout << "all left side bar contents have been release" << endl;
}