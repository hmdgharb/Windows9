#include "Computer.h"
Computer::Computer(){

	allCreated = true;
	isActive = false;
	myPathAnalysis = false;
	
	myFileList = NULL;
	myFolderList = NULL;
	folderNumber = fileNumber = 0;

	myUpBar = NULL;
	myUpBar = new UpSideBar();
	if(myUpBar == NULL)
		allCreated = false;
	
	myLeftBar = NULL;
	myLeftBar = new LeftSideBar();
	if(myLeftBar == NULL)
		allCreated = false;

	myDriveC = NULL;
	myDriveC = new Object();
	if(myDriveC == NULL)
		allCreated = false;

	myDriveD = NULL;
	myDriveD = new Object();
	if(myDriveD == NULL)
		allCreated = false;
}
void Computer::goBack(){
	cout << "this is before address: " << myPathAnalysis->getAddress() << endl;
	myPathAnalysis->removeFromPath();
	cout << "this is new address: " << myPathAnalysis->getAddress() << endl;
}
void Computer::resetPath(string name){
	if(myPathAnalysis != NULL){
		delete myPathAnalysis;
		myPathAnalysis = NULL;
	}

	myPathAnalysis = new PathAnalysis(name.c_str());
	if(myPathAnalysis != NULL){
		FileListAndFolderListCreation();
		FileListAndFolderListInitialize();
		cout << "path " << name.c_str() << " has been updated" << endl;
	}else{
		cout << "path " << name.c_str() << "cannot be create" << endl;
	}
}

string Computer::getCurrentAddress(){
	if(myPathAnalysis == NULL)
		return "";
	else
		return myPathAnalysis->getAddress();
}

bool Computer::isAnyThingCreated(){
	return allCreated;
}

void Computer::setActivation(bool activation){
	isActive = activation;
}
bool Computer::getActivation(){
	return isActive;
}

void Computer::setupViewPosition(){

	myUpBar->setPosition("Up", 30, 30);
	myUpBar->setPosition("NewFolder", 130, 30);
	myUpBar->setPosition("NewText", 230, 30);

	myLeftBar->setPosition("Desktop", 30, 200);
	myLeftBar->setPosition("Computer", 30, 300);

	myDriveC->setPosition(250, 200);
	myDriveD->setPosition(350, 200);
}

void Computer::getViewPosition(string type, string name, int &x, int &y){
	if(type == "UpSideBar")
		myUpBar->getPosition(name, x, y);
	else if(type == "LeftSideBar")
		myLeftBar->getPosition(name, x, y);
	else if(type == "Drive"){
		if(name == "DriveC")
			myDriveC->getPosition(x, y);
		else if(name == "DriveD")
			myDriveD->getPosition(x, y);
	}
	
}
bool Computer::getMouseState(string type, string name){
	if(type == "UpSideBar")
		return myUpBar->getMouseState(name);
	else if(type == "LeftSideBar")
		return myLeftBar->getMouseState(name);
	else if(type == "Drive"){
		if(name == "DriveC")
			return myDriveC->getMouseState();
		else if(name == "DriveD")
			return myDriveD->getMouseState();
	}
}

void Computer::setMouseState(string type, string name, bool state){
	if(type == "UpSideBar")
		myUpBar->setMouseState(name, state);
	else if(type == "LeftSideBar")
		myLeftBar->setMouseState(name, state);
	else if(type == "Drive"){
		if(name == "DriveC")
			myDriveC->setMouseState(state);
		else if(name == "DriveD")
			myDriveD->setMouseState(state);
	}
}
void Computer::release(){

	if(myUpBar != NULL){
		myUpBar->release();
		delete myUpBar;
		myUpBar = NULL;
	}
	
	if(myLeftBar != NULL){
		myLeftBar->release();
		delete myLeftBar;
		myLeftBar = NULL;
	}

	if(myPathAnalysis != NULL){
		delete myPathAnalysis;
		myPathAnalysis = NULL;
	}

	if(myFileList != NULL){
		free(myFileList);
		fileNumber = 0;
		myFileList = NULL;
	}

	if(myFolderList != NULL){
		free(myFolderList);
		folderNumber = 0;
		myFolderList = NULL;
	}

	if(myDriveC != NULL){
		delete myDriveC;
		myDriveC = NULL;
	}
	
	if(myDriveD != NULL){
		delete myDriveD;
		myDriveD = NULL;
	}

}

