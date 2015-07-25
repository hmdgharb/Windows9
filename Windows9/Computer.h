#include "Folder.h"
#include "File.h"
#include "UpSideBar.h"
#include "LeftSideBar.h"
#include "PathAnalysis.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifndef COMPUTER_H
#define COMPUTER_H
class Computer{
	
	UpSideBar *myUpBar;
	LeftSideBar *myLeftBar;
	PathAnalysis * myPathAnalysis;
	File * myFileList;
	Folder * myFolderList;

	Object * myDriveC;
	Object * myDriveD;

	int fileNumber;
	int folderNumber;

	bool isActive;
	bool allCreated;

	int rowStart;
	int columnStart;
	int distanceBetweenTwoIcon;
	
public:
	Computer();
	void goBack();
	void resetPath(string name);
	void setActivation(bool activation);
	void setupViewPosition();
	void getViewPosition(string type, string name, int &x, int &y);
	bool getMouseState(string type, string name);
	void setMouseState(string type, string name, bool st);
	bool getActivation();
	bool isAnyThingCreated();
	void release();
	void FileListAndFolderListCreation();
	void FileListAndFolderListInitialize();
	void FileListAndFolderListShowName();
	void setPositionOfFolderListAndFileList(int w, int h, int screenWidth, int screenHeight);
	string getCurrentAddress();
	void checkAddress();
	void getFolderListMembers(int &myFolderListMembers);
	Folder * getFolderList();
	void getFileListMembers(int &myFileListMembers);
	File * getFileList();
};
#endif