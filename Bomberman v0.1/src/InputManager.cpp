template <class al_e,class al_k>
InputManager<al_e,al_k>::InputManager(void){
	this->_x[0] = 0; this->_x[1] = 0;
	this->_y[0] = 0; this->_y[1] = 0;
	this->usePlayer[0] = true;
	this->usePlayer[1] = true;
	this->_step = 1;
}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::setStep(int step){ this->_step = step;	}

template <class al_e,class al_k>
int InputManager<al_e,al_k>::getStep(void){ return this->_step; }

template <class al_e,class al_k>
int InputManager<al_e,al_k>::getX(int p){ return this->_x[p]; }

template <class al_e,class al_k>
int InputManager<al_e,al_k>::getY(int p){ return this->_y[p]; }

template <class al_e,class al_k>
bool InputManager<al_e,al_k>::getUserPlayer(int p){ return this->usePlayer[p];}

template <class al_e,class al_k>
int InputManager<al_e,al_k>::setX(int p, int x){ 
	if(this->usePlayer[p])
		this->_x[p] = x; 
}

template <class al_e,class al_k>
int InputManager<al_e,al_k>::setY(int p, int y){ 
	if(this->usePlayer[p])
		this->_y[p] = y; 
}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::setUserKeyboard(int p, bool a){ this->usePlayer[p] = a;}

template <class al_e,class al_k>
bool InputManager<al_e,al_k>::getUserKeyboard(int p){return this->usePlayer[p];}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::decY(int p){
	if(this->usePlayer[p]){
		if(this->_y[p] > 0)
			this->_y[p] -= this->_step; 
	}
}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::incY(int p){
	if(this->usePlayer[p]){
		this->_y[p] += this->_step; 
	}
}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::decX(int p){
	if(this->usePlayer[p]){
		if(this->_x[p] > 0)
			this->_x[p] -= this->_step;
	}
}

template <class al_e,class al_k>
void InputManager<al_e,al_k>::incX(int p){
	if(this->usePlayer[p]){
		this->_x[p] += this->_step;
	}
}

template <class al_e,class al_k>
bool InputManager<al_e,al_k>::IsKeyPressed(al_e events,int key){
	if(events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if(events.keyboard.keycode == key)
			return true;
	}
	return false;
}

template <class al_e,class al_k>
bool InputManager<al_e,al_k>::IsKeyReleased(al_e events,int key){
	if(events.type == ALLEGRO_EVENT_KEY_UP)
	{
		if(events.keyboard.keycode == key)
			return true;
	}
	return false;
}

template <class al_e,class al_k>
bool InputManager<al_e,al_k>::keyDown(al_k key_state, int key){
	return al_key_down(&key_state, key);
}