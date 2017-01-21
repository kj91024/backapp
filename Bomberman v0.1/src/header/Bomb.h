template <class al_b>
class Bomb{
	private:
	int _n[2], _bombs[10][5], max_bomb,timeBomb;
	int _type;
	al_b *_bomb;
	al_b *_bomb0;
	al_b *_bomb1;
	al_b *_bomb2;
	al_b *_bomb3;
	al_b *_bomb4; 
	// posicion en X - posicion en Y - Jugador - timer - impreso

	public:
	Bomb(void);
	~Bomb(void);
	int getMaxBomb(void);
	int getBombPrint(int i);
	int getBombX(int i);
	int getBombY(int i);
	int getBombTimer(int i);
	int getBombPlayer(int i);
	void setBombPrint(int i,bool s);
	void deleteBomb(int i);
	bool existBombPrint(void);
	bool existBombNoPrint(void);
	void decBombTimer(int i);
	void putBomb(int x,int y,int player);
	void drawBomb(int x,int y,int width,int height);
	void drawBomb0(int x,int y,int width,int height);
	void drawBomb1(int x,int y,int width,int height);
	void drawBomb2(int x,int y,int width,int height);
	void drawBomb3(int x,int y,int width,int height);
	void drawBomb4(int x,int y,int width,int height);
};