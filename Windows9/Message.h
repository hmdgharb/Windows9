#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

#ifndef MESSAGE_H
#define MESSAGE_H
class Message {
	Message * next;
	Message * before;

	SDL_Surface * S_message;
	SDL_Texture * T_message;
	bool messageLoaded;
	char textMessage[256];
public:
	Message(SDL_Renderer *render, const char *text, TTF_Font *ft);
	void setNext(Message * next);
	void setBefore(Message * before);
	Message * getNext();
	Message * getBefore();
	const char * getTextMessage();
	void release();
	bool isMessageLoaded();
	void getWidthHeight(int &w, int &h);
	SDL_Texture *getMessageTexture();
};
#endif