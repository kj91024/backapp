template <class al_b,class al_f>
CreatePlay<al_b, al_f>::CreatePlay(void){
	this->_block = al_load_bitmap("img/block.jpg");
	this->_bw = 45;
	this->_bh = 45;
	this->_loadMapPlayer=false;
	this->_x[0] = 0;
	this->_x[1] = 0;
	this->_y[0] = 0;
	this->_y[1] = 0;
	this->_font40 = al_load_font("fonts/game_font.ttf",40,0);
	this->_noAnimate = false;
}

template <class al_b,class al_f>
CreatePlay<al_b, al_f>::~CreatePlay(void){
	al_destroy_bitmap(this->_block);
	al_destroy_font(this->_font40);
}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::setNoAnimatePlay(bool c){this->_noAnimate = c;}

template <class al_b,class al_f>
bool CreatePlay<al_b, al_f>::getNoAnimatePlay(void){return this->_noAnimate;}

template <class al_b,class al_f>
char CreatePlay<al_b, al_f>::getMap(int x, int y){return this->temp_map[y][x];}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::setMap(int x, int y,char p){this->temp_map[y][x] = p;}

template <class al_b,class al_f>
char CreatePlay<al_b, al_f>::getUpdateX(int p){return this->_x[p];}

template <class al_b,class al_f>
char CreatePlay<al_b, al_f>::getUpdateY(int p){return this->_y[p];}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::setLoadMapPlayer(bool p){this->_loadMapPlayer = p;}

template <class al_b,class al_f>
bool CreatePlay<al_b, al_f>::getLoadMapPlayer(void){return this->_loadMapPlayer;}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::downloadMapPlayer(Maps<al_b> &m,Player<al_b> &p){
	if(!this->_loadMapPlayer){
	    m.loadMap(3,m.getLevel());
	    for(int y = 0; y < m.getHeight(); y++){
	    	for(int x = 0; x < m.getWidth(); x++){
			    this->temp_map[y][x] = m.getMap(x,y);
			    switch(m.getMap(x,y)){
			    	case 'j': p.setX(0,x); p.setY(0,y); p.setLastX(0,x); p.setLastY(0,y); p.setDir(0,0);break;
			    	case 'g': p.setX(1,x); p.setY(1,y); p.setLastX(1,x); p.setLastY(1,y); p.setDir(1,0);break;
			    }
	    	}
	    }
	    this->_loadMapPlayer = true;
	   }
}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::showPlay(Maps<al_b> &m,Player<al_b> &p,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	if(this->temp_map[p.getY(0)][p.getX(0)] == 'p' || this->temp_map[p.getY(0)][p.getX(0)] == 'd' || this->temp_map[p.getY(0)][p.getX(0)] == 'c' || this->temp_map[p.getY(0)][p.getX(0)] == 'z'|| this->temp_map[p.getY(0)][p.getX(0)] == 'g'|| this->temp_map[p.getY(0)][p.getX(0)] == 'y'){
		switch(p.getDir(0)){
			case 0: p.decY(0); break; // Abajo
			case 1: p.incX(0); break; // Izquierda
			case 2: p.incY(0); break; // Arriba
			case 3: p.decX(0); break; // Derecha
		}
		p.setLastX(0,p.getX(0));
		p.setLastY(0,p.getY(0));
	}
	if(this->temp_map[p.getY(1)][p.getX(1)] == 'p' || this->temp_map[p.getY(1)][p.getX(1)] == 'd' || this->temp_map[p.getY(1)][p.getX(1)] == 'c' || this->temp_map[p.getY(1)][p.getX(1)] == 'z' || this->temp_map[p.getY(1)][p.getX(1)] == 'j'|| this->temp_map[p.getY(1)][p.getX(1)] == 'x'){
		switch(p.getDir(1)){
			case 0: p.decY(1); break; // Abajo
			case 1: p.incX(1); break; // Izquierda
			case 2: p.incY(1); break; // Arriba
			case 3: p.decX(1); break; // Derecha
		}
		p.setLastX(1,p.getX(1));
		p.setLastY(1,p.getY(1));
	}
	
	if(this->temp_map[p.getY(0)][p.getX(0)] == 'k' || this->temp_map[p.getY(0)][p.getX(0)] == 'm' || this->temp_map[p.getY(0)][p.getX(0)] == 'n' || this->temp_map[p.getY(0)][p.getX(0)] == 'o' || this->temp_map[p.getY(0)][p.getX(0)] == 't'){
		input.setUserKeyboard(0, false);
		input.setUserKeyboard(1, false);
		p.loserPlayer(0);
		p.winnerPlayer(1);
		this->temp_map[p.getY(0)][p.getX(0)] = '0';
	}else if(this->temp_map[p.getY(0)][p.getX(0)] == '0' || this->temp_map[p.getY(0)][p.getX(0)] == '1' || this->temp_map[p.getY(0)][p.getX(0)] == '2' || this->temp_map[p.getY(0)][p.getX(0)] == '3' || this->temp_map[p.getY(0)][p.getX(0)] == '4' || this->temp_map[p.getY(0)][p.getX(0)] == '5'){
		// Para que no pase al siguiente :v
	}else if(p.getX(0) != p.getLastX(0) || p.getY(0) != p.getLastY(0) ){
		if(this->temp_map[p.getLastY(0)][p.getLastX(0)] == 'x'){
			this->temp_map[p.getLastY(0)][p.getLastX(0)] = 'z';	
		}else{
			this->temp_map[p.getLastY(0)][p.getLastX(0)] = 'e';
		}
		this->temp_map[p.getY(0)][p.getX(0)] = 'j';
	}

	if(this->temp_map[p.getY(1)][p.getX(1)] == 'k' || this->temp_map[p.getY(1)][p.getX(1)] == 'm' || this->temp_map[p.getY(1)][p.getX(1)] == 'n' || this->temp_map[p.getY(1)][p.getX(1)] == 'o' || this->temp_map[p.getY(1)][p.getX(1)] == 't'){
		input.setUserKeyboard(0, false);
		input.setUserKeyboard(1, false);
		p.loserPlayer(1);
		p.winnerPlayer(0);
		this->temp_map[p.getY(1)][p.getX(1)] = '6';
	}else if(this->temp_map[p.getY(1)][p.getX(1)] == '6' || this->temp_map[p.getY(1)][p.getX(1)] == '7' || this->temp_map[p.getY(1)][p.getX(1)] == '8' || this->temp_map[p.getY(1)][p.getX(1)] == '9' || this->temp_map[p.getY(1)][p.getX(1)] == 'a' || this->temp_map[p.getY(1)][p.getX(1)] == 'b'){
		// Para que no pase al siguiente :v
	}else if(p.getX(1) != p.getLastX(1) || p.getY(1) != p.getLastY(1) ){
		if(this->temp_map[p.getLastY(1)][p.getLastX(1)] == 'y'){
			this->temp_map[p.getLastY(1)][p.getLastX(1)] = 'z';
		}else{
			this->temp_map[p.getLastY(1)][p.getLastX(1)] = 'e';
		}
		this->temp_map[p.getY(1)][p.getX(1)] = 'g';
	}

	p.setLastX(0, p.getX(0));
	p.setLastY(0, p.getY(0));

	p.setLastX(1, p.getX(1));
	p.setLastY(1, p.getY(1));

	this->showCreatePlay(m,p,input);
}

