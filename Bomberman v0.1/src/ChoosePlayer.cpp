template <class al_b,class al_f>
ChoosePlayer<al_b,al_f>::ChoosePlayer(void){
	this->_readyPlayer[0] = 0;
	this->_readyPlayer[1] = 0;
	this->_avatar[0] = 0;
	this->_avatar[1] = 0;
	this->_background = al_load_bitmap("img/block.jpg");
	this->_1 = al_load_bitmap("img/player/1.png");
	this->_2 = al_load_bitmap("img/player/2.png");
	this->_3 = al_load_bitmap("img/player/3.png");
	this->_4 = al_load_bitmap("img/player/4.png");
	this->_5 = al_load_bitmap("img/player/5.png");
	this->_6 = al_load_bitmap("img/player/6.png");
	this->_font30 = al_load_font("fonts/free_sans.ttf",30,0);
	this->_font20 = al_load_font("fonts/free_sans.ttf",20,0);
}

template <class al_b,class al_f>
ChoosePlayer<al_b,al_f>::~ChoosePlayer(void){
	al_destroy_bitmap(this->_1);
	al_destroy_bitmap(this->_2);
	al_destroy_bitmap(this->_3);
	al_destroy_bitmap(this->_4);
	al_destroy_bitmap(this->_5);
	al_destroy_bitmap(this->_6);
	al_destroy_font(this->_font30);
	al_destroy_font(this->_font20);
}

template <class al_b,class al_f>
int ChoosePlayer<al_b,al_f>::getAvatarCodePlayer1(void){ return this->_avatar[0]; }

template <class al_b,class al_f>	
int ChoosePlayer<al_b,al_f>::getAvatarCodePlayer2(void){ return this->_avatar[1]; }

template <class al_b,class al_f>
bool ChoosePlayer<al_b,al_f>::getReadyPlayer(int p){ return this->_readyPlayer[p]; }

template <class al_b,class al_f>
void ChoosePlayer<al_b,al_f>::setReadyPlayer(int p,bool c){ this->_readyPlayer[p] = c; }

template <class al_b,class al_f>
bool ChoosePlayer<al_b,al_f>::readyPlayer(int p, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	this->_readyPlayer[p] = (this->_readyPlayer[p])? 0 : 1;
	return this->_readyPlayer[p];
}

template <class al_b, class al_f>
void ChoosePlayer<al_b, al_f>::showChoosePlayer(Maps<al_b> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){	
	//m.loadMap(1);
	m.showBackground();

	this->_avatar[0] = (input.getY(0)*3) + (input.getX(0));
	this->_avatar[1] = (input.getY(1)*3) + (input.getX(1));

	al_draw_filled_rectangle(288, 120, 620, 470, al_map_rgb(20,20,20));
	al_draw_filled_rectangle(288, 470, 620, 540, al_map_rgb(255,255,255));
	al_draw_text(this->_font30, al_map_rgb(180,40,40), 315, 130, 0, "Escoge tu personaje");

	for(int y=0;y<m.getHeight();y++){
		for(int x=0;x<m.getWidth();x++){
			if(m.getMap(x,y) == 'x'){ al_draw_filled_rectangle( 310+(100*x), 200+(130*y), 400+(100*x), 320+(130*y), al_map_rgb(255,255,255)); }
			if(input.getX(1) == x && input.getY(1) == y){ al_draw_filled_circle( 385+(100*x), 215+(130*y) ,10, al_map_rgb(60,60,60)); }
			if(input.getX(0) == x && input.getY(0) == y){ al_draw_filled_circle( 325+(100*x), 215+(130*y) ,10, al_map_rgb(140,40,40)); }	 
		}
	}
	al_draw_scaled_bitmap(this->_1, 160, 256, 35, 40, 320, 210, 80, 100, 0);
	al_draw_scaled_bitmap(this->_2, 160, 256, 35, 40, 420, 210, 80, 100, 0);
	al_draw_scaled_bitmap(this->_3, 160, 256, 35, 40, 520, 210, 80, 100, 0);
	al_draw_scaled_bitmap(this->_4, 160, 256, 35, 40, 320, 340, 80, 100, 0);
	al_draw_scaled_bitmap(this->_5, 160, 256, 35, 40, 420, 340, 80, 100, 0);
	al_draw_scaled_bitmap(this->_6, 160, 256, 35, 40, 520, 340, 80, 100, 0);

	al_draw_rectangle(300, 190, 610, 460, al_map_rgb(140,40,40), 3);

	//Leyenda
	al_draw_filled_circle( 320, 490 ,5, al_map_rgb(140,40,40));
	if(this->_readyPlayer[0])	
		al_draw_text(this->_font20, al_map_rgb(0,0,0), 330, 470, 0, "Jugador 1 - Listo");
	else
		al_draw_text(this->_font20, al_map_rgb(0,0,0), 330, 470, 0, "Jugador 1 - Tecla T");
	

	al_draw_filled_circle( 320, 515, 5, al_map_rgb(60,60,60));
	if(this->_readyPlayer[1])
		al_draw_text(this->_font20, al_map_rgb(0,0,0), 330, 500, 0, "Jugador 2 - Listo");
	else
		al_draw_text(this->_font20, al_map_rgb(0,0,0), 330, 500, 0, "Jugador 2 - Tecla P");
}