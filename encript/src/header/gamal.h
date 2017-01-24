using namespace std;
using namespace NTL;
using namespace cv;

class gamal{
	private:
		ZZ p, e1, e2, c1, c2, d, r, seed;
		string alf;
	public:
		gamal(int , ZZ );
		gamal(int , ZZ , ZZ ,ZZ ,ZZ );
		vector<ZZ> getPublic(void);
		
		string _c(string);
		string _d(string);

		bool Miller(ZZ);
		ZZ randomPrime(int);
		ZZ findGen(ZZ);
		string giro(string);

		string ZZtoStringBits(ZZ);
		ZZ StringtoZZBits(string);
		string ZZtoString(const ZZ);
		ZZ StringtoZZ(string);
		string AddRightZero(string, int);
		string AddLeftZero(string, int);
};