void Computer::FileListAndFolderListCreation(){
	
	/*---------------------------------------------------------------------file list creation section--------------*/
	if(myFileList != NULL){
		free(myFileList);
		myFileList = NULL;
	}
	fileNumber = 0;
	
	string fileNameList = myPathAnalysis->getFileListItContains();
//	cout << fileNameList << endl;
	stringstream fileNameListStream( fileNameList.c_str() );
	cout << "-----------------in FileListCreation Section--------------------" << endl;
	while(fileNameListStream.good()){
		string temp;
		getline(fileNameListStream, temp, '|');
		if(temp != ""){
//			cout << "file: " << temp << endl;
			fileNumber++;
		}
	}
	
	myFileList = (File*) malloc(sizeof(File) * fileNumber);
	cout << "number fo files created: " << fileNumber << endl;

/*---------------------------------------------------------------------folder list creation section--------------*/
	if(myFolderList != NULL){
		free(myFolderList);
		myFolderList = NULL;
	}

	folderNumber = 0;
	
	string folderNameList = myPathAnalysis->getFolderListItContains();

	//	cout << folderNameList << endl;
	stringstream folderNameListStream( folderNameList.c_str() );
	cout << "-----------------in FolderListCreation--------------------" << endl;
	while(folderNameListStream.good()){
		string temp;
		getline(folderNameListStream, temp, '|');
		if(temp != ""){
			folderNumber++;
		}
	}

	myFolderList = (Folder*) malloc(sizeof(Folder) * folderNumber);
	cout << "number fo folders created: " << folderNumber << endl;

}

void Computer::FileListAndFolderListInitialize(){
	
	/*---------------------------------------------------------------------file list initialize section--------------*/
	
	string fileNameList = myPathAnalysis->getFileListItContains();
	
	stringstream fileNameListStream( fileNameList.c_str() );
	cout << "-----------------in FileListInitial--------------------" << endl;
	int fileIndex = 0;

	while(fileNameListStream.good()){
		string temp;
		getline(fileNameListStream, temp, '|');
		if(temp != ""){
			
			File *FL = &(myFileList[fileIndex]);
			FL->setName(temp);
			fileIndex++;
		}
	}

	cout << "all " << fileIndex << " file has been initliazed" << endl;



	/*---------------------------------------------------------------------folder list initialize section--------------*/
	string folderNameList = myPathAnalysis->getFolderListItContains();
	
	stringstream folderNameListStream( folderNameList.c_str() );
	cout << "-----------------in FolderListInitial--------------------" << endl;
	int folderIndex = 0;

	while(folderNameListStream.good()){
		string temp;
		getline(folderNameListStream, temp, '|');
		if(temp != ""){
			
			Folder *FLD = &(myFolderList[folderIndex]);
			FLD->setName(temp);
			folderIndex++;
		}
	}
	cout << "all " << folderIndex << " folder has been initliazed" << endl;
}

void Computer::FileListAndFolderListShowName(){

	cout << "______________________i am in FileList ShowName section______________________" << endl;
	for(int i = 0; i < fileNumber; i++){
		cout << i+1 << ".	" << myFileList[i].getName() << endl;
	}

	cout << "______________________i am in FolderList ShowName section______________________" << endl;
	for(int i = 0; i < folderNumber; i++){
		cout << i+1 << ".	" << myFolderList[i].getName() << endl;
	}
}


void Computer::setPositionOfFolderListAndFileList(int w, int h, int SCREEN_WIDTH, int SCREEN_HEIGHT){

	rowStart = 200;
	columnStart = 150;

	int xPos, yPos;
	
	distanceBetweenTwoIcon = 20;

	xPos = rowStart + distanceBetweenTwoIcon;
	yPos = columnStart + distanceBetweenTwoIcon * 3;

	string orderPosition = "default";

	bool activeUpDownSide = false;
	if(orderPosition == "default"){
	
		for(int i = 0; i < folderNumber; i++){
			
			if(xPos + w < SCREEN_WIDTH ){
				myFolderList[i].setPosition(xPos, yPos);
				xPos += (w + distanceBetweenTwoIcon);
				if(xPos + w +distanceBetweenTwoIcon >= SCREEN_WIDTH){
					xPos = rowStart + distanceBetweenTwoIcon;
					yPos += (h + 2 * distanceBetweenTwoIcon);
				}
			}else{
				activeUpDownSide = true;
				cout << "y height is bigger than normal" <<  endl;
			}
		}

		cout << "and active up down side is:" << activeUpDownSide << endl; 
	
		for(int i = 0; i < fileNumber; i++){
			
			if(xPos + w < SCREEN_WIDTH ){
				myFileList[i].setPosition(xPos, yPos);
				xPos += (w + distanceBetweenTwoIcon);
				if(xPos + w +distanceBetweenTwoIcon >= SCREEN_WIDTH){
					xPos = rowStart + distanceBetweenTwoIcon;
					yPos += (h + 2 * distanceBetweenTwoIcon);
				}
			}else{
				activeUpDownSide = true;
				cout << "y height is bigger than normal" <<  endl;
			}
		}
	}
}

void Computer::getFolderListMembers(int &myFolderListMembers){
	myFolderListMembers = folderNumber;
}
Folder *Computer::getFolderList(){
	return myFolderList;
}

void Computer::getFileListMembers(int &myFileListMembers){
	myFileListMembers = fileNumber;
}
File *Computer::getFileList(){
	return myFileList;
}