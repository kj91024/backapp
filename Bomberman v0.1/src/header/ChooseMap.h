template <class al_b,class al_f>
class ChooseMap{
	private:
		int _readyPlayer[2];
		int _avatar[2];
		al_f *_font30;
		al_f *_font20;

		al_b *_block;
		char temp_map[1][3];
		int _height, _width;
		bool _load;

	public:
		ChooseMap(void);
		void showChooseMap(Maps<al_b> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);
		~ChooseMap(void);
};