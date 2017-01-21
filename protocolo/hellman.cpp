#include "src/lib.cpp"
using namespace std;
using namespace NTL;
using namespace cv;

int main(int argc, char const *argv[]){
	vector<ZZ> data, u;
	ZZ p, g, A;
	protocolo me, other;

	me.h = NULL;
    other.h = NULL;

	me.takePhoto();
	data = me.getSeed();
	
	other.h = new hellman(20, data[0]);
	u = other.h->getPublic();
	p = u[0];
	g = u[1];
	A = u[2];

	me.h = new hellman(20, data[1], p, g, A);
	other.h->setB( me.h->getB() );
	
	me.setK( me.h->getK() );
	other.setK( other.h->getK() );
	
	cout << me.K <<" " << other.K <<endl;

	return 0;
}