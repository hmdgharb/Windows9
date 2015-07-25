#include "Windows9.h"
#include <stdio.h>

Windows9::Windows9(){
	
	termination = false;
	myFolderList = NULL;
	myFileList = NULL;
	myGraphic = NULL;
	myDesktop = NULL;
	myComputer = NULL;
	myNewFolder = NULL;

	myGraphic = new Graphic();
	myDesktop = new Desktop();
	myComputer = new Computer();
	myNewFolder = new NewFolder();
	
	if(myDesktop != NULL){
		cout << "myDesktop has been created" << endl;
		if(myDesktop->isAnyThingCreated() == true){
			myDesktop->setupViewPosition();
			myDesktop->setActivation(true);		//not activing state of myDesktop for playing on display
			cout << "myDesktop has been activated" << endl;
		} else{
			cout << "myDesktop cannot created its values" << endl;
			termination = true;
		}
	} else{
		termination = true;
		cout << "myDesktop has not been created" << endl;
	}

	
	if(myComputer != NULL){
		cout << "myComputer has been created" << endl;
		if(myComputer->isAnyThingCreated() == true){
			myComputer->setupViewPosition();
			myComputer->setActivation(false);		//activing state of myComputer for playing on display
			cout << "myComputer has not been activated" << endl;
		} else{
			cout << "myComputer cannot created its values" << endl;
			termination = true;
		}
	} else{
		termination = true;
		cout << "myComputer has not been created" << endl;
	}

	if(myNewFolder != NULL){
		cout << "myNewFolder has been created" << endl;
		if(myNewFolder->isAnyThingCreated() == true){
			myNewFolder->setupViewPosition();
			myNewFolder->setActivation(false);		//activing state of myComputer for playing on display
			cout << "myNewFolder has not been activated" << endl;
		} else{
			cout << "myNewFolder cannot created its values" << endl;
			termination = true;
		}
	} else{
		termination = true;
		cout << "myNewFolder has not been created" << endl;
	}
}

void Windows9::UpdateCaption(){
	
	if(myComputer->getActivation() == true)
		myGraphic->setCaption("myComputer");
	else if(myDesktop->getActivation() == true)
		myGraphic->setCaption("myDesktop");
	
}
void Windows9::Execute(){
	
	SDL_Event *currentEvent = myGraphic->getEvent();
	
	UpdateCaption();
	myGraphic->activeInputText();
	myText = "NewFolder";
	myNewFolder->setMessageChanged(true);
					
	while(termination == false){
		
		displayBasics();

		while(SDL_PollEvent(currentEvent)){
			
			if(currentEvent->type == SDL_QUIT){
				termination = true;
			}
			else if(currentEvent->type == SDL_MOUSEMOTION){
				xPosOfMouse = currentEvent->button.x;
				yPosOfMouse = currentEvent->button.y;
				//cout << "x: " << xPosOfMouse << " y: " << yPosOfMouse << endl;
				checkMouseState(xPosOfMouse, yPosOfMouse);
			}
			else if(currentEvent->type == SDL_MOUSEBUTTONDOWN){
				xPosOfMouse = currentEvent->button.x;
				yPosOfMouse = currentEvent->button.y;
				cout << "x: " << xPosOfMouse << " y: " << yPosOfMouse << endl;
				checkMouseClicked(xPosOfMouse, yPosOfMouse);
			}
			else if(currentEvent->type == SDL_KEYDOWN && myNewFolder->getActivation()){
				
				if( currentEvent->key.keysym.sym == SDLK_BACKSPACE && myText.length() > 0 ){
					myNewFolder->setMessageChanged(true);
					myText.pop_back();
				}
			}
			if(currentEvent->type == SDL_TEXTINPUT && myNewFolder->getActivation()){
				myNewFolder->setMessageChanged(true);
				myText += currentEvent->text.text;
			}
		}
		
		if(myNewFolder->getActivation() && myNewFolder->getMessageChanged() == true){
			myNewFolder->setName(myText);
			cout << "text: " << myNewFolder->getName() << endl;
		}
		myGraphic->display();
		UpdateCaption();
	}
	myGraphic->deactiveInputText();
	
}

