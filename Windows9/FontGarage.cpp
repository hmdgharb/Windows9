#include "FontGarage.h"

FontGarage::FontGarage(const char * fontFolder, int size){
	
	AllLoaded = true;
	Allber_Bd = Aller_BdIt = Aller_It = Aller_Lt = Aller_LtIt = Aller_Rg = AllerDisplay = grasping = NULL;
	Size = size;
	strcpy(path,fontFolder);
	string name = path;

	name +=  "\\Allber_Bd.ttf";
	Allber_Bd = TTF_OpenFont(name.c_str(), Size);
	if(Allber_Bd == NULL){
		AllLoaded = false;
	}
	
	name = path;
	name +=  "\\Aller_BdIt.ttf";
	Aller_BdIt = TTF_OpenFont(name.c_str(), Size);
	if(Aller_BdIt == NULL){
		AllLoaded = false;
	}
	
	name = path;
	name +=  "\\Aller_It.ttf";
	Aller_It = TTF_OpenFont(name.c_str(), Size);
	if(Aller_It == NULL){
		AllLoaded = false;
	}

	name = path;
	name +=  "\\Aller_Lt.ttf";
	Aller_Lt = TTF_OpenFont(name.c_str(), Size);
	if(Aller_Lt == NULL){
		AllLoaded = false;
	}

	name = path;
	name +=  "\\Aller_LtIt.ttf";
	Aller_LtIt = TTF_OpenFont(name.c_str(), Size);
	if(Aller_LtIt == NULL){
		AllLoaded = false;
	}

	name = path;
	name +=  "\\Aller_Rg.ttf";
	Aller_Rg = TTF_OpenFont(name.c_str(), Size);
	if(Aller_Rg == NULL){
		AllLoaded = false;
	}

	name = path;
	name +=  "\\AllerDisplay.ttf";
	AllerDisplay = TTF_OpenFont(name.c_str(), Size);
	if(AllerDisplay == NULL){
		AllLoaded = false;
	}

	name = path;
	name +=  "\\grasping.ttf";
	grasping = TTF_OpenFont(name.c_str(), Size);
	if(grasping == NULL){
		AllLoaded = false;
	}
}

bool FontGarage::isAllFontLeaded(){
	return AllLoaded;
}

void FontGarage::release(){

	if(Allber_Bd != NULL){
		TTF_CloseFont( Allber_Bd );
		Allber_Bd = NULL;
	}

	if(Aller_BdIt != NULL){
		TTF_CloseFont( Aller_BdIt );
		Aller_BdIt = NULL;
	}
	if(Aller_It != NULL){
		TTF_CloseFont( Aller_It );
		Aller_It = NULL;
	}
	if(Aller_Lt != NULL){
		TTF_CloseFont( Aller_Lt );
		Aller_Lt = NULL;
	}
	if(Aller_LtIt != NULL){
		TTF_CloseFont( Aller_LtIt );
		Aller_LtIt = NULL;
	}
	if(Aller_Rg != NULL){
		TTF_CloseFont( Aller_Rg );
		Aller_Rg = NULL;
	}
	if(AllerDisplay != NULL){
		TTF_CloseFont( AllerDisplay );
		AllerDisplay = NULL;
	}
	if(grasping != NULL){
		TTF_CloseFont( grasping );
		grasping = NULL;
	}

	cout << "all font has been released" << endl;
}

TTF_Font * FontGarage::getFont(string nm){
	string name;
//	cout << "font name: " << nm << endl;
	if(nm == "Allber_Bd"){

		return Allber_Bd;
	}
	if(nm == "Aller_BdIt"){

		return Aller_BdIt;
	}
	if(nm == "Aller_It"){

		return Aller_It;
	}
	if(nm == "Aller_Lt"){

		return Aller_Lt;
	}
	if(nm == "Aller_LtIt"){

		return Aller_LtIt;
	}
	if(nm == "Aller_Rg"){

		return Aller_Rg;
	}

	if(nm == "AllerDisplay"){

		return AllerDisplay;
	}
	if(nm == "grasping"){

		return Allber_Bd;
	}
}