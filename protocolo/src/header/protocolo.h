using namespace std;
using namespace NTL;
using namespace cv;

class protocolo{
	private:
		vector<string> alf;
        Mat frame;
        vector<ZZ> seedCamera;
		string ec;
		
	public:
		int alto, ancho;
		hellman *h;
		cesar *c;
		RSA *rsa;
		gamal *g;
		ZZ K;

		protocolo(void);

		Mat getFrame(void);
		void takePhoto(void);
		vector<string> proc(string);
		string _ccesar(void);
		string _dcesar(string);
		void showPhoto(void);
		
		int getAlfSize(void);
		string ZZtoString(const ZZ);
		ZZ StringtoZZ(string);
		string AddRightZero(string, int);
		string AddLeftZero(string, int);

		string getEC(void);
		vector<ZZ> getSeed(void);

		void setK(ZZ);
		void setEC(string);
};