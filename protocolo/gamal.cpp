#include "src/lib.cpp"
using namespace std;
using namespace NTL;
using namespace cv;

int main(int argc, char const *argv[]){
	vector<ZZ> data, u;
	ZZ p, e1, e2;
	protocolo me, other;

	me.g = NULL;
    other.g = NULL;

	me.takePhoto();
	data = me.getSeed();
	
	other.g = new gamal(20, data[1]);
	u = other.g->getPublic();
	e1 = u[0];
	e2 = u[1];
	p = u[2];
	
	me.g = new gamal(20, data[0], e1, e2, p);

	string msn = "Hola como estas";
	string _c = me.g->_c(msn);
	cout << _c << endl;
	string _d = other.g->_d(_c);
	cout << _d << endl;
	return 0;
}