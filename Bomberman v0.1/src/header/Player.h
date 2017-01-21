template <class al_b>
class Player:public Bomb<al_b>,public InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE>{
	protected:
	int _dir[2], _lastX[2], _lastY[2], _source[2][1], _pwinner,_ploser;
	al_b *player1;
	al_b *player2;
	public:
	Player(void);
	~Player(void);
	void pushAvatar(int p1,int p2);
	al_b *getAvatar(int p);
	int getSource(int p);
	void setSource(int p, int d);
	void incSource(int p);

	int getDir(int p);
	void setDir(int p, int d);

	int getLastX(int p);
	int getLastY(int p);

	void setLastX(int p,int x);
	void setLastY(int p,int y);

	void loserPlayer(int p);
	void winnerPlayer(int p);

	int loserPlayer(void);
	int winnerPlayer(void);
	void operator>>(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
	void operator<<(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
};