class ScreenManager: 
	public Menu<ALLEGRO_BITMAP,ALLEGRO_FONT>, 
	public Save<ALLEGRO_FONT,FILE>,
	public ChoosePlayer<ALLEGRO_BITMAP, ALLEGRO_FONT>,
	public ChooseMap<ALLEGRO_BITMAP, ALLEGRO_FONT>, 
	public CreatePlay<ALLEGRO_BITMAP, ALLEGRO_FONT>, 
	public CreateResults<ALLEGRO_FONT>,
	public CreatePause<ALLEGRO_FONT>{
	private:
		bool _Menu, _Save, _ChoosePlayer, _ChooseMap, _BeginPlay, _ShowPause, _ShowResults;
		ALLEGRO_FONT *_font20;
		ScreenManager *sm;
	public:
	ScreenManager(void);
	~ScreenManager(void);
	bool isCreateMenu(void);
	bool isCreateSave(void);
	bool isCreateChoosePlayer(void);
	bool isCreateChooseMap(void);
	bool isCreateBeginPlay(void);
	bool isCreateShowPause(void);
	bool isCreateShowResults(void);
	
	void setMenu(bool c);
	void setSave(bool c);
	void setChoosePlayer(bool c);
	void setChooseMap(bool c);
	void setBeginPlay(bool c);
	void setShowPause(bool c);
	void setShowResults(bool c);

	void drawButton(void);
	void restartInput(InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);

	//Virtual de Menu
	/*virtual int getButtonSelectMenu(void);
	virtual void setButtonSelectMenu(int c);
	virtual void showMenu(Maps<ALLEGRO_BITMAP> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input);*/
};
