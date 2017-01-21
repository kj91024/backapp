using namespace std;
using namespace NTL;

class afin{
	private:
		int clave;
		ZZ kpublic;
		ZZ kprivate;
		string alf;
	
	public:
		afin(int clave);
		ZZ getKeyPublic(void);
		ZZ getKeyPrivate(void);
		string _c(ZZ a, string msn);
		string _d(ZZ a, string msn);
};