void Windows9::Shutdown(){

	cout << "-----------------in Windows9::Shutdown()--------------------" << endl;
	
	if(myGraphic != NULL){

		myGraphic->Shutdown();
		delete myGraphic;
		myGraphic = NULL;
	}

	if(myComputer != NULL){
		myComputer->release();
		delete myComputer;
		myComputer = NULL;
	}
	
	if(myDesktop != NULL){
		myDesktop->release();
		delete myDesktop;
		myDesktop = NULL;
	}

	if(myNewFolder != NULL){
		myNewFolder->release();
		delete myNewFolder;
		myNewFolder = NULL;
	}

	cout << "Windows9 has been shutdown." << endl;
}



void Windows9::displayBasics(){

	myGraphic->clearScreen();
	int x, y, w, h;
	if(myDesktop->getActivation() == true){
		myGraphic->addImageToWindow(0, 0, "desktop_background", true, "full screen");
		myGraphic->addMessageToWindow(300, 450, "Created By Hamid Gharb. email: hmd.gharb@gmail.com", "Allber_Bd");
		myDesktop->getViewPosition("computer", x, y);
		myGraphic->addImageToWindow(x, y, "computer", myDesktop->getMouseState("computer")); 
	} else if(myComputer->getActivation() == true){
		
		myGraphic->addImageToWindow(0, 0, "background", true, "full screen");
		myGraphic->addMessageToWindow(300, 50, "Created By Hamid Gharb. email: hmd.gharb@gmail.com", "Allber_Bd");
		string t = myComputer->getCurrentAddress();
		myGraphic->addMessageToWindow(300, 10, "Current Address:", "Aller_BdIt");
		if(t == "")
			myGraphic->addMessageToWindow(400, 10, "MyComputer", "Allber_Bd");
		else
			myGraphic->addMessageToWindow(400, 10, t, "Allber_Bd");
		
		//Computer Icon
		myComputer->getViewPosition("LeftSideBar","Computer", x, y);
		myGraphic->addImageToWindow(x, y, "computer", myNewFolder->getActivation() == false && myComputer->getMouseState("LeftSideBar", "Computer"));
		//Desktop Icon
		myComputer->getViewPosition("LeftSideBar","Desktop", x, y);
		myGraphic->addImageToWindow(x, y, "desktop", myNewFolder->getActivation() == false && myComputer->getMouseState("LeftSideBar", "Desktop"));
		//Up Icon
		myComputer->getViewPosition("UpSideBar","Up", x, y);
		myGraphic->addImageToWindow(x, y, "up", myNewFolder->getActivation() == false && myComputer->getMouseState("UpSideBar", "Up"));
		//NewFolder
		myComputer->getViewPosition("UpSideBar","NewFolder", x, y);
		myGraphic->addImageToWindow(x, y, "newFolder", myNewFolder->getActivation() == false && myComputer->getMouseState("UpSideBar", "NewFolder"));
		//NewText
		myComputer->getViewPosition("UpSideBar","NewText", x, y);
		myGraphic->addImageToWindow(x, y, "newText", myNewFolder->getActivation() == false && myComputer->getMouseState("UpSideBar", "NewText"));
		
		if(myComputer->getCurrentAddress() == ""){
		
			//DriveC
			myComputer->getViewPosition("Drive", "DriveC", x, y);
			myGraphic->addImageToWindow(x, y, "drive", myComputer->getMouseState("Drive", "DriveC"));
			myGraphic->getData(w, h, "drive");
			myGraphic->addMessageToWindow(x + 5,y + h + 10, "Drive C", "AllerDisplay");
	
			//DriveD
			myComputer->getViewPosition("Drive", "DriveD", x, y);
			myGraphic->addImageToWindow(x, y, "drive", myComputer->getMouseState("Drive", "DriveD"));
			myGraphic->addMessageToWindow(x + 5,y + h + 10, "Drive D", "AllerDisplay");
	} else{
			
			//getting information of folders for displaying them in graphic functions
			Folder *folderList ;
			int folderListMembers;
			myComputer->getFolderListMembers( folderListMembers);
			folderList = myComputer->getFolderList();
			int x, y, w, h;
			string temp, temp2;
			myGraphic->getData(w, h, "folder");
			for(int i = 0; i < folderListMembers; i++){
				folderList[i].getPosition(x, y);
				myGraphic->addImageToWindow(x, y, "folder", myNewFolder->getActivation() == false && folderList[i].getMouseState());
				temp = folderList[i].getName();

				if(temp.size() < 10)
					myGraphic->addMessageToWindow(x + 5, y + h + 5, temp, "Aller_BdIt"); 
				else{
					temp2 = "";
					for(int i = 0; i < 7; i++)
						temp2 += temp.at(i);
					temp2 += "...";
					myGraphic->addMessageToWindow(x + 5, y + h + 5, temp2, "Aller_BdIt"); 
				}
			}
			
			folderList = NULL;
			folderListMembers = 0;

			
			//getting information of files for displaying them in graphic functions
			File *fileList ;
			int fileListMembers;
			myComputer->getFileListMembers( fileListMembers);
			fileList = myComputer->getFileList();
			myGraphic->getData(w, h, "folder");
			
			for(int i = 0; i < fileListMembers; i++){
				fileList[i].getPosition(x, y);
				myGraphic->addImageToWindow(x, y, "text", myNewFolder->getActivation() == false && fileList[i].getMouseState());
			
				temp = fileList[i].getName();

				if(temp.size() < 10)
					myGraphic->addMessageToWindow(x + 5, y + h + 5, temp, "Aller_LtIt"); 
				else{
					temp2 = "";
					for(int i = 0; i < 7; i++)
						temp2 += temp.at(i);
					temp2 += "...";
					myGraphic->addMessageToWindow(x + 5, y + h + 5, temp2, "Aller_LtIt"); 
				}
			}
			
			fileList = NULL;
			fileListMembers = 0;

		}
		if(myNewFolder->getActivation() == true){
			
			myNewFolder->getViewPosition("messageBox", x, y);
			myGraphic->getData(w, h, "messageBox");
			myGraphic->addImageToWindow(x, y, "messageBox", checkIsInBox(xPosOfMouse, yPosOfMouse, x, y, w, h));
			myGraphic->addMessageToWindow(x + 20, y + 20, "Please Add New Name: ", "Aller_BdIt");
			myNewFolder->getViewPosition("save", x, y);
			myGraphic->getData(w, h, "save");
			myGraphic->addImageToWindow(x, y, "save", checkIsInBox(xPosOfMouse, yPosOfMouse, x, y, w, h));
			
			myNewFolder->getViewPosition("cancel", x, y);
			myGraphic->getData(w, h, "cancel");
			myGraphic->addImageToWindow(x, y, "cancel", checkIsInBox(xPosOfMouse, yPosOfMouse, x, y, w, h));

			if(myNewFolder->getMessageChanged() == true){
				myGraphic->resetNewMessage(myNewFolder->getName(), "Aller_BdIt");
				myNewFolder->setMessageChanged(false);
			}
			myNewFolder->getViewPosition("message", x, y);
			myGraphic->displayNewMessage(x, y); 
		}
		
	}
}
bool Windows9::checkIsInBox(int xPos, int yPos, int x, int y, int w, int h){
	if(xPos >= x && xPos <= x + w && yPos >= y && yPos <= y + h)
		return true;
	else 
		return false;
}

