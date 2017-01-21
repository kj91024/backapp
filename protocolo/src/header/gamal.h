using namespace std;
using namespace NTL;
using namespace cv;

class gamal{
	private:
		vector<string> alf;
	public:
		/*meter en el privado*/
		ZZ p, e1, e2, c1, c2, d, r, seed;
		/*meter en el privado*/

		gamal(int , ZZ );
		gamal(int , ZZ , ZZ ,ZZ ,ZZ );
		vector<ZZ> getPublic(void);

		void setP(ZZ);
		void setE1(ZZ);
		void setE2(ZZ);
		void setC1(ZZ);
		void setC2(ZZ);
		void setD(ZZ);
		void setR(ZZ);
		
		string _c(string);
		string _d(string);
		string _ci(string);
		string _di(string);

		bool Miller(ZZ);
		ZZ randomPrime(int);
		ZZ findGen(ZZ);
		string giro(string);
		int find(char a);

		string ZZtoStringBits(ZZ);
		ZZ StringtoZZBits(string);
		string ZZtoString(const ZZ);
		ZZ StringtoZZ(string);
		string AddRightZero(string, int);
		string AddLeftZero(string, int);
};