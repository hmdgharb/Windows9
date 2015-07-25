#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

#ifndef FONTGARAGE_H
#define FONTGARAGE_H
class FontGarage{
	
	char path[512];
	TTF_Font * Allber_Bd;
	TTF_Font * Aller_BdIt;
	TTF_Font * Aller_It;
	TTF_Font * Aller_Lt;
	TTF_Font * Aller_LtIt;
	TTF_Font * Aller_Rg;
	TTF_Font * AllerDisplay;
	TTF_Font * grasping;

	int Size;
	
	bool AllLoaded;
public:
	FontGarage(const char * fontFolder, int size);
	bool isAllFontLeaded();
	void release();
	TTF_Font * getFont(string nm);
};
#endif