using namespace std;
using namespace NTL;

class files{
private:	
	FILE *fp;
	string s;
public:
	bool isFile(const char *fp);
	ZZ readZZ(const char *fp);
	string readString(const char *fp);
	void writeString(const char *fp, string text);
	void writeZZ(const char *fp, ZZ text);
	void close(void);
};