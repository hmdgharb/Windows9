#include "MessageLinkedList.h"

MessageLinkedList::MessageLinkedList(){
	head = tail = NULL;
	NumberOfMessageInserted = 0;
}
void MessageLinkedList::addMessage(SDL_Renderer *render, const char *text, TTF_Font *ft){

	Message *myMessage = new Message(render, text, ft);
	if(myMessage->isMessageLoaded() == true){
		if(head == NULL){
			head = myMessage;
			tail = myMessage;
			NumberOfMessageInserted++;
		} else if(head == tail && tail != NULL){
			head->setNext(myMessage);
			myMessage->setBefore(head);
			tail = myMessage;
			NumberOfMessageInserted++;
		}
		else{
			tail->setNext(myMessage);
			myMessage->setBefore(tail);
			tail = myMessage;
			NumberOfMessageInserted++;
		}
	} else{
		cout << "Message cannot be created!" << endl;
	}
}
void MessageLinkedList::showContent(){
	Message *counter = head;
	for(int i = 0; i < NumberOfMessageInserted; i++){
		cout << "Message number: " << i << ", text: " << counter->getTextMessage() << endl;
		counter = counter->getNext();
	}
}
Message *  MessageLinkedList::searchList(string text){
	Message *counter = head;
	Message *founded = NULL;
	for(int i = 0; i < NumberOfMessageInserted; i++){
		
		if(text ==  counter->getTextMessage()){
			founded = counter;
			i = NumberOfMessageInserted;
		}
		counter = counter->getNext();
	}

	return founded;
}
void MessageLinkedList::release(){
	Message * counter = head;
	Message * nextCounter;

	for(int i = 0; i < NumberOfMessageInserted; i++){
		counter->setBefore(NULL);
		nextCounter = counter->getNext();
		cout << "one message has been removed: " << counter->getTextMessage() << endl;
		counter->release();
		delete counter;
		counter = nextCounter;
		NumberOfMessageInserted--;
		
	}
	head = tail = NULL;
	counter = nextCounter = NULL;
}