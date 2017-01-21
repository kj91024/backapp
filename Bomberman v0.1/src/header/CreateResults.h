template <class al_f>
class CreateResults{
	private:
		al_f *_font50;

	public:
		CreateResults(void);
		~CreateResults(void);

		void showResults(Player<ALLEGRO_BITMAP> &p);

};