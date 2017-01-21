template <class al_f>
CreateResults<al_f>::CreateResults(void){	this->_font50 = al_load_font("fonts/game_font.ttf",40,0);}

template <class al_f>
CreateResults<al_f>::~CreateResults(void){ al_destroy_font(this->_font50);}

template <class al_f>
void CreateResults<al_f>::showResults(Player<ALLEGRO_BITMAP> &p){
	if(p.winnerPlayer() != -1 && p.loserPlayer() != -1){
	al_draw_filled_rectangle(400, 110, 550, 155, al_map_rgb(100,50,50));
	al_draw_filled_rectangle(400, 160, 550, 330, al_map_rgb(255,255,255));
	al_draw_filled_rectangle(400, 335, 550, 380, al_map_rgb(0,0,0));
	al_draw_rectangle(410, 170, 540, 290, al_map_rgb(0,0,0), 3);

	al_draw_rectangle(390, 100, 560, 390, al_map_rgb(255,255,255), 3);

	al_draw_scaled_bitmap(p.getAvatar(p.winnerPlayer()), 163, 300, 25, 45, 445, 190, 60, 100, 0);

	al_draw_text(this->_font50, al_map_rgb(255,255,255), 430, 120, 0, "Winner");
	if(p.winnerPlayer() == 0)
		al_draw_text(this->_font50, al_map_rgb(0,0,0), 415, 300, 0, "Jugador 1");	
	else
		al_draw_text(this->_font50, al_map_rgb(0,0,0), 415, 300, 0, "Jugador 2");	

	al_draw_text(this->_font50, al_map_rgb(255,255,255), 410, 345, 0, "Continuar");

	/*cout << "Ganador" << p.winnerPlayer() << endl;
	cout << "Perdedor" << p.loserPlayer() << endl;*/	
	}else
		cout << "Error" << endl;
}