RSA::RSA(ZZ N, ZZ e){
	for(int i=0; i<256; i++) alf.push_back(NumberToString(i));
	alf.push_back(",");
	for(char i='a'; i<='z'; i++) alf.push_back(CharToString(i));
	alf.push_back(" ");
	for(char i='A'; i<='Z'; i++) alf.push_back(CharToString(i));
	alf.push_back("-");
	alf.push_back(".");

	/*Setting Claves*/
	this->N = N;
	this->e = e;
}
RSA::RSA(ZZ seed){
	this->seed = seed;
	
	for(int i=0; i<256; i++) alf.push_back(NumberToString(i));
	alf.push_back(",");
	for(char i='a'; i<='z'; i++) alf.push_back(CharToString(i));
	alf.push_back(" ");
	for(char i='A'; i<='Z'; i++) alf.push_back(CharToString(i));
	alf.push_back("-");
	alf.push_back(".");

	/*Verificamos que se cree solo una sesion para 
	que no este cambiando a cada rato de session*/
		/*Generando claves*/
		p = RandomPrime_ZZ(1024);
		//p = randomPrime(50);
		q = RandomPrime_ZZ(1024);
		//q = randomPrime(50);
		N = p*q;
		//cout << "N: "<<N<<endl;
		ON = (p-1)*(q-1);
		while(true){
			//randomPrime(seed, 1024, 154);
			this->e = RandomPrime_ZZ(1024);
			//cout << "e: "<<e<<endl;
			//this->e = randomPrime(50);
			if(this->e > ON) continue;
			this->d = inverse(this->e,ON);
			//cout << "d: "<<d<<endl;
			if( this->d != -1) break;
		}

		/*Setting a gpass para que indique que ya 
		se a generado un session*/
}
vector<ZZ> RSA::getPublic(void){
	vector<ZZ> v;
	v.push_back(e);
	v.push_back(N);
	return v;
}
string RSA::_c(string msn){
	string new_msn, cipher, letter;
	int size1 = ZZtoString(N).size()-1;			//N-1
	while(msn.size() > 0){
		if(msn.size()-1 > size1){
			cipher = msn.substr(0, size1);
			msn = msn.substr(size1, msn.size()-1);
		}else{
			cipher = msn;
			msn.clear();
		}
		cout << "------" << endl;
		cout << "normal: "<<cipher << " " << endl;
		letter = ZZtoString(exp_mod( StringtoZZ(cipher) , d, N));	
		cout << letter << " ";
		new_msn += AddLeftZero(letter, size1+1);
		cout << "rubrica: " << AddLeftZero(ZZtoString(exp_mod( StringtoZZ(cipher) , d, N)), size1+1) << endl;
	}
	
	msn = new_msn;
	new_msn.clear();
	
	int size2 = ZZtoString(oN).size()-1;//N-1
	while(msn.size() > 0){
		if(msn.size()-1 > size2){
			cipher = msn.substr(0, size2);
			msn = msn.substr(size2, msn.size()-1);
		}else{
			cipher = msn;
			msn.clear();
		}
		cout << "---" << endl;
		cout << "rubrica-s: " << cipher << endl;
		letter = ZZtoString(exp_mod( StringtoZZ(cipher) , oe, oN));
		cout << "firma: " << letter << endl;
		new_msn += AddLeftZero(letter, size2+1);
	}
	msn = new_msn;
	return new_msn;
}
string RSA::_d(string msn){
	string new_msn, cipher, letter;
	int size1 = ZZtoString(N).size();			//N-1
	//cout << endl<<endl;
	while(msn.size() > 0){
		if(msn.size()-1 > size1){
			cipher = msn.substr(0, size1);
			msn = msn.substr(size1, msn.size()-1);
			letter = ZZtoString(exp_mod( StringtoZZ(cipher) , d, N));
			new_msn += AddLeftZero( letter, size1-1);
		}else{
			cipher = msn;
			msn.clear();
			letter = ZZtoString(exp_mod( StringtoZZ(cipher) , d, N));
			new_msn += letter;
		}
	}
	msn = new_msn;
	new_msn.clear();
	
	int size2 = ZZtoString(oN).size();//N-1
	while(msn.size() > 0){
		if(msn.size()-1 > size2){
			cipher = msn.substr(0, size2);
			msn = msn.substr(size2, msn.size()-1);
			letter = ZZtoString(exp_mod( StringtoZZ(cipher) , oe, oN));
			new_msn += AddLeftZero( letter, size2-1);
		}else{
			cipher = msn;
			msn.clear();
			letter = ZZtoString(exp_mod( StringtoZZ(cipher) , oe, oN));
			new_msn += letter;
		}
		//cout << "---" << endl;
		//cout << "rubrica: " << cipher << endl;
		//letter = ZZtoString(exp_mod( StringtoZZ(cipher) , oe, oN));
		//new_msn += AddLeftZero( letter, size2-1);
		//cout << "real: " << AddLeftZero(ZZtoString(exp_mod( StringtoZZ(cipher) , oe, oN)), size2-1) << endl;
	}
	msn = new_msn;
	
	return new_msn;
}
string RSA::ZZtoString(const ZZ num){
	stringstream buffer;
	buffer << num;
	return buffer.str();
}
ZZ RSA::StringtoZZ(string num){
	if(num != ""){
		ZZ b(INIT_VAL, num.c_str());
		return b;
	}else
		return ZZ(0);
}
string RSA::AddRightZero(string num, int n){
	int count = n-num.size();
	for (int i = 0; i < count; ++i){
		num += "0";
	}
	return num;
}
string RSA::AddLeftZero(string num, int n){
	int count = n-num.size();
	for (int i = 0; i < count; ++i)
		num.insert(0,"0");
	return num;
}

