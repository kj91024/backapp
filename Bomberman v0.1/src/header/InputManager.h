template <class al_e,class al_k>
class InputManager{
	private:
		int _x[2], _y[2], _step;
		bool usePlayer[2];
	public:
		InputManager(void);
		void setStep(int step);
		int getStep(void);
		int getX(int p);
		int getY(int p);
		
		bool getUserPlayer(int p);

		int setX(int p, int x);
		int setY(int p, int y);

		void setUserKeyboard(int p, bool a);
		bool getUserKeyboard(int p);

		void decY(int p);
		void incY(int p);
		void decX(int p);
		void incX(int p);

		bool IsKeyPressed(al_e events,int key);
		bool IsKeyReleased(al_e events,int key);
		bool keyDown(al_k key_state, int key);
};