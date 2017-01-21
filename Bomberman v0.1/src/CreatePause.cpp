template <class al_f>
CreatePause<al_f>::CreatePause(void){
	this->_font50 = al_load_font("fonts/game_font.ttf",40,0);
	this->_font20 = al_load_font("fonts/free_sans.ttf",18,0);
	this->_button = 0;
}

template <class al_f>
CreatePause<al_f>::~CreatePause(void){
	al_destroy_font(this->_font50);
}

template <class al_f>
int CreatePause<al_f>::getButtonSelectPause(void){return this->_button;}

template <class al_f>
void CreatePause<al_f>::setButtonSelectPause(int c){this->_button = c;}

template <class al_f>
void CreatePause<al_f>::showPause(Player<ALLEGRO_BITMAP> &p,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	al_draw_filled_rectangle(360, 180, 540, 380, al_map_rgb(20,20,20));
	al_draw_text(this->_font50, al_map_rgb(255,255,255), 405, 195, 0, "Pausa");

	for(int i=0; i<3;i++)
		al_draw_filled_rectangle(370, 230+(50*i), 530, 270+(50*i), al_map_rgb(40,40,40));
	
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 410, 235, 0, "Continuar");
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 390, 285, 0, "Guardar Partida");
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 430, 335, 0, "Salir");

	al_draw_rectangle(375, 235+(50*input.getY(0)), 525, 265+(50*input.getY(0)), al_map_rgb(140,40,40),3);
	this->_button = input.getY(0);
}