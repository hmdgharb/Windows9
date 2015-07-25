#include "Desktop.h"

Desktop::Desktop(){
	isActive = false;
	allCreated = true;
	
	myComputer = NULL;
	myComputer = new Object();
	if(myComputer == NULL)
		allCreated = false;
}

bool Desktop::isAnyThingCreated(){
	return allCreated;
}

void Desktop::setActivation(bool activation){
	isActive = activation;
}
bool Desktop::getActivation(){
	return isActive;
}

void Desktop::setupViewPosition(){

	myComputer->setPosition( 30, 30);
	
}
void Desktop::setMouseState(string name, bool state){
	if(name == "computer")
		myComputer->setMouseState( state);
}

bool Desktop::getMouseState(string name){
	if(name == "computer")
		return myComputer->getMouseState();
}

void Desktop::getViewPosition(string name, int &x, int &y){
	if(name == "computer")
		myComputer->getPosition( x, y);
}

void Desktop::release(){

	if(myComputer != NULL){
		delete myComputer;
		 myComputer = NULL;
	}
}