ZZ RSA::inversaMulti(void){
	ZZ number;
	//if(resto_minimo(this->e, this->N) == 1)
		number = exp_mod(this->e,this->ON-1,this->N);
	//else
	//	number = ZZ(-1);	
	return number;
}
ZZ RSA::randomPrime(int n){
	ZZ nnumber, s, c, z, p, t;
	bool st = true, ct = true;
	string number, newnumber, num;
	int a, b, d, e;
	/*Paso A*/

	ZZ seed = this->seed;
	
	/*Paso B*/
	for (int i = 0; i < n; ++i){
		s = (seed & (ZZ(1)<<3))>>3;
		c = (seed & (ZZ(1)<<2))>>2;
		z = mod(s+c, (ZZ)2);
		seed = (seed<<1)|z;
	}

	number = ZZtoStringBits(seed);
	number = number.substr(0, n);
	while(st){
		/*Paso C*/
		srand(time(NULL));
		p = mod((ZZ)rand(), (ZZ)n);
		t = mod((ZZ)rand(), (ZZ)n);//
		conv(b, p);
		conv(e, t);
		b = number[b]-'0';
		e = number[e]-'0';

		/*Paso D*/
		num = number.substr(0, n/2);
		a = num[0]-'0';
		num = num.substr(1, num.size());
		conv(b, mod(ZZ(b + a),(ZZ)2) );
		num += '0'+b;
		newnumber += num;

		num = number.substr(n/2, n);
		a = num[(num.size()-1)]-'0';
		num = num.substr(0,num.size()-1);
		conv(b, mod(ZZ(b + a),(ZZ)2) );
		num.insert(0, 1, b+'0');		
		newnumber += num;
		newnumber[0] = '1';
		number = newnumber;
		nnumber = StringtoZZBits(number);
		newnumber.clear();
		d = number[number.size()-1]-'0';


	    struct timeval tiq, tfq;
    	double tiempoq = 0;
	    if( (d & 1) )
			if(Miller( nnumber)) st = false;
	}
	
	return nnumber;
}
string RSA::ZZtoStringBits(ZZ num){
	string n;
	int b;
	ZZ a; 
	for (; num > 0;){
		a = mod(num, (ZZ)2);
		conv(b, a);
		n.insert(0,1,'0' + b);
		num = num>>1;
	}
	return n;
}
ZZ RSA::StringtoZZBits(string num){
	ZZ n = (ZZ)0;
	for (int i = num.size()-1; i >= 0; --i){
		if(num[i]-'0' == 1)
			n += ZZ(1)<<((num.size()-1) - i) ;
	}
	return n;
}
bool RSA::Miller(ZZ p){
    int z;

    /*if (p < 2)   			return false;*/
    if (p != 2 && mod(p, (ZZ)2)==0)	return false;
    
	int iteration = 5;
    ZZ s = p - 1;
    while (mod(s, (ZZ)2) == 0)      s = s >> 1;
    for (int i = 0; i < iteration; i++){ 
        conv(z, (p - 1) + 1);
        ZZ a = ZZ( mod(ZZ(rand()), ZZ(z))), temp = s;
        ZZ mod = exp_mod(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1){
            mod = mulmod(mod, mod, p);
            temp = temp << 1;
        }
        if (mod != p - 1 && temp % 2 == 0) return false;
    }
    return true;
}
ZZ RSA::mulmod(ZZ a, ZZ b, ZZ m)
{
    ZZ x = (ZZ)0,y = mod(a, m);
    while (b > 0)
    {
        if (mod(b, (ZZ)2) == 1)
            x = mod((x + y), m);
        y = mod((y * 2), m);
        b = b>>1;
    }
    return mod(x, m);
}
void RSA::setRSA(ZZ e,ZZ N){
	oe = e;
    oN = N;
}