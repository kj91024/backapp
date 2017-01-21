template <class al_b>
class Maps{
	private:
	bool _init;
	int _level, _bw, _bh,_w,_h;
	char map[15][20];
	al_b *_background;

	public:
	Maps(void);
	~Maps(void);
	int getWidth(void);
	void setWidth(int c);
	int getHeight(void);
	void setHeight(int c);
	int getLevel(void);
	int setLevel(const int new_level);
	bool getInit(void);
	bool changeInit(bool h);
	char getPositionMap(int x, int y);
	char loadMap(int type, int level, bool b);
	char showBackground(void);
	char getMap(int x, int y){return this->map[y][x];}
};