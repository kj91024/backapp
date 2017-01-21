ScreenManager::ScreenManager(void){
	this->_Menu = true;//Menu del juego
	this->_Save = false;
	this->_ChoosePlayer = false;//Escojer el personaje
	this->_ChooseMap = false;//Escojer el mapa
	this->_BeginPlay = false;//Empezar a jugar
	this->_ShowPause = false;
	this->_ShowResults = false; //Resultado del juego
	this->_font20 = al_load_font("fonts/free_sans.ttf",18,0);
}
ScreenManager::~ScreenManager(void){
	//delete this->sm;
	al_destroy_font(this->_font20);
}
bool ScreenManager::isCreateMenu(void){return this->_Menu;  }
bool ScreenManager::isCreateSave(void){return this->_Save;       }
bool ScreenManager::isCreateChoosePlayer(void){return this->_ChoosePlayer;  }
bool ScreenManager::isCreateChooseMap(void){return this->_ChooseMap;    }
bool ScreenManager::isCreateBeginPlay(void){return this->_BeginPlay;     }
bool ScreenManager::isCreateShowPause(void){return this->_ShowPause;     }
bool ScreenManager::isCreateShowResults(void){return this->_ShowResults;   }

void ScreenManager::setMenu(bool c)  {this->_Menu  = c;}
void ScreenManager::setSave(bool c)  {this->_Save = c;}
void ScreenManager::setChoosePlayer(bool c)  {this->_ChoosePlayer  = c;}
void ScreenManager::setChooseMap(bool c)    {this->_ChooseMap  = c;}
void ScreenManager::setBeginPlay(bool c)     {this->_BeginPlay  = c;}
void ScreenManager::setShowPause(bool c)  {this->_ShowPause  = c;}
void ScreenManager::setShowResults(bool c)  {this->_ShowResults  = c;}

void ScreenManager::drawButton(void){
	/*Boton de atras*/
	al_draw_filled_rectangle(10, 620, 150, 660, al_map_rgb(250,250,250));
	al_draw_text(this->_font20, al_map_rgb(0,0,0), 128, 625, 2, "Atras (ESC)");
}
void ScreenManager::restartInput(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	//Player 1
	input.setX(0,0);
	input.setY(0,0);
	//Player 2
	input.setX(1,0);
	input.setY(1,0);

	input.setUserKeyboard(0, true);
	input.setUserKeyboard(1, true);
}
//Virtual Menu
/*int ScreenManager::getButtonSelectMenu(void){ cout << "virtual getButtonSelectMenu"<<endl;}
void ScreenManager::setButtonSelectMenu(int c){ cout << "virtual setButtonSelectMenu"<<endl;}
void ScreenManager::showMenu(Maps<ALLEGRO_BITMAP> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){ cout << "virtual showMenu"<<endl;}
*/