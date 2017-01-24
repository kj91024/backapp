using namespace std;
using namespace NTL;
using namespace cv;

class RSA{
	private:
		ZZ e, d, N, ON;
		ZZ p, q;
		ZZ seed;
		bool gpass;
		int bits;
	public:
		string alf;

		RSA(ZZ seed);
		RSA(ZZ N, ZZ e);
		
		vector<ZZ> getPublic(void);
		//vector<ZZ> getPrivate(void);
		string _c(string msn);
		string _d(string msn);
		ZZ resto_chino(vector<ZZ> a,vector<ZZ> p);

		string ZZtoString(const ZZ num);
		ZZ StringtoZZ(string num);
		string AddRightZero(string num, int n);
		string AddLeftZero(string num, int n);


		string ZZtoStringBits(ZZ num);
		ZZ StringtoZZBits(string num);

		bool Miller(ZZ);
		ZZ mulmod(ZZ, ZZ, ZZ);
		ZZ inversaMulti(void);		//Inversa multiplicativa
		ZZ euler(void);			//Potenciacion modular
		ZZ randomPrime(int);
		//ZZ getNumCamera(void);
};