#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

#ifndef IMAGEGARAGE_H
#define IMAGEGARAGE_H
class ImageGarage{

	bool AllLoaded;
	
	SDL_Surface * S_background;
	SDL_Texture * T_background;
	
	SDL_Surface * S_drive;
	SDL_Texture * T_drive;
	
	SDL_Surface * S_folder;
	SDL_Texture * T_folder;
	
	SDL_Surface * S_image;
	SDL_Texture * T_image;

	SDL_Surface * S_movie;
	SDL_Texture * T_movie;
	
	SDL_Surface * S_text;
	SDL_Texture * T_text;
	
	SDL_Surface * S_other;
	SDL_Texture * T_other;
	
	SDL_Surface * S_desktop;
	SDL_Texture * T_desktop;

	SDL_Surface * S_desktop_background;
	SDL_Texture * T_desktop_background;

	SDL_Surface * S_computer;
	SDL_Texture * T_computer;

	SDL_Surface * S_newFolder;
	SDL_Texture * T_newFolder;

	SDL_Surface * S_newText;
	SDL_Texture * T_newText;

	SDL_Surface * S_up;
	SDL_Texture * T_up;

	SDL_Surface * S_messageBox;
	SDL_Texture * T_messageBox;

	SDL_Surface * S_save;
	SDL_Texture * T_save;

	SDL_Surface * S_cancel;
	SDL_Texture * T_cancel;
public:
	ImageGarage(const char *ImageFolder, SDL_Renderer * render);
	bool isAllImageLoaded();
	bool getImageData(int &w, int &h, string n);
	bool setImageTextureColor(Uint8 red, Uint8 green, Uint8 blue, string name);
	SDL_Texture * getImageTexture(string n);
	void release();
};

#endif