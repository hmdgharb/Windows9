#include "dirent.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef PATHANALYSIS_H
#define PATHANALYSIS_H
class PathAnalysis{

	DIR *temp_dir;
	struct dirent *pdir;

	string addressPath;

	bool trueInitialize;
	bool reOpenFolder();

public:
	PathAnalysis(string address);
	bool isAnyThingOkey();
	void setAddress(string address);
	string getAddress();
	string getFolderListItContains();
	string getFileListItContains();
	void addToPath(string n);
	void removeFromPath();
};
#endif