void Windows9::checkMouseState(int xPosMouse, int yPosMouse){
	
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	if(myDesktop->getActivation() == true){
		myDesktop->getViewPosition("computer", x, y);
		myGraphic->getData(w, h, "computer");

		myDesktop->setMouseState("computer", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
	}
	else if(myComputer->getActivation() == true){
		//checking is mouse in Desktop Icon
		myComputer->getViewPosition("LeftSideBar", "Desktop", x, y);
		myGraphic->getData(w, h, "desktop");
		myComputer->setMouseState("LeftSideBar", "Desktop", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
		
		if(myComputer->getCurrentAddress() == ""){
		
			//checking is mouse in Drive C Icon
			myComputer->getViewPosition("Drive", "DriveC", x, y);
			myGraphic->getData(w, h, "drive");
			myComputer->setMouseState("Drive", "DriveC", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
			
			//checking is mouse in Drive D Icon
			myComputer->getViewPosition("Drive", "DriveD", x, y);
			myGraphic->getData(w, h, "drive");
			myComputer->setMouseState("Drive", "DriveD", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
		
			myComputer->setMouseState("UpSideBar", "Up", false);
			myComputer->setMouseState("UpSideBar", "NewFolder", false);
			myComputer->setMouseState("UpSideBar", "NewText", false);
			myComputer->setMouseState("LeftSideBar", "Computer", false);
		
		}else {
			//checking is mouse in Computer Icon
			myComputer->getViewPosition("LeftSideBar", "Computer", x, y);
			myGraphic->getData(w, h, "computer");
			myComputer->setMouseState("LeftSideBar", "Computer", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
		
			//checking is mouse in Up Icon
			myComputer->getViewPosition("UpSideBar", "Up", x, y);
			myGraphic->getData(w, h, "up");
			myComputer->setMouseState("UpSideBar", "Up", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
			//checking is mouse in NewFoder Icon
			myComputer->getViewPosition("UpSideBar", "NewFolder", x, y);
			myGraphic->getData(w, h, "newFolder");
			myComputer->setMouseState("UpSideBar", "NewFolder", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
			//checking is mouse in NewText Icon
			myComputer->getViewPosition("UpSideBar", "NewText", x, y);
			myGraphic->getData(w, h, "newText");
			myComputer->setMouseState("UpSideBar", "NewText", checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
		
			
			//getting information of folders for updating them in graphic functions
			Folder *folderList ;
			int folderListMembers;
			myComputer->getFolderListMembers( folderListMembers);
			folderList = myComputer->getFolderList();
			myGraphic->getData(w, h, "folder");
			for(int i = 0; i < folderListMembers; i++){
				folderList[i].getPosition(x, y);
				folderList[i].setMouseState( checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
			}
			
			folderList = NULL;
			folderListMembers = 0;

			//getting information of files for updating them in graphic functions
			File *fileList ;
			int fileListMembers;
			myComputer->getFileListMembers( fileListMembers);
			fileList = myComputer->getFileList();
			myGraphic->getData(w, h, "text");
			
			for(int i = 0; i < fileListMembers; i++){
				fileList[i].getPosition(x, y);
				fileList[i].setMouseState( checkIsInBox(xPosMouse, yPosMouse, x, y, w, h));
			}
			
			fileList = NULL;
			fileListMembers = 0;
			
		}
	}
}


void Windows9::checkMouseClicked(int xPosMouse, int yPosMouse){
	
	int x, y, w, h;

	if(myDesktop->getActivation() == true){
		myDesktop->getViewPosition("computer", x, y);
		myGraphic->getData(w, h, "computer");

		if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
			myDesktop->setActivation(false);
			myComputer->setActivation(true);
			cout << "myComputer has been activated and myDesktop has been de activated" << endl;
		}
	}
	
	if(myComputer->getActivation() == true && myNewFolder->getActivation() == false){
		myComputer->getViewPosition("LeftSideBar","Desktop", x, y);
		myGraphic->getData(w, h, "desktop");
		//myGraphic->releaseMessageLinkedList();
		bool occurried = false;
		if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
			myDesktop->setActivation(true);
			myComputer->setActivation(false);
			myComputer->resetPath("");
			cout << "myDesktop has been activated and myComputer has been de activated" << endl;
			occurried = true;
		}
		if(occurried == false && myComputer->getCurrentAddress() == ""){
			myComputer->getViewPosition("Drive","DriveC", x, y);
			myGraphic->getData(w, h, "drive");

			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
				myComputer->resetPath("C:\\");
				int w, h;
				int SCREEN_WIDTH, SCREEN_HEIGHT;
				myGraphic->getData(w, h, "folder");
				myGraphic->getScreenWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
				myComputer->setPositionOfFolderListAndFileList(w, h, SCREEN_WIDTH, SCREEN_HEIGHT);
				cout << "DriveC path has been created" << endl;
				occurried = true;	
			}
		}
		if(occurried == false && myComputer->getCurrentAddress() == ""){

			myGraphic->getData(w, h, "drive");
			myComputer->getViewPosition("Drive","DriveD", x, y);
			
			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
				myComputer->resetPath("D:\\");
				int w, h;
				int SCREEN_WIDTH, SCREEN_HEIGHT;
				myGraphic->getData(w, h, "folder");
				myGraphic->getScreenWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
				myComputer->setPositionOfFolderListAndFileList(w, h, SCREEN_WIDTH, SCREEN_HEIGHT);
				cout << "DriveD path has been created" << endl;
				occurried = true;
			}
		}
		if(occurried == false && myComputer->getCurrentAddress() != ""){
			myComputer->getViewPosition("LeftSideBar","Computer", x, y);
			myGraphic->getData(w, h, "computer");

			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
				myComputer->resetPath("");
				//cout << "DriveC path has been created" << endl;
				occurried = true;	
			}
		}

		if(occurried == false && myComputer->getCurrentAddress() != ""){
			myComputer->getViewPosition("UpSideBar","NewFolder", x, y);
			myGraphic->getData(w, h, "newFolder");

			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
				myNewFolder->setActivation(true);
				occurried = true;	
			}
		}
		if(occurried == false && myComputer->getCurrentAddress() != ""){
			myComputer->getViewPosition("UpSideBar","Up", x, y);
			myGraphic->getData(w, h, "up");

			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){		
				myComputer->goBack();
				string temp = myComputer->getCurrentAddress();
				myComputer->resetPath(temp);
				if(temp != ""){
					int w, h;
					int SCREEN_WIDTH, SCREEN_HEIGHT;
					myGraphic->getData(w, h, "folder");
					myGraphic->getScreenWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
					myComputer->setPositionOfFolderListAndFileList(w, h, SCREEN_WIDTH, SCREEN_HEIGHT);
					occurried = true;
				}
			}
		}

		if(occurried == false && myComputer->getCurrentAddress() != ""){
						
			//getting information of folders for updating them in graphic functions
			Folder *folderList ;
			int folderListMembers;
			myComputer->getFolderListMembers( folderListMembers);
			folderList = myComputer->getFolderList();
			myGraphic->getData(w, h, "folder");
			for(int i = 0; i < folderListMembers; i++){
				folderList[i].getPosition(x, y);
				if( checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){

					string temp =  myComputer->getCurrentAddress();
					temp +=  folderList[i].getName();
					temp += "\\";
					cout <<temp << endl;
					myComputer->resetPath(temp);
				
					int w, h;
					int SCREEN_WIDTH, SCREEN_HEIGHT;
					myGraphic->getData(w, h, "folder");
					myGraphic->getScreenWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
					myComputer->setPositionOfFolderListAndFileList(w, h, SCREEN_WIDTH, SCREEN_HEIGHT);
				}
			}
			
			folderList = NULL;
			folderListMembers = 0;

		}
	}
	else if(myComputer->getActivation() == true && myNewFolder->getActivation() == true ){
		
		myNewFolder->getViewPosition("cancel", x, y);
		myGraphic->getData(w, h, "cancel");
		bool occurried = false;
		if(checkIsInBox(xPosMouse, yPosMouse,x, y, w, h)){
			myNewFolder->setActivation( false); 
			occurried = true;
		}
		if(occurried == false){
			
			myNewFolder->getViewPosition("save", x, y);
			myGraphic->getData(w, h, "save");
			if(checkIsInBox(xPosMouse, yPosMouse, x, y, w, h)){
				cout << myComputer->getCurrentAddress() << myNewFolder->getName() << "\\"<< endl;
			
				myNewFolder->createFolder(myComputer->getCurrentAddress());


				myNewFolder->setActivation(false);
				myComputer->resetPath(myComputer->getCurrentAddress());
				int w, h;
				int SCREEN_WIDTH, SCREEN_HEIGHT;
				myGraphic->getData(w, h, "folder");
				myGraphic->getScreenWidthHeight(SCREEN_WIDTH, SCREEN_HEIGHT);
				myComputer->setPositionOfFolderListAndFileList(w, h, SCREEN_WIDTH, SCREEN_HEIGHT);
				occurried = true;
			}
		}
	}
	
}