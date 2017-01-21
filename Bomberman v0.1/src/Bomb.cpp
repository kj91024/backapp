template <class al_b>
Bomb<al_b>::Bomb(void){
	this->timeBomb = 12;
	this->max_bomb = 10;
	this->_bomb = al_load_bitmap("img/skills.png");
	this->_bomb0 = al_load_bitmap("img/le0.tga");
	this->_bomb1 = al_load_bitmap("img/le1.tga");
	this->_bomb2 = al_load_bitmap("img/le2.tga");
	this->_bomb3 = al_load_bitmap("img/le3.tga");
	this->_bomb4 = al_load_bitmap("img/le4.tga");
	this->_n[0] = 1;	this->_n[1] = 1;
	for(int y = 0;y<10;y++){
		for(int x =0;x<5;x++){
			this->_bombs[y][x] = -1;		
		}
	}
}

template <class al_b>
Bomb<al_b>::~Bomb(void){
	al_destroy_bitmap(this->_bomb);
	al_destroy_bitmap(this->_bomb0);
	al_destroy_bitmap(this->_bomb1);
	al_destroy_bitmap(this->_bomb2);
	al_destroy_bitmap(this->_bomb3);
	al_destroy_bitmap(this->_bomb4);
}

template <class al_b>
int Bomb<al_b>::getMaxBomb(void){ return this->max_bomb; }

template <class al_b>
int Bomb<al_b>::getBombPrint(int i){ return this->_bombs[i][4]; }

template <class al_b>
int Bomb<al_b>::getBombX(int i){ return this->_bombs[i][0]; }

template <class al_b>
int Bomb<al_b>::getBombY(int i){ return this->_bombs[i][1]; }

template <class al_b>
int Bomb<al_b>::getBombTimer(int i){ return this->_bombs[i][3]; }

template <class al_b>
int Bomb<al_b>::getBombPlayer(int i){ return this->_bombs[i][2]; }

template <class al_b>
void Bomb<al_b>::setBombPrint(int i,bool s){ this->_bombs[i][4] = s; }

template <class al_b>
void Bomb<al_b>::deleteBomb(int i){
	for(int j = 0;j<5;j++)
		this->_bombs[i][j] = -1; 
}

template <class al_b>
bool Bomb<al_b>::existBombPrint(void){
	for(int i = 0;i<10;i++){
		if(this->_bombs[i][4] == 1)
			return true;
	}
	return false;
}

template <class al_b>
bool Bomb<al_b>::existBombNoPrint(void){
	for(int i = 0;i<10;i++){
		if(this->_bombs[i][4] == 0)
			return true;
	}
	return false;
}

template <class al_b>
void Bomb<al_b>::decBombTimer(int i){ this->_bombs[i][3]--; }

template <class al_b>
void Bomb<al_b>::putBomb(int x,int y,int player){
	int i, count = 0;
	bool put = false;
	for(i=0;i<10;i++){
		if(this->_bombs[i][2] == player)
			count++;
	}
	if(count <= this->_n[player])
		put = true;
		if(put){
		//Recorremos hasta encontrar el un espacio basio
		for(i=0;i<10;i++){
			if(this->_bombs[i][2] == -1)
				break;
		}
		//Colocar una bomba				
		this->_bombs[i][0] = x;
		this->_bombs[i][1] = y;
		this->_bombs[i][2] = player;
		this->_bombs[i][3] = this->timeBomb;
		this->_bombs[i][4] = 1;
	}
}

template <class al_b>
void Bomb<al_b>::drawBomb(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb, 288, 80, 50, 50, (x * width)+7,(y * height)+7, 31, 31, 0);
}

template <class al_b>
void Bomb<al_b>::drawBomb0(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb0, 0, 0, 62, 62, x * width,y * height, width, height, 0);
}

template <class al_b>
void Bomb<al_b>::drawBomb1(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb1, 0, 0, 62, 62, x * width,y * height, width, height, 0);
}

template <class al_b>
void Bomb<al_b>::drawBomb2(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb2, 0, 0, 62, 62, x * width,y * height, width, height, 0);
}

template <class al_b>
void Bomb<al_b>::drawBomb3(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb3, 0, 0, 62, 62, x * width,y * height, width, height, 0);
}

template <class al_b>
void Bomb<al_b>::drawBomb4(int x,int y,int width,int height){ 
	al_draw_filled_rectangle(x*width, y*height, (x*width)+width, (y*height)+height, al_map_rgb(255,255,255));
	al_draw_scaled_bitmap(this->_bomb4, 0, 0, 62, 62, x * width,y * height, width, height, 0);
}