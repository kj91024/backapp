template <class al_b,class al_f>
ChooseMap<al_b,al_f>::ChooseMap(void){
	this->_readyPlayer[0] = 0;
	this->_readyPlayer[1] = 0;
	this->_avatar[0] = 0;
	this->_avatar[1] = 0;
	this->_block = al_load_bitmap("img/block.jpg");
	this->_font30 = al_load_font("fonts/free_sans.ttf",30,0);
	this->_font20 = al_load_font("fonts/free_sans.ttf",20,0);
	this->_height = 0;
	this->_width  = 0;
	this->_load = false;
}

template <class al_b,class al_f>
ChooseMap<al_b,al_f>::~ChooseMap(void){
	al_destroy_font(this->_font30);
	al_destroy_font(this->_font20);
}

template <class al_b,class al_f>
void ChooseMap<al_b,al_f>::showChooseMap(Maps<al_b> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	m.showBackground();

	al_draw_text(this->_font30, al_map_rgb(0,0,0), 335, 130, 0, "Escoge un mapa");
	for(int i = 0;i < 3;i++){
		m.loadMap(3,i);
		for(int y = 0; y<m.getHeight();y++){
			for(int x = 0;x<m.getWidth();x++){
		//al_draw_filled_rectangle(80+(250*i)+(12*x), 200+(12*y), 80+(250*i)+((12*x) +12), 200+((12*y )+12), al_map_rgb(255,255,255));

				switch(m.getPositionMap(x,y)){
					case 'p': al_draw_scaled_bitmap(this->_block, 145, 171, 58, 58, 80+(250*i)+(12*x), 200+(12*y), 12, 12, 0);  break;
					case 'j':
					case 'g':
					case 'e': al_draw_filled_rectangle(80+(250*i)+(12*x), 200+(12*y), 80+(250*i)+((12*x) +12), 200+((12*y )+12), al_map_rgb(255,255,255)); break;
					case 'c': al_draw_scaled_bitmap(this->_block, 258, 20, 58, 58, 80+(250*i)+(12*x), 200+(12*y), 12, 12, 0); 	 break;
					case 'd': al_draw_scaled_bitmap(this->_block, 37, 20, 58, 58, 80+(250*i)+(12*x), 200+(12*y), 12, 12, 0); 	 break;
					case 's': al_draw_filled_rectangle(80+(250*i)+(12*x), 200+(12*y), 80+(250*i)+((12*x) +12), 200+((12*y )+12), al_map_rgb(236,236,236)); break;
				}
			}
		}
	}
	m.setLevel(input.getX(0));
	
	al_draw_rectangle(80+(250*input.getX(0)), 200, 320+(250*input.getX(0)), 370, al_map_rgb(140,40,40),5);	
	al_draw_filled_rectangle(360, 385, 540, 430, al_map_rgb(20,20,20));
	al_draw_text(this->_font20, al_map_rgb(255,255,255), 395, 390, 0, "Seleccionar");
}