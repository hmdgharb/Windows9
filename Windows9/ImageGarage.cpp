#include "ImagesGarage.h";
ImageGarage::ImageGarage(const char *ImageFolder, SDL_Renderer *render){

	cout << "-----------------in ImageGarage--------------------" << endl;

	AllLoaded = true;
	string path = ImageFolder;
	string temp = "";

	S_background = S_drive = S_folder = S_image = S_movie = S_text = S_other = S_computer = S_desktop_background = S_desktop = S_newFolder = S_newText = S_up = S_messageBox = S_save = S_cancel = NULL;
	T_background = T_drive = T_folder = T_image = T_movie = T_text = T_other = T_computer = T_desktop_background = T_desktop = T_newFolder = T_newText = T_up = T_messageBox = T_save = T_cancel = NULL;

	temp = path.c_str();
	temp += "\\desktop_background.jpg";
	S_desktop_background = IMG_Load(temp.c_str());
	if(S_desktop_background != NULL){
	
		T_desktop_background = SDL_CreateTextureFromSurface(render, S_desktop_background);
	} else {
		cout << "cannot open " << temp.c_str() << endl;
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\background.jpg";
	S_background = IMG_Load(temp.c_str());
	if(S_background != NULL){
	
		T_background = SDL_CreateTextureFromSurface(render, S_background);
	} else {
		cout << "cannot open " << temp.c_str() << endl;
		AllLoaded = false;
	}


	temp = path.c_str();
	temp += "\\drive.jpg";
	S_drive = IMG_Load(temp.c_str());
	if(S_drive != NULL){
	
		T_drive = SDL_CreateTextureFromSurface(render, S_drive);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}


	temp = path.c_str();
	temp += "\\folder.jpg";
	S_folder = IMG_Load(temp.c_str());
	if(S_folder != NULL){
	
		T_folder = SDL_CreateTextureFromSurface(render, S_folder);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}
	
	temp = path.c_str();
	temp += "\\image.jpg";
	S_image = IMG_Load(".\\..\\Windows9\\image\\image.jpg");
	if(S_image != NULL){
	
		T_image= SDL_CreateTextureFromSurface(render, S_image);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}
	
	temp = path.c_str();
	temp += "\\movie.jpg";
	S_movie = IMG_Load(".\\..\\Windows9\\image\\movie.jpg");
	if(S_movie != NULL){
	
		T_movie= SDL_CreateTextureFromSurface(render, S_movie );
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\text.jpg";
	S_text = IMG_Load(".\\..\\Windows9\\image\\text.jpg");
	if(S_text != NULL){
	
		T_text= SDL_CreateTextureFromSurface(render, S_text );
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}
	
	temp = path.c_str();
	temp += "\\other.jpg";
	S_other = IMG_Load(".\\..\\Windows9\\image\\other.jpg");
	if(S_other != NULL){
	
		T_other = SDL_CreateTextureFromSurface(render, S_other);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\desktop.jpg";
	S_desktop = IMG_Load(".\\..\\Windows9\\image\\desktop.jpg");
	if(S_desktop != NULL){
	
		T_desktop = SDL_CreateTextureFromSurface(render, S_desktop);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\computer.jpg";
	S_computer = IMG_Load(".\\..\\Windows9\\image\\computer.jpg");
	if(S_computer != NULL){
	
		T_computer = SDL_CreateTextureFromSurface(render, S_computer);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\newFolder.jpg";
	S_newFolder = IMG_Load(".\\..\\Windows9\\image\\newFolder.jpg");
	if(S_newFolder != NULL){
	
		T_newFolder = SDL_CreateTextureFromSurface(render, S_newFolder);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}
	
	temp = path.c_str();
	temp += "\\newText.jpg";
	S_newText = IMG_Load(".\\..\\Windows9\\image\\newText.jpg");
	if(S_newText != NULL){
	
		T_newText = SDL_CreateTextureFromSurface(render, S_newText);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	
	temp = path.c_str();
	temp += "\\up.jpg";
	S_up = IMG_Load(".\\..\\Windows9\\image\\up.jpg");
	if(S_up != NULL){
	
		T_up = SDL_CreateTextureFromSurface(render, S_up);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}




	temp = path.c_str();
	temp += "\\messageBox.jpg";
	S_messageBox = IMG_Load(".\\..\\Windows9\\image\\messageBox.jpg");
	if(S_messageBox != NULL){
	
		T_messageBox = SDL_CreateTextureFromSurface(render, S_messageBox);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\save.jpg";
	S_save = IMG_Load(".\\..\\Windows9\\image\\save.jpg");
	if(S_save != NULL){
	
		T_save = SDL_CreateTextureFromSurface(render, S_save);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}

	temp = path.c_str();
	temp += "\\cancel.jpg";
	S_cancel = IMG_Load(".\\..\\Windows9\\image\\cancel.jpg");
	if(S_cancel != NULL){
	
		T_cancel = SDL_CreateTextureFromSurface(render, S_cancel);
	} else {
		cout << "cannot open " << temp.c_str() << endl; 
		AllLoaded = false;
	}


}

bool ImageGarage::isAllImageLoaded(){
	return AllLoaded;
}

void ImageGarage::release(){
	
	//releasing SDL_Surface * files
	if( S_background != NULL){
		SDL_FreeSurface(S_background);
	}

	if(S_drive != NULL){
		SDL_FreeSurface(S_drive);
	}

	if(S_folder != NULL){
		SDL_FreeSurface(S_folder);
	}
	
	if(S_image != NULL){
		SDL_FreeSurface(S_image);
	}
	
	if(S_movie != NULL){
		SDL_FreeSurface(S_movie);
	}
	
	if(S_text != NULL){
		SDL_FreeSurface(S_text);
	}
	
	if(S_other != NULL){
		SDL_FreeSurface(S_other);
	}
	
	if(S_desktop != NULL){
		SDL_FreeSurface(S_desktop);
	}
	
	if(S_desktop_background != NULL){
		SDL_FreeSurface(S_desktop_background);
	}
	
	if(S_computer != NULL){
		SDL_FreeSurface(S_computer);
	}
	
	if(S_newFolder != NULL){
		SDL_FreeSurface(S_newFolder);
	}
	
	if(S_newText != NULL){
		SDL_FreeSurface(S_newText);
	}
	
	if(S_up != NULL){
		SDL_FreeSurface(S_up);
	}
	
	if(S_messageBox != NULL){
		SDL_FreeSurface(S_messageBox);
	}
	
	if(S_save != NULL){
		SDL_FreeSurface(S_save);
	}
	
	if(S_cancel != NULL){
		SDL_FreeSurface(S_cancel);
	}
	//releasing SDL_Texture * files
	if( T_background != NULL){
		SDL_DestroyTexture(T_background);
	}

	if(T_drive != NULL){
		SDL_DestroyTexture(T_drive);
	}
	if(T_folder != NULL){
		SDL_DestroyTexture(T_folder);
	}

	if(T_image != NULL){
		SDL_DestroyTexture(T_image);
	}

	if(T_movie != NULL){
		SDL_DestroyTexture(T_movie);
	}
	
	if(T_text != NULL){
		SDL_DestroyTexture(T_text);
	}
	
	if(T_other != NULL){
		SDL_DestroyTexture(T_other);
	}

	if(T_desktop != NULL){
		SDL_DestroyTexture(T_desktop);
	}
	
	if(T_desktop_background != NULL){
		SDL_DestroyTexture(T_desktop_background);
	}
	
	if(T_computer != NULL){
		SDL_DestroyTexture(T_computer);
	}
	
	if(T_newFolder != NULL){
		SDL_DestroyTexture(T_newFolder);
	}

	if(T_newText != NULL){
		SDL_DestroyTexture(T_newText);
	}
	
	if(T_up!= NULL){
		SDL_DestroyTexture(T_up);
	}

	if(T_messageBox != NULL){
		SDL_DestroyTexture(T_messageBox);
	}

	if(T_save != NULL){
		SDL_DestroyTexture(T_save);
	}
	
	if(T_cancel!= NULL){
		SDL_DestroyTexture(T_cancel);
	}
	cout << "-----------------in ImageGarge::release()--------------------" << endl;
	cout << "all images and textures has been released" << endl;

}

bool ImageGarage::getImageData(int &w, int &h, string n){

	if(n == "background"){
		w = S_background->w;
		h = S_background->h;
		return true;
	} else if(n == "folder"){
		w = S_folder->w;
		h = S_folder->h;
		return true;
	}else if(n == "drive"){
		w = S_drive->w;
		h = S_drive->h;
		return true;
	} else if(n == "image"){
		w = S_image->w;
		h = S_image->h;
		return true;
	} else if(n == "movie"){
		w = S_movie->w;
		h = S_movie->h;
		return true;
	} else if(n == "text"){
		w = S_text->w;
		h = S_text->h;
		return true;
	} else if(n == "other"){
		w = S_other->w;
		h = S_other->h;
		return true;
	} else if(n == "newFolder"){
		w = S_newFolder->w;
		h = S_newFolder->h;
		return true;
	} else if(n == "newText"){
		w = S_newText->w;
		h = S_newText->h;
		return true;
	} else if(n == "desktop"){
		w = S_desktop->w;
		h = S_desktop->h;
		return true;
	} else if(n == "desktop_background"){
		w = S_desktop_background->w;
		h = S_desktop_background->h;
		return true;
	}else if(n == "computer"){
		w = S_computer->w;
		h = S_computer->h;
		return true;
	} else if(n == "up"){
		w = S_up->w;
		h = S_up->h;
		return true;
	} else if(n == "messageBox"){
		w = S_messageBox->w;
		h = S_messageBox->h;
		return true;
	}else if(n == "save"){
		w = S_save->w;
		h = S_save->h;
		return true;
	} else if(n == "cancel"){
		w = S_cancel->w;
		h = S_cancel->h;
		return true;
	}
	return false;
}

SDL_Texture *ImageGarage::getImageTexture(string n){
	if(n == "background"){
		return T_background;
	} else if(n == "folder"){
		return T_folder;
	}else if(n == "drive"){
		return T_drive;
	} else if(n == "image"){
		return T_image;
	} else if(n == "movie"){
		return T_movie;
	} else if(n == "text"){
		return T_text;
	} else if(n == "other"){
		return T_other;
	} else if(n == "newFolder"){
		return T_newFolder;
	} else if(n == "newText"){
		return T_newText;
	} else if(n == "computer"){
		return T_computer;
	} else if(n == "desktop"){
		return T_desktop;
	} else if(n == "desktop_background"){
		return T_desktop_background;
	} else if(n == "up"){
		return T_up;
	}else if(n == "messageBox"){
		return T_messageBox;
	} else if(n == "save"){
		return T_save;
	} else if(n == "cancel"){
		return T_cancel;
	}
	else return NULL;
}

bool ImageGarage::setImageTextureColor(Uint8 red, Uint8 green, Uint8 blue, string name){
	if(name == "background"){
		SDL_SetTextureColorMod( T_background, red, green, blue );
		return true;
	} else if(name == "drive"){
		SDL_SetTextureColorMod( T_drive, red, green, blue );
		return true;
	} else if(name == "folder"){
		SDL_SetTextureColorMod( T_folder, red, green, blue );
		return true;
	} else if(name == "image"){
		SDL_SetTextureColorMod( T_image, red, green, blue );
		return true;
	} else if(name == "movie"){
		SDL_SetTextureColorMod( T_movie, red, green, blue );
		return true;
	} else if(name == "text"){
		SDL_SetTextureColorMod( T_text, red, green, blue );
		return true;
	} else if(name == "other"){
		SDL_SetTextureColorMod( T_other, red, green, blue );
		return true;
	} else if(name == "newFolder"){
		SDL_SetTextureColorMod( T_newFolder, red, green, blue );
		return true;
	} else if(name == "newText"){
		SDL_SetTextureColorMod( T_newText, red, green, blue );
		return true;
	} else if(name == "computer"){
		SDL_SetTextureColorMod( T_computer, red, green, blue );
		return true;
	} else if(name == "desktop"){
		SDL_SetTextureColorMod( T_desktop, red, green, blue );
		return true;
	} else if(name == "desktop_background"){
		SDL_SetTextureColorMod( T_desktop_background, red, green, blue );
		return true;
	} else if(name == "up"){
		SDL_SetTextureColorMod( T_up, red, green, blue );
		return true;
	}else if(name == "messageBox"){
		SDL_SetTextureColorMod( T_messageBox, red, green, blue );
		return true;
	} else if(name == "save"){
		SDL_SetTextureColorMod( T_save, red, green, blue );
		return true;
	} else if(name == "cancel"){
		SDL_SetTextureColorMod( T_cancel, red, green, blue );
		return true;
	}
	else {
		return false;
	}
}