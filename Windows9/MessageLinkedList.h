#include "Message.h"

#ifndef MESSAGELINKEDLIST_H
#define MESSAGELINKEDLIST_H
class MessageLinkedList{
	Message * head;
	Message * tail;
	int NumberOfMessageInserted;
public:
	MessageLinkedList();
	void addMessage(SDL_Renderer *render, const char *text, TTF_Font *ft);
	void showContent();
	void release();
	Message * searchList(string text);
};
#endif