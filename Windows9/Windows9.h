#include "Graphic.h"
#include "Computer.h"
#include "Desktop.h"
#include "NewFolder.h"

#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

#ifndef WINDOWS9_H
#define WINDOWS9_H
class Windows9{
	
	bool termination;
	
	Graphic * myGraphic;
	Computer * myComputer;
	Desktop * myDesktop;
	Folder * myFolderList;
	File * myFileList;
	NewFolder * myNewFolder;
	string myText;
	int folderNumber;
	int fileNumber;

	int xPosOfMouse;
	int yPosOfMouse;

	void UpdateCaption();
	bool checkIsInBox(int xPos, int yPos, int x, int y, int w, int h);
	void setPositionOfFolderAndFileList();
	void displayBasics();
	void checkMouseState(int x, int y);
	void checkMouseClicked(int x, int y);
public:
	Windows9();
	void Execute();
	void Shutdown();
};
#endif