using namespace std;
using namespace NTL;
using namespace cv;


class hellman{
	private:
		unsigned p, g;
		ZZ a, b;
		ZZ A, B, K;
		ZZ seed;
		string alf;
	public:
		/*Primero que crea los valores g, p, A y los envia*/
		hellman(int, ZZ);
		vector<ZZ> getPublic(void);
		void setB(ZZ);

		/*Recibe los valores y devuelve B*/
		hellman(int, ZZ, ZZ, ZZ, ZZ);
		ZZ getB(void);

		/*Solo para mi curiosidad*/
		ZZ getK(void);

		bool Miller(ZZ);
		unsigned criba_(int);	
		unsigned findGen(unsigned);
		unsigned Miller_(int);	

		string _c(string msn);
		string _d(string msn);	
		
		/*Crea numeros primos con un rango a N o a 3/4 de N*/
		ZZ randomPrime(int, bool);
		string ZZtoStringBits(ZZ);
		ZZ StringtoZZBits(string);
};