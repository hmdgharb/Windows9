#include "NewFolder.h"

NewFolder::NewFolder(){
	allCreated = true;
	isActive = false;

	messageBox = cancel = save = message = NULL;
	Name = "NewFolder";
	messageBox = new Object();
	if(messageBox == NULL)
		allCreated = false;

	cancel = new Object();
	if(cancel == NULL)
		allCreated = false;

	save = new Object();
	if(save == NULL)
		allCreated = false;

	message = new Object();
	if(message == NULL)
		allCreated = false;
}

bool NewFolder::isAnyThingCreated(){
	return allCreated;
}

void NewFolder::setActivation(bool activation){
	isActive = activation;
}

bool NewFolder::getActivation(){
	return isActive;
}

void NewFolder::setupViewPosition(){
	
	messageBox->setPosition(150, 150);
	message->setPosition(190, 190);
	save->setPosition(170, 220);
	cancel->setPosition(310, 220);
}
string NewFolder::getName(){
	return Name;
}
void NewFolder::setName(string t){
	Name = t;
}

bool NewFolder::getMessageChanged(){
	return messageChanged;
}

void NewFolder::setMessageChanged(bool st){
	messageChanged = st;
}
void NewFolder::getViewPosition(string name, int &x, int &y){
	if(name == "messageBox"){
		messageBox->getPosition(x, y);
	}
	else if(name == "cancel"){
		cancel->getPosition(x, y);
	}
	else if(name == "save"){
		save->getPosition(x, y);
	}
	else if(name == "message"){
		message->getPosition(x, y);
	} 
	else{
		cout << "name : " << name.c_str() << " is not in New class, for get view position" << endl;
	}
}

bool NewFolder::getMouseState(string name){
	if(name == "messageBox"){
		return messageBox->getMouseState();
	}
	else if(name == "cancel"){
		return cancel->getMouseState();
	}
	else if(name == "save"){
		return save->getMouseState();
	}else{
		cout << "name : " << name.c_str() << " is not in New class, for get mouse state" << endl;
		return false;
	}
}
void NewFolder::setMouseState(string name, bool st){
	if(name == "messageBox"){
		messageBox->setMouseState(st);
	}
	else if(name == "cancel"){
		cancel->setMouseState(st);
	}
	else if(name == "save"){
		save->setMouseState(st);
	}else{
		cout << "name : " << name.c_str() << " is not in New class, for set mouse state" << endl;
	}
}

void NewFolder::release(){
	if(messageBox != NULL){
		delete messageBox;
		messageBox = NULL;
	}
	if(cancel != NULL){
		delete cancel;
		cancel = NULL;
	}
	if(save != NULL){
		delete save;
		save = NULL;
	}
	if(message != NULL){
		delete message;
		message = NULL;
	}
}

void NewFolder::createFolder(string path){
	string tempPath = path;
	tempPath += Name;
	char *myPath = (char *)malloc(sizeof(char) * tempPath.size());
	strcpy(myPath, tempPath.c_str());

	wstring tempWstring (myPath, myPath +strlen(myPath));
	
	LPCWSTR dirPath =	tempWstring.c_str();

	if(CreateDirectory (dirPath, NULL) != NULL)
		cout << "folder: " << myPath << " is created" << endl;
	else
		cout << "cannot create : " << myPath << endl;

	free(myPath);
}