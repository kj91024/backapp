template <class al_f, class f>
class Save
{
	private:
	al_f *_font30;
	al_f *_font20;
	f *fp;
	int _file;
	vector<char *> name_files; 
	public:
	Save(void);
	~Save(void);
	f *File(char *t);
	void showSave(Maps<ALLEGRO_BITMAP> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,bool st);
};