template <class al_b,class al_f>
void CreatePlay<al_b, al_f>::showCreatePlay(Maps<al_b> &m,Player<al_b> &p,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	if(!this->_noAnimate){
		for(int y = 0; y < m.getHeight(); y++){
		    for(int x = 0; x < m.getWidth(); x++){
		    	switch(this->temp_map[y][x]){
				    // Animacion de la explosion de la bomba
				    case 'k': this->temp_map[y][x] = 'm';break;
				    case 'm': this->temp_map[y][x] = 'n';break;
				    case 'n': this->temp_map[y][x] = 'o';break;
				    case 'o': this->temp_map[y][x] = 't';break;
				    case 't': this->temp_map[y][x] = 'e';break;
				    // Animacion de explosion de Player 1
				    case '0': this->temp_map[y][x] = '1';break;
				    case '1': this->temp_map[y][x] = '2';break;
				    case '2': this->temp_map[y][x] = '3';break;
				    case '3': this->temp_map[y][x] = '4';break;
				    case '4': this->temp_map[y][x] = '5';break;
				    // Animacion de explosion de Player 2
				    case '6': this->temp_map[y][x] = '7';break;
				    case '7': this->temp_map[y][x] = '8';break;
				    case '8': this->temp_map[y][x] = '9';break;
				    case '9': this->temp_map[y][x] = 'a';break;
				    case 'a': this->temp_map[y][x] = 'b';break;
		    	}
		    }
    	}
		
		if(p.existBombPrint()){
			for(int i = 0;i<p.getMaxBomb();i++){
				if(p.getBombPrint(i) == 1){ 
					switch(p.getBombPlayer(i)){
						case 0:
							if(p.getBombY(i) == p.getLastY(0) && p.getBombX(i) == p.getLastX(0)) 
								this->temp_map[p.getBombY(i)][p.getBombX(i)] = 'x';
							else 
								this->temp_map[p.getBombY(i)][p.getBombX(i)] = 'z';
							break;

						case 1:
							if(p.getBombY(i) == p.getLastY(1) && p.getBombX(i) == p.getLastX(1)) 
								this->temp_map[p.getBombY(i)][p.getBombX(i)] = 'y';
							else 
								this->temp_map[p.getBombY(i)][p.getBombX(i)] = 'z';	
							break;	    	
					}
			    	p.setBombPrint(i, 0);
			    }
		    }
		}

		if(p.existBombNoPrint()){
			for(int i = 0;i<p.getMaxBomb();i++){
				if(p.getBombPrint(i) == 0 && p.getBombTimer(i) > 0){
					p.decBombTimer(i);
				}else if(p.getBombTimer(i) == 0){
					int a, b;
					a = p.getBombX(i);
					b = p.getBombY(i);
					this->temp_map[b][a] = 'k';

					for(int x = a-1;x>a-3;x--){
						if( x < 0 || x>m.getWidth())
					    	continue;
					    else if(this->temp_map[b][x] == 'p' || this->temp_map[b][x] == 'c')
					    	break;
					    this->temp_map[b][x] = 'k';
					}
					
					for(int x = a+1;x<a+3;x++){
					    if( x < 0 || x>m.getWidth())
					    	continue;
					    else if(this->temp_map[b][x] == 'p' || this->temp_map[b][x] == 'c')
					    	break;
					    this->temp_map[b][x] = 'k';
					}
					for(int y = b-1;y>b-3;y--){
					    if( y < 0 || y>m.getHeight())
					    	continue;
					    else if(this->temp_map[y][a] == 'p' || this->temp_map[y][a] == 'c')
					    	break;
					    this->temp_map[y][a] = 'k';
					}
					
					for(int y = b+1;y<b+3;y++){
					    if( y < 0)
					    	continue;
					    else if(this->temp_map[y][a] == 'p' || this->temp_map[y][a] == 'c')
					    	break;
					    this->temp_map[y][a] = 'k';
					}
					p.deleteBomb(i);
				}
			}	
		}
	}

	for(int y = 0;y<m.getHeight();y++){
		for(int x = 0;x<m.getWidth();x++){
			switch(this->temp_map[y][x]){
				case 'p': al_draw_scaled_bitmap(this->_block, 145, 171, 58, 58, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);  break;
				case 'e': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); break;
				case 'c': al_draw_scaled_bitmap(this->_block, 258, 20, 58, 58, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0); 	 break;
				case 'd': al_draw_scaled_bitmap(this->_block, 37, 20, 58, 58, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0); 	 break;
				case 's': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(236,236,236)); break;

				case 'j': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), p.getSource(0), 40*p.getDir(0), 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0); break;
				case 'g': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(1), p.getSource(1), 40*p.getDir(1), 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0); break;

				case 'x': p.drawBomb(x,y,this->_bw,this->_bh); al_draw_scaled_bitmap(p.getAvatar(0), p.getSource(0), 40*p.getDir(0), 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;// Jugador 1 sobre la bomba
				case 'y': p.drawBomb(x,y,this->_bw,this->_bh); al_draw_scaled_bitmap(p.getAvatar(1), p.getSource(1), 40*p.getDir(1), 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;// Jugador 2 sobre la bomba

				case 'z': p.drawBomb(x,y,this->_bw,this->_bh); break;
				case 'k': p.drawBomb0(x,y,this->_bw,this->_bh); break;
			    case 'm': p.drawBomb1(x,y,this->_bw,this->_bh); break;
			    case 'n': p.drawBomb2(x,y,this->_bw,this->_bh); break;
			    case 'o': p.drawBomb3(x,y,this->_bw,this->_bh); break;
			    case 't': p.drawBomb4(x,y,this->_bw,this->_bh); break;

			    case '0': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 92, 160, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '1': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 125, 160, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '2': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 155, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '3': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 188, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '4': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 225, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '5': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); break;

				case '6': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 92, 160, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '7': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 125, 160, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '8': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 155, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case '9': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 188, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case 'a': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); al_draw_scaled_bitmap(p.getAvatar(0), 225, 200, 38, 38, x * this->_bw, y * this->_bh, this->_bw, this->_bh, 0);break;
			    case 'b': al_draw_filled_rectangle(x*this->_bw, y*this->_bh, (x*this->_bw)+this->_bw, (y*this->_bh)+this->_bh, al_map_rgb(255,255,255)); break;	
			}
		}
	}

	al_draw_filled_rectangle(0, 630, 900, 700, al_map_rgb(255,255,255));	
	al_draw_text(this->_font40, al_map_rgb(0,0,0), 450, 640, 0, "VS");	
	al_draw_scaled_bitmap(p.getAvatar(0), 102, 200, 25, 25, 400, 630, 50, 50, 0);
	al_draw_scaled_bitmap(p.getAvatar(1), 102, 200, 25, 25, 490, 630, 50, 50, 0);
}