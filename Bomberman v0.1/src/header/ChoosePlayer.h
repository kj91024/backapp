template <class al_b,class al_f>
class ChoosePlayer{
	private:
	int _readyPlayer[2];
	int _avatar[2];
	al_f *_font30;
	al_f *_font20;

	al_b *_background;
	
	al_b *_player1;
	al_b *_player2;
	
	al_b *_1;
	al_b *_2;
	al_b *_3;
	al_b *_4;
	al_b *_5;
	al_b *_6;
	
	public:
	ChoosePlayer(void);
	int getAvatarCodePlayer1(void);
	int getAvatarCodePlayer2(void);

	bool getReadyPlayer(int p);
	void setReadyPlayer(int p,bool c);
	bool readyPlayer(int p, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);

	void showChoosePlayer(Maps<al_b> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
	~ChoosePlayer(void);
};