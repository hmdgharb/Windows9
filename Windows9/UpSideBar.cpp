#include "UpSideBar.h"
UpSideBar::UpSideBar(){
	
	myUp = new Object;
	myNewFolder = new Object;
	myNewText = new Object;

	myUp->setName("Up");
	myNewFolder->setName("NewFolder");
	myNewText->setName("NewText");
}

void UpSideBar::getPosition(string name, int &x, int &y){
	
	if("Up" == name){
		myUp->getPosition(x, y);
	} else if("NewFolder" == name){
		myNewFolder->getPosition(x, y);
	} else if("NewText" == name){
		myNewText->getPosition(x, y);
	} else{
		cout << "getPosition for: " << name << " cannot be done, because the name is not exist" << endl;
		x = 0;
		y = 0;
	}
}

bool UpSideBar::setPosition(string name, int x, int y){
	
	if("Up" == name){
		myUp->setPosition(x, y);
		return true;
	} else if("NewFolder" == name){
		myNewFolder->setPosition(x, y);
		return true;
	} else if("NewText" == name){
		myNewText->setPosition(x, y);
		return true;
	} else{
		return false;
	}
}
bool UpSideBar::getMouseState(string name){

	if("Up" == name){
		return myUp->getMouseState();
	} else if("NewFolder" == name){
		return myNewFolder->getMouseState();
	}else if("NewText" == name){
		return myNewText->getMouseState();
	}
	else{
		cout << "up side bar cannot get mouse state for : " << name << endl;
		return false;
	}
}

void UpSideBar::setMouseState(string name, bool state){

	if("Up" == name){
		myUp->setMouseState(state);
	} else if("NewFolder" == name){
		myNewFolder->setMouseState(state);
	}else if("NewText" == name){
		myNewText->setMouseState(state);
	}
	else{
		cout << "up side bar cannot set mouse state for : " << name << "in state: " << state << endl;
	}
}

void UpSideBar::release(){
	if(myUp != NULL){
		delete myUp;
		myUp = NULL;
	}
	if(myNewFolder != NULL){
		delete myNewFolder;
		myNewFolder = NULL;
	}

	if(myNewText != NULL){
		delete myNewText;
		myNewText = NULL;
	}
	cout << "all up side bar contents have been release" << endl;
}