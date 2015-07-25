#include "Graphic.h"

SDL_Texture * T_newmessage;
SDL_Surface * S_newmessage;
Graphic::Graphic(){

	cout << "-----------------in Graphic()--------------------" << endl;
	T_newmessage = NULL;
	S_newmessage = NULL;
	trueInitialize = true;
	SCREEN_HEIGHT = 480;
	SCREEN_WIDTH = 640;
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		InitialErrorHasOccurried();

	if(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") < 0)
		InitialErrorHasOccurried();

	//creating our window for 
	window = NULL;
	window = SDL_CreateWindow("Window 9", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH , SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if(window == NULL)
		InitialErrorHasOccurried();
	

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
		InitialErrorHasOccurried();

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	int imgFlags = IMG_INIT_JPG;
	if(! (IMG_Init(imgFlags) & imgFlags))
		InitialImageErrorHasOccurried();

	if(	TTF_Init() < 0)
		InitialFontErrorHasOccurrid();
	
	font = NULL;
	
	font = new FontGarage(".\\..\\Windows9\\font", 12);
	if(font->isAllFontLeaded() == false)
		InitialFontErrorHasOccurrid();
	else
		cout << "font has been loaded." << endl;


	image = NULL;
	image = new ImageGarage(".\\..\\Windows9\\image", renderer);
	if(image->isAllImageLoaded() == false)
		trueInitialize = false;
	else
		cout << "all image has been loaded." << endl;

	messageList = NULL;
	messageList = new MessageLinkedList();
	if(messageList == NULL)
		trueInitialize = false;
	else
		cout << "message list has been created." << endl;
}

void Graphic::InitialErrorHasOccurried(){
	printf("Error for creating window: %s\n", SDL_GetError());
	trueInitialize = false;
}
	
void Graphic::InitialImageErrorHasOccurried(){
	printf("SDL_image could not initlialize! SDL_image Error: %s\n", IMG_GetError());
	trueInitialize = false;
}

void Graphic::InitialFontErrorHasOccurrid(){
	 printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	trueInitialize = false;
}

bool Graphic::isAnyThingOkey(){

	return trueInitialize;
}

void Graphic::Shutdown(){

	cout << "-----------------in Graphic::Shutdown()--------------------" << endl;
	if(messageList != NULL){

		messageList->release();
		delete messageList;
		messageList = NULL;
	}
	if(image != NULL){
		image->release();
		delete image;
		image = NULL;
	}

	if(font != NULL){
		 font->release();
		 delete font;
		 font = NULL;
	}

	if(renderer != NULL){
		SDL_DestroyRenderer( renderer );
		renderer = NULL;
	}
	if(window != NULL){
		SDL_DestroyWindow( window );
		window = NULL;
	}

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	cout << "graphic has been shutdown." << endl;
}

void Graphic::setCaption(const char *n){
	SDL_SetWindowTitle(window, n);

}

void Graphic::applyTexture(int x, int y, int w, int h, SDL_Texture *source){
	
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	offset.w = w;
	offset.h = h;
	
	SDL_RenderCopy(renderer, source, 0, &offset);
}

void Graphic::scaleTexture(int x, int y, int w, int h, SDL_Texture *source){
	
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	offset.w = w;
	offset.h = h;
	
	SDL_RenderCopy(renderer, source, &offset, 0);
}

void Graphic::clearScreen(){
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( renderer );
}

void Graphic::display(){

	SDL_RenderPresent(renderer);
}

SDL_Event *Graphic::getEvent(){
	return &graphicEvent;
}

void Graphic::addImageToWindow(int x, int y, string n, bool state, char * type){
	int w = 0;
	int h = 0;
	if(image == NULL){
		cout << "image is null" << endl;
	} else if (type != NULL){

		string eq = type;
		if(eq == "full screen"){
			SDL_GetWindowSize(window, &w, &h);
			SCREEN_WIDTH = w;
			SCREEN_HEIGHT = h;
			if(state == true){
				image->setImageTextureColor(255, 255, 255, n);
			}else
				image->setImageTextureColor(200, 200, 200, n);
	
			scaleTexture(x, y, w, h, image->getImageTexture(n));
		}
	}else {
		if( image->getImageData(w, h, n) == true){
			if(state == true){
				image->setImageTextureColor(255, 255, 255, n);
			}else
				image->setImageTextureColor(200, 200, 200, n);
		
			applyTexture(x, y, w, h, image->getImageTexture(n));
		}
		else 
			cout << "image: " << n << " is not exist in our ImageGarage!" << endl;
	}
}
void Graphic::scaleImageToWindow(int x, int y, int w, int h, string name){
	scaleTexture(x, y, w, h, image->getImageTexture(name));
}
void Graphic::addMessageToWindow(int x, int y, string messageText, string messageType){

	if(font == NULL){
		cout << "font is not created" << endl;
	}
	else if(messageList == NULL) {
			cout << "message list is not created" << endl;
	}
	else{
		Message *f = NULL;
		f = messageList->searchList(messageText);
		if(f == NULL){
			messageList->addMessage(renderer, messageText.c_str(), font->getFont(messageType));
			cout << "new message added to our messageList, text: "<< messageText.c_str() << endl;
		}
		else{
			int w, h;
			f->getWidthHeight(w, h);
			applyTexture(x, y, w, h, f->getMessageTexture()); 
		}
	}
}
void Graphic::getData(int &x, int &y, string n){

	image->getImageData(x, y, n);
}
void Graphic::getScreenWidthHeight(int &width, int &height){
	SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
}

void Graphic::activeInputText(){
	SDL_StartTextInput();
}

void Graphic::deactiveInputText(){
	SDL_StopTextInput();
}

void Graphic::displayNewMessage(int x, int y){
	if(T_newmessage != NULL)
		applyTexture(x, y, S_newmessage->w, S_newmessage->h, T_newmessage);
	else
		cout << "new message is null" << endl;
}
void Graphic::resetNewMessage(string message, string fontName){
	
	cout << "message: " << message.c_str() << endl;
	if(S_newmessage != NULL){
		SDL_FreeSurface(S_newmessage);
	}
	if(T_newmessage != NULL){
		SDL_DestroyTexture(T_newmessage);
		T_newmessage = NULL;
	}
	
	SDL_Color color = {255, 255, 255};
	S_newmessage = TTF_RenderText_Solid(font->getFont(fontName), message.c_str(), color);
	T_newmessage =  SDL_CreateTextureFromSurface(renderer, S_newmessage);
	//SDL_FreeSurface(S_newmessage);
}

void Graphic::releaseMessageLinkedList(){
	messageList->release();
}