#include "PathAnalysis.h"
#include <stdio.h>
#include <sstream>

PathAnalysis::PathAnalysis(string address){
	temp_dir = opendir(address.c_str()); //for checking that the path is a folder
	
	trueInitialize = true;

	if(!temp_dir){
		cout << "cannot open: " << address.c_str() << endl;
		trueInitialize = false;
	} else{
		closedir(temp_dir); //close it.
		addressPath = address;
	}
}

bool PathAnalysis::reOpenFolder(){
	temp_dir = opendir(addressPath.c_str());
	
	if(!temp_dir){
		cout << "cannot open: " << addressPath.c_str() << endl;
		return false;
	} else{
		return true;
	}
}

bool PathAnalysis::isAnyThingOkey(){
	return trueInitialize;
}

void PathAnalysis::setAddress(string address){
	addressPath = address;
}

string PathAnalysis::getAddress(){
	return addressPath;
}
string PathAnalysis::getFolderListItContains(){
	
	string ListOfFolderNames = "";
	if(reOpenFolder()){
		while(pdir = readdir(temp_dir)){

			if(pdir->d_type == 16384){		//number indicate type of folder
				ListOfFolderNames += pdir->d_name;
				ListOfFolderNames += "|";
			}
		}
		closedir(temp_dir);
	}
	return ListOfFolderNames;
}

string PathAnalysis::getFileListItContains(){
	
	string ListOfFileNames = "";
	if(reOpenFolder()){
		while(pdir = readdir(temp_dir)){
			if(pdir->d_type == 32768){		//number indicate type of file
				ListOfFileNames += pdir->d_name;
				ListOfFileNames += "|";
				//cout << pdir->d_name << " " << pdir->d_type << endl;
			}
		}
		closedir(temp_dir);
	}
	return ListOfFileNames;
}

void PathAnalysis::addToPath(string nm){
	if(nm != ""){
		addressPath += nm.c_str();
		addressPath += "\\";
	}else{
		cout << " the empty added path is not legal! " << endl;
	}
}

void PathAnalysis::removeFromPath(){
	
	string temp = "";
	int size = 12;
	size = addressPath.size();
	cout << "size of address: " << size << endl;
	
	char *okey = (char *)malloc(sizeof(char)*size);

	strcpy(okey, addressPath.c_str());

	string tempy = okey;

	string result="";
	stringstream addressStream( tempy );
	string traversedPath;
	int counter = 0;

	while(addressStream.good()){
		counter++;
		string temp2;
		getline(addressStream, temp2, '\\');
		cout <<counter<< " " << temp2 << endl;
		if(temp2 != ""){
			result = traversedPath;
			traversedPath += temp2;
			traversedPath +="\\";
		}
	}
	//if(result != "")
		addressPath = result;
}