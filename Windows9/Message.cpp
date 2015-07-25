#include "Message.h"

Message::Message(SDL_Renderer *render, const char *text, TTF_Font *ft){
	
	messageLoaded = true;
	
	next = before = NULL;
	strcpy(textMessage, text);
	SDL_Color textColor = {0, 0, 0};
	S_message = NULL;
	S_message = TTF_RenderText_Solid( ft, text, textColor );
	if(S_message == NULL){
		messageLoaded = false;
	} else{
			T_message = SDL_CreateTextureFromSurface( render, S_message);
	
	}
}
const char *Message::getTextMessage(){
	return textMessage;
}
void Message::setNext(Message * next){
	this->next = next;
}
void Message::setBefore(Message * before){
	this->before = before;
}

Message * Message::getNext(){
	return next;
}
Message * Message::getBefore(){
	return before;
}

bool Message::isMessageLoaded(){
	return messageLoaded;
}

void Message::release(){
	
	if( S_message != NULL){
		SDL_FreeSurface(S_message);
	}
	if(T_message!= NULL){
		SDL_DestroyTexture(T_message);
	}
}

void Message::getWidthHeight(int &w, int &h){
	if(S_message != NULL){
		w = S_message->w;
		h = S_message->h;
	} else{
		w = 0;
		h = 0;
	}
}

SDL_Texture * Message::getMessageTexture(){
	return T_message;
}