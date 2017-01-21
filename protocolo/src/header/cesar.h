using namespace std;
using namespace NTL;

class cesar{
	private:
		ZZ clave;
		vector<string> alf;
	public:
		cesar(ZZ clave);
		string _c(int msn);
		string _d(ZZ msn);
		string ZZtoString(const ZZ num);
};