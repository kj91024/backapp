using namespace std;
using namespace NTL;
using namespace cv;

vector<ZZ> getCamera(){
    vector<ZZ> lseedcamera;
    ZZ sum = (ZZ)1, nm = (ZZ)0;
    VideoCapture cap;
    cap.open(0);
    if( !cap.isOpened() ){
        cout << "Could not initialize capturing...\n";
        sum = (ZZ)0; 
    }else{  
        namedWindow( "Generate Seed", 1 );
        Mat frame;
        for(int i=0;i<1;i++){
            cap >> frame;
            if( frame.empty() ) break;
            imshow("Generate Seed", frame);
        }
        Vec2b numeric;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 1; j++,nm=nm+2){
                numeric = frame.at<Vec2b>(i, j);
                if(numeric[0] != 0 and numeric[1] != 0){
                    sum *= numeric[0];
                    sum *= numeric[1];
                }
                if((i == (ZZ)0 and j == (ZZ)0 ) or (i == (ZZ)1 and j == (ZZ)0) or (i == (ZZ)2 and j == (ZZ)0) ){
                    lseedcamera.push_back(sum);
                    sum = (ZZ)1;
                }
            }
        }
    }
    return lseedcamera;
}

/*Funciones Basicas*/
ZZ mod(ZZ a, ZZ b){
	ZZ mod =  a / b;
	mod = a - (mod * b);
	return (mod < 0)? a + mod : mod;
}
int mod(int a, int b){
	int mod =  a / b;
	mod = a - (mod * b);
	return (mod < 0)? a + mod : mod;
}
ZZ min(ZZ a, ZZ b){ return (a > b) ? b : a; }
ZZ exp(ZZ a,ZZ exp){
	ZZ i = (ZZ)0,r = (ZZ)1;
	while(i < exp){
		r = r * a;
		i++;
	}
	return r;
}
ZZ exp_mod(ZZ a,ZZ b,ZZ m){
	ZZ res = (ZZ)1;
	while(b > 0){
		if((b & 1) == 1) res = mod(res*a, m);
		a = mod(mod(a,m)*mod(a,m),m);
		b = b>>1;
		//cout <<res<<endl; 
	}
	return res;
}
int exp_mod(int a,int b,int m){
	int res = 1;
	while(b > 0){
		if((b & 1) == 1) res = mod(res*a, m);
		a = mod(mod(a,m)*mod(a,m),m);
		b = b>>1;
		//cout <<res<<endl; 
	}
	return res;
}
/*Funciones Euclidianas*/
ZZ euclides(ZZ a, ZZ b){
	ZZ r, d;
	int i = 1;
	r = d = (ZZ)1;
	while(r > 0){
		d =	 r;
		r = mod(a,b);
		a = b;
		b = r;
		//cout <<endl<< i++ << endl;
	}
	return d;
}
vector<ZZ> euclides_extended(ZZ a, ZZ b){
	ZZ r, d, q, x, y;
	ZZ x1 = (ZZ)0, x2 = (ZZ)1, y1 = (ZZ)1, y2 = (ZZ)0;
	int i = 0;
	x = y = r = d = 0;
	if(a != 0 & b == 0){
		x = 1;y = 0;d = a;
	}else if (a == 0 & b != 0){
		x = 0;y = 1;d = b;
	}else{
		while(b > 0){
			q = a/b;
			r = a - q*b;
			x = x2 - q*x1;
			y = y2 - q*y1;
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
			y2 = y1;
			y1 = y;
			//cout << endl<< ++i << endl;
		}
		d = a;
		x = x2;
		y = y2;
	}
	vector<ZZ> n;
	//y = y2 - q*y1;
	n.push_back(d);	n.push_back(x);	n.push_back(y);
	return n;
}
ZZ euclides_binary(ZZ a, ZZ b){
	int i,o = 0;
	ZZ t = (ZZ)0;
	if(a == 0) return b;
	else if(b == 0) return a;
	else if(b == a) return a;
	else{
		for(i = 0; (a & 1) == 0 && (b & 1) == 0;i++){
		 	cout << a << " "<<b<<" "<<t<<endl;
		 	a = a>>1;
			b = b>>1;
			o++;
		}

		while((a & 1) == 0 and o++) {a = a>>1;cout << a << " "<<b<<" "<<t<<endl;}
		while(b != 0){
			while((b & 1) == 0 and o++) {b = b>>1;cout << a << " "<<b<<"  "<<t<<endl;}
			if(a > b){
				t = b;
				b = a;
				a = t;
			}
			b = b - a;
			o++;
			cout << a << " "<<b<<" "<<t<<endl;
		}
		cout <<o<<endl;
		return a << i;
	}
}
vector<ZZ> euclides_binary_extended(ZZ x, ZZ y){
	ZZ res;
	int g = 0;
	int o = 0;
	if(x == 0) res = y;
	else if(y == 0) res = x;
	else if(y == x) res = x;
	else{
		for(int i = 0; (x & 1) == 0 && (y & 1) == 0;i++){
		 	x = x>>1;
			y = y>>1;
			g++;
		}

		ZZ u = x, v = y, A = (ZZ)1, B = (ZZ)0, C = (ZZ)0, D = (ZZ)1;
		while(u != 0){
			//cout << x << " "<< y << " "<< u <<" "<< v <<" "<< A <<" "<< B <<" "<< C <<" "<< D << endl;
			o++;
			while((u & 1) == 0){
				u = u >> 1;
				if(mod(A,(ZZ)2) == 0 and mod(B,(ZZ)2) == 0){
					A = A>>1;
					B = B>>1;
				}else{
					A = (A+y) >> 1;
					B = (B-x) >> 1;
				}
			}
			while((v & 1) == 0){
				v = v >> 1;
				if(mod(C,(ZZ)2) == 0 and mod(D,(ZZ)2) == 0){
					C = C>>1;
					D = D>>1;
				}else{
					C = (C+y) >> 1;
					D = (D-x) >> 1;
				}	
			}

			if(u >= v){
				u = u - v;
				A = A - C;
				B = B - D;
			}else{
				v = v - u;
				C = C - A;
				D = D - B;
			}
		}

		//cout << o << endl;
		if(u == 0){
			x = C;
			y = D;
		}

		//cout << x << " "<< y << " "<< u <<" "<< v <<" "<< A <<" "<< B <<" "<< C <<" "<< D << endl;
		res = v<<g;
	}
	vector<ZZ> n;
	n.push_back(res); n.push_back(x); n.push_back(y);
	return n;
}
ZZ r_euclides_binary(ZZ a, ZZ b){
	ZZ d;
	if(a == b)
		return a;
	else if( (a & 1) == 0 && (b & 1) == 0 ){//Primera Propiedad
		a = a >> 1;
		b = b >> 1;
		d = r_euclides_binary(a, b) << 1;
	}else if( (a & 1) == 0 && (b & 1) == 1 ){//Segunda Propiedad
		a = a >> 1;
		d = r_euclides_binary(a, b);
	}else if( (a & 1) == 1 && (b & 1) == 0 ){//Segunda Propiedad
		b = b >> 1;
		d = r_euclides_binary(a, b);
	}else{									 //Tercera propiedad
		if(a > b)
			a = a-b;
		else
			b = b-a;
		d = r_euclides_binary(a, b);
	}
	return d;
}
ZZ resto_minimo(ZZ a, ZZ b){
	ZZ c,d,r;
	if(a == 0){
		return b;
	}else{
		while(b != 0){
			r = mod(a,b);
			a = b;
			b = r;
		}
	}
	return a;

	/*while(true){
		int r = a / b;
		if(r == 0) return b;
		else if(r > b/2) a = b; b = b-r;
		else a = b; b = r;
	}*/
}
ZZ lehmer_mcd(ZZ A, ZZ B, ZZ p, ZZ system){ 
	ZZ a0, a1, b,W,q0,q1,r,u0,u1,v0,v1,R,T;
	W = exp(system,p);
	int h,o=0;
	while(B >= W){
			cout << o<< " "<< A<<" " <<B << " "<<a0<< " " << a1<< " " <<W<< " " <<q0<< " " <<q1<< " " <<r<< " " <<u0<< " " <<u1<< " " <<v0<< " " <<v1<< " " <<R<< " " <<T<<endl;
		conv(h,NumBits(B)-p +1);
		a0 = A >> h;
		a1 = B >> h;
		u0 = (ZZ)1;u1 = (ZZ)0;v0 = (ZZ)0; v1 = (ZZ)1;
		while(( a1+u1 != (ZZ)0 ) and ( a1+v1 != (ZZ)0 )){
			//cout << A<<" " <<B << " "<<a0<< " " << a1<< " " <<W<< " " <<q0<< " " <<q1<< " " <<r<< " " <<u0<< " " <<u1<< " " <<v0<< " " <<v1<< " " <<R<< " " <<T<<endl;
			q0 = (a0+u0)/(a1+u1);
			q1 = (a0+v0)/(a1+v1);

			if(q0 != q1)
				break;

			r = a0 - q0*a1;	a0 = a1;	a1 = r;
			r = u0 - q0*u1;	u0 = u1;	u1 = r;
			r = v0 - q0*v1;	v0 = v1;	v1 = r;
		}

		if (v0 == (ZZ)0){
			R = mod(A,B);
			A = B;
			B = R;
		}else{
			R = u0*A+v0*B;
			T = u1*A+v1*B;
			A = R;
			B = T;
		}
		if(B == 0) return A;
		o++;
	} 
	A = euclides(A,B);
	return A;
}
ZZ LSBGCD(ZZ a, ZZ b){
	ZZ t = (ZZ)0;
	int s = 0;
	int i = 0;
	while(b != (ZZ)0){
		cout << i<<" "<<a << " "<< b << " "<<s << " "<<t << endl;
		s = 0;
		while( (b<<s) <= a) s++;
		--s;

		t = min(a-(b<<s),(b<<(s+1))-a);
		a = b; b = t;
		if(b > a){
			 ZZ temp = a;
			 a = b;
			 b = temp;
		}
		i++;
	}
	cout << i<< endl;
	return a;
}
ZZ inverse(ZZ a, ZZ n){
	vector<ZZ> temp = euclides_extended(a,n);
	if(temp[0] == 1){	// el MCD es 1
		return mod(temp[1], n);
	}else
		return ZZ(-1);
}
ZZ resto_chino_for_RSA(vector<ZZ> a,vector<ZZ> p){
	bool st = true;
	ZZ P = (ZZ)1, x = (ZZ)0;
	vector<ZZ> Pi, qi, r;
	for(int i = 0; i < p.size(); i++){
		/*for(int j = i + 1; j < p.size(); j++){
			if(resto_minimo(p[i], p[j]) != 1){
				st = false;
				break;
			}
		}*/
		P *= p[i];
	}
	/*if(st == false){
		cout << "No tiene solución"<< endl;
		return (ZZ)0;
	}*/

	for(int i = 0; i < p.size(); i++){
		Pi.push_back(P/p[i]);
		qi.push_back(inverse(mod(Pi[i],p[i]),p[i]));
		x += mod(a[i], P) * mod(Pi[i], P)  * mod(qi[i], P);
		x = mod(x, P);
	}
	return x;
}
vector<ZZ> erase(vector<ZZ> vec, int a){
	for (int i = a; i < vec.size()-1; ++i){
		vec[i] = vec[i+1];
	}
	vec.resize(vec.size()-1);
	return vec;
}
ZZ eratostenes(int bits){
	int u = 0;
	ZZ num, onum, oc, ic, a = (ZZ)1;
	int n;
	
	/*Generamos los bits con puros unos*/
	//for(int i = bits-1; i>=0; i--)
	//	num = num | a<<i;
	//cout << num << endl;
	num = (1<<bits)-1;
	conv(n,num);
	num = 1<<n;

	for(int i = 2; i < n and i*i < n; i++){
		onum = (num & (1 << (i-1))) >> i-1;
		if(onum == 0){
			for (int o = i+1; o < n; ++o){
				onum = (num & ((ZZ)1 << (o-1))) >> o-1;
				if(onum == 0){
					if(mod( (ZZ)o, (ZZ)i) == 0){
						num = num | ((ZZ)1 << (o-1));
					}
				}
			}
		}
	}
	
	cout << num<<endl;
	for (int i = 2; i < n; ++i){
		onum = (num & ((ZZ)1 << (i-1))) >> i-1;
		if(onum == 0) cout << i << endl;
	}
	//01011110001101010101000111010000   -   32
	

	/*conv(num, 2147483656);
	for (; num>=0;){
		num = num/2;
		cout << mod(num,(ZZ)2) <<endl;
	}*/
	return num;
}
string ZZtoString(const ZZ num){
	stringstream buffer;
	buffer << num;
	return buffer.str();
}
ZZ StringtoZZ(string num){
	ZZ b(INIT_VAL, num.c_str());
	return b;
}
string AddRightZero(string num, int n){
	for (int i = 0; i < n-num.size(); ++i)
		num.insert(0,"0");
	return num;
}
bool Miller(ZZ p){
    int z;

    /*if (p < 2)   			return false;*/
    if (p != 2 && mod(p, (ZZ)2)==0)	return false;
    
	int iteration = 1000;
    ZZ s = p - 1;
    while (mod(s, (ZZ)2) == 0)      s = s >> 1;
    for (int i = 0; i < iteration; i++){
        conv(z, (p - 1) + 1);
        ZZ a = ZZ( mod(ZZ(rand()), ZZ(z))), temp = s;
        ZZ mod = exp_mod(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1){
            mod = exp_mod(mod, (ZZ)2, p);
            temp = temp << 1;
        }
        if (mod != p - 1 && temp % 2 == 0) return false;
    }
    return true;
}
unsigned criba_(int bt){
	int64_t t = 1;
	t = (t<<bt)-1;
	int64_t sqr = sqrt(t);
	int64_t cache = 32768;
	unsigned segment = max(sqr, cache);
	int64_t s = 3, n = 3, tem = 0;
	int sqr_ = sqrt(sqr);
	vector<bool> b (sqr+1, 1);
	vector<unsigned int> v;
	vector<bool> criba(segment);
	vector<unsigned int> primo;
	vector<unsigned int> next;
	for(int i=2; i<sqr_; i++)
		if(b[i])
			for(int j=i*i; j<=sqr; j+=i)
				b[j] = false;
	for(int64_t bg=0; bg<=t; bg+=segment){
		fill(criba.begin(), criba.end(), true);
		int64_t en = min(bg+segment-1, t);
		for(;s*s<=en; s+=2){
			if(b[s]){
				primo.push_back(s);
				next.push_back(s*s-bg);
			}
		}
		for(int i=0; i<primo.size(); i++){
			int j = next[i];
			for(int k=primo[i]*2; j<segment; j+=k)	criba[j] = false;
			next[i] = j-segment;
		}
		for(; n<=en; n+=2)
			if(criba[n-bg]) v.push_back(n);
	}
	for (int i = v.size()-1; i > 0; --i)
		if(Miller( ZZ((v[i]-1)/2) )) return v[i];
	return 0;
}
unsigned findGen(unsigned p){
	unsigned g = p/2;
	unsigned q = (p-1)/2;
	unsigned found = 0;
	for (; g < (p-2) and found != 1; ++g)
		if(exp_mod((ZZ)g,(ZZ)2,(ZZ)p) != 1 and exp_mod((ZZ)g,(ZZ)q,(ZZ)p) != 1)	found = 1;
	return g;
}
/*ZZ StringtoZZ(string num){
	ZZ number = (ZZ)0;
	for (int i = 0; i < num.size(); ++i)
		number = (number * 10) + (num[i] - '0');
	return number;
}
string AddZeroString(string num, ZZ n){
	string cero = "";
	if(n > num.size()){
		for (int i = 0; i < n-num.size(); ++i)
			cero += '0';

		for (int i = 0; i < num.size(); ++i)
			cero += num[i];
	}else
		cero = num;
	return cero;
}
string reverseString(string msn){
	char temp;
	for(int i = 0, j = msn.size()-1; i < j; i++, j--){
		temp = msn[i];
		msn[i] = msn[j];
		msn[j] = temp; 
	}
	return msn;
}*/

string NumberToString(int pNumber){
	ostringstream oOStrStream;
 	oOStrStream << pNumber;
 	return oOStrStream.str();
}
string CharToString(char pNumber){
	ostringstream oOStrStream;
 	oOStrStream << pNumber;
 	return oOStrStream.str();
}
//PAARA CALCULAR EL ULTMO BIT DE UN NUMERO: NUMERO & 1 DONDE 0 ES ES PAR Y 1 ES IMPAR
