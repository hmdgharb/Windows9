#include "ImagesGarage.h"
#include "FontGarage.h"
#include "MessageLinkedList.h"
#include <vector>

#ifndef GRAPHIC_H
#define GRAPHIC_H
 
class Graphic{
	
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Renderer * renderer;
	SDL_Window * window;

	ImageGarage * image;
	FontGarage * font;
	
	MessageLinkedList * messageList;

	SDL_Event graphicEvent;

	bool trueInitialize;

	void InitialErrorHasOccurried();
	void InitialImageErrorHasOccurried();
	void InitialFontErrorHasOccurrid();
	void applyTexture(int x, int y, int w, int h, SDL_Texture *source);
	void applyMessage(string messageText, string messageType, int size);

public:
	void scaleTexture(int x, int y, int w, int h, SDL_Texture *source);
	Graphic();
	bool isAnyThingOkey();
	void setCaption(const char *n);
	void clearScreen();
	void addImageToWindow(int x, int y, string n, bool state, char * type = NULL);
	void scaleImageToWindow(int x, int y, int w, int h, string name);
	void addMessageToWindow(int x, int y, string messageText, string messageType);
	void display();
	SDL_Event *getEvent();
	void getScreenWidthHeight(int &width, int &height);
	void Shutdown();
	void getData(int &w, int &h, string n);
	void resetNewMessage(string message, string fontName);
	void displayNewMessage(int x, int y);
	void activeInputText();
	void deactiveInputText();
	void releaseMessageLinkedList();
};
#endif