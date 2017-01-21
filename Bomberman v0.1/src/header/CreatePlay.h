template <class al_b,class al_f>
class CreatePlay{
	private:
		al_b *_block;
		al_f *_font40;
		int _bw, _bh, _x[2], _y[2];
		char temp_map[15][20];
		bool _loadMapPlayer,_noAnimate;
	public:
		CreatePlay(void);
		~CreatePlay(void);
		void setNoAnimatePlay(bool c);
		bool getNoAnimatePlay(void);

		char getMap(int x, int y);
		void setMap(int x, int y,char p);
		
		char getUpdateX(int p);
		char getUpdateY(int p);
		
		void setLoadMapPlayer(bool p);
		bool getLoadMapPlayer(void);

		void downloadMapPlayer(Maps<al_b> &m,Player<al_b> &p);
		void showPlay(Maps<al_b> &m,Player<al_b> &p,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
		void showCreatePlay(Maps<al_b> &m,Player<al_b> &p,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
};