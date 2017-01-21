template <class al_b,class al_f>
Menu<al_b,al_f>::Menu(void){
	this->_icon = al_load_bitmap("img/icon.png");
	this->_font100 = al_load_font("fonts/game_font.ttf",100,0);
	this->_font20 = al_load_font("fonts/free_sans.ttf",18,0);
	this->_font40 = al_load_font("fonts/free_sans.ttf",40,0);
	this->move = true;
	this->_button = 0;
}

template <class al_b,class al_f>
Menu<al_b,al_f>::~Menu(void){
	al_destroy_bitmap(this->_icon);
	al_destroy_font(this->_font100);
	al_destroy_font(this->_font20);
	al_destroy_font(this->_font40);
}

template <class al_b,class al_f>
int Menu<al_b,al_f>::getButtonSelectMenu(void){return this->_button;}

template <class al_b,class al_f>
void Menu<al_b,al_f>::setButtonSelectMenu(int c){this->_button = c;}

template <class al_b,class al_f>
void Menu<al_b,al_f>::showMenu(Maps<al_b> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	m.loadMap(0);
	m.showBackground();
	this->_button = input.getY(0);
	//al_draw_bitmap_region(this->_icon, 85, 110, 85, 110, 410, 160, 0);
	if(this->move){
		for(int i = 100; i <= 230; i = i + 1){
			m.showBackground();
			al_draw_text(this->_font100, al_map_rgb(20,20,20), 270, i, 0, "BomberMan");
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
		this->move = false;
		m.showBackground();
	
	}else
		al_draw_text(this->_font100, al_map_rgb(20,20,20), 270, 230, 0, "BomberMan");
	
	al_draw_text(this->_font40, al_map_rgb(30,30,30), 348, 180, 0, "Deadmatch");
	
	for(int i = 0; i < 3; i++)
		al_draw_filled_rectangle(370, 300+(i*45), 525, 340+(i*45), al_map_rgb(20,20,20));
	
	/*Textos*/
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 425, 303, 0, "Jugar");
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 390, 350, 0, "Cargar Partida");
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 425, 395, 0, "Salir");

	al_draw_rectangle(375, 305+(input.getY(0)*45), 520, 335+(input.getY(0)*45), al_map_rgb(140,40,40), 3);
	//al_draw_rectangle(375, 350, 520, 385, al_map_rgb(140,40,40), 3);
}