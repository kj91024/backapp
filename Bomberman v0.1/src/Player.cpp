template <class al_b>
Player<al_b>::Player( void ){
	this->_source[0][0] = 0;
	this->_source[1][0] = 2;
	this->_lastX[0] = 1; this->_lastX[1] = 1;
	this->_lastY[0] = 1; this->_lastY[1] = 1;
	this->_dir[0] = -1;
	this->_dir[1] = -1;
	this->player1 = al_load_bitmap("img/player/1.png");
	this->player2 = al_load_bitmap("img/player/1.png");
	this->_pwinner = -1;
	this->_ploser = -1;
}

template <class al_b>
Player<al_b>::~Player(void)
{
	al_destroy_bitmap(this->player1);
	al_destroy_bitmap(this->player2);
}

template <class al_b>
void Player<al_b>::pushAvatar(int p1,int p2){
	switch(p1){
		case 0: this->player1 = al_load_bitmap("img/player/1.png"); break;
		case 1: this->player1 = al_load_bitmap("img/player/2.png"); break;
		case 2: this->player1 = al_load_bitmap("img/player/3.png"); break;
		case 3: this->player1 = al_load_bitmap("img/player/4.png");break;
		case 4: this->player1 = al_load_bitmap("img/player/5.png");break;
		case 5: this->player1 = al_load_bitmap("img/player/6.png");break;
	}
	switch(p2){
		case 0: this->player2 = al_load_bitmap("img/player/1.png"); break;
		case 1: this->player2 = al_load_bitmap("img/player/2.png"); break;
		case 2: this->player2 = al_load_bitmap("img/player/3.png"); break;
		case 3: this->player2 = al_load_bitmap("img/player/4.png");break;
		case 4: this->player2 = al_load_bitmap("img/player/5.png");break;
		case 5: this->player2 = al_load_bitmap("img/player/6.png");break;
	}
}

template <class al_b>
al_b * Player<al_b>::getAvatar(int p){
	switch(p){
		case 0: return this->player1;
		case 1: return this->player2;
	}
}

template <class al_b>
int Player<al_b>::getSource(int p){return this->_source[p][0];}

template <class al_b>
void Player<al_b>::setSource(int p, int d){this->_source[p][0] = d;}

template <class al_b>
void Player<al_b>::incSource(int p){this->_source[p][0] += 32; }

template <class al_b>
int Player<al_b>::getDir(int p){return this->_dir[p];}

template <class al_b>
void Player<al_b>::setDir(int p, int d){ this->_dir[p] = d; }

template <class al_b>
int Player<al_b>::getLastX(int p){ return this->_lastX[p]; }

template <class al_b>
int Player<al_b>::getLastY(int p){ return this->_lastY[p]; }

template <class al_b>
void Player<al_b>::setLastX(int p,int x){ this->_lastX[p] = x; }

template <class al_b>
void Player<al_b>::setLastY(int p,int y){ this->_lastY[p] = y; }

template <class al_b>
void Player<al_b>::loserPlayer(int p){ this->_ploser = p;}

template <class al_b>
void Player<al_b>::winnerPlayer(int p){ this->_pwinner = p;}

template <class al_b>
int Player<al_b>::loserPlayer(void){return this->_ploser;}

template <class al_b>
int Player<al_b>::winnerPlayer(void){return this->_pwinner;}

template <class al_b>
void Player<al_b>::operator>>(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	input.setX(0,this->getX(0));
	input.setY(0,this->getY(0));

    input.setX(1,this->getX(1));
    input.setY(1,this->getY(1));
}

template <class al_b>
void Player<al_b>::operator<<(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	this->setX(0,input.getX(0));
	this->setY(0,input.getY(0));

	this->setX(1,input.getX(1));
	this->setY(1,input.getY(1));
}