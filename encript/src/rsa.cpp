RSA::RSA(ZZ N, ZZ e){
	this->alf = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
	/*Setting Claves*/
	this->N = N;
	this->e = e;
}
RSA::RSA(ZZ seed){
	this->seed = seed;
	this->alf = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
	/*Verificamos que se cree solo una sesion para 
	que no este cambiando a cada rato de session*/
	if(this->gpass == false){
		/*Generando claves*/
		//p = RandomPrime_ZZ(1022);
		struct timeval ti, tf;
		double tiempo;
		gettimeofday(&ti, NULL);

		p = randomPrime(1024);
		//q = RandomPrime_ZZ(1022);
		q = randomPrime(1024);
		this->N = p*q;
		ON = (p-1)*(q-1);

		while(true){
			//randomPrime(seed, 1024, 154);
			//this->e = RandomPrime_ZZ(1022);
			this->e = randomPrime(1024);
			if(this->e > ON) continue;
			this->d = inverse(this->e,ON);
			if( this->d != -1) break;
		}
		gettimeofday(&tf, NULL);   
			    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;        
			    printf("[Generacion de Claves Termino en %f milisegundos]\n", tiempo);
		/*Setting a gpass para que indique que ya 
		se a generado un session*/
		this->gpass = true;
	}
}
vector<ZZ> RSA::getPublic(void){
	vector<ZZ> v;
	v.push_back(this->e);
	v.push_back(this->N);
	return v;
}
/*string RSA::_c(string msn){
	string letter, new_msn = "", new_cipher = "",cipher = "";
	int size1, size2, o=0;
	ZZ num = (ZZ)0;

	size1 = ZZtoString((ZZ)this->alf.size()).size();//Zn
	size2 = ZZtoString(this->N).size();				//N

	for (int i = 0; i < msn.size(); ++i){
		letter = ZZtoString((ZZ)this->alf.find(msn[i]));
		new_msn += AddLeftZero( letter, size1 );
	}
	cout << new_msn << endl;
	
	for (int i = 0; i < new_msn.size();){
		for(o = i; o<(i+size1) and o < new_msn.size();o++){
			cipher += new_msn[o];
		}
		if(StringtoZZ(cipher) > this->N){
			cipher.replace(cipher.size()-size1, size1,"");
			new_cipher += AddLeftZero(ZZtoString(exp_mod( StringtoZZ(cipher) ,this->e, this->N)), size2);
			cipher.clear();
		}else if( o >= new_msn.size()){
			new_cipher += AddLeftZero(ZZtoString(exp_mod( StringtoZZ(cipher) ,this->e, this->N)), size2);
			i = new_msn.size();
			cipher.clear();
		}
		else
			i = i+size1;
	}
	cout << new_cipher << endl;
	return new_cipher;
}
string RSA::_d(string msn){
	string letter, new_msn = msn, new_cipher = "",cipher = "";
	int size1, size2, size3, indice;

	ZZ Dpi, Dpq, dp, dq;
	vector<ZZ> modl, ent;
	modl.push_back(this->p);
	modl.push_back(this->q);
	dp = mod(this->d, this->p-1 );
	dq = mod(this->d, this->q-1 );

	size1 = ZZtoString((ZZ)this->alf.size()).size();//Zn
	size2 = ZZtoString(this->N).size();				//N

	cout << msn<<endl;
	for (int i = 0; i < (new_msn.size()/size2); ++i){
		for (int o = i*size2; o < (i+1)*size2 and o < new_msn.size(); o++){
			cipher += new_msn[o];
		}
		Dpi = exp_mod(StringtoZZ(cipher), dp, p);
		Dpq = exp_mod(StringtoZZ(cipher), dq, q);
		ent.push_back(Dpi);
		ent.push_back(Dpq);
		cipher = ZZtoString(this->resto_chino(ent, modl));
		cout << cipher << endl;
		new_cipher += AddLeftZero(cipher, size1);
		cipher.clear();
		ent.clear();
	}
	new_msn = "";
	for (int i = 0; i < (new_cipher.size()/size1) ; ++i){
		for (int o = i*size1; o < (i+1)*size1 and o < new_cipher.size(); o++){
			letter += new_cipher[o];
		}
		conv(indice, StringtoZZ(letter));
		new_msn += this->alf[indice];
		letter = "";
	}
	cout << new_msn<<endl;
	return new_msn;
}*/
string RSA::_c(string msn){
	string letter, new_msn = "", new_cipher = "",cipher = "";
	int size1, size2, size3;
	ZZ num = (ZZ)0;

	size1 = ZZtoString((ZZ)this->alf.size()).size();//Zn
	size2 = ZZtoString(this->N).size()-1;			//N-1
	size3 = ZZtoString(this->N).size();				//N

	for (int i = 0; i < msn.size(); ++i){
		letter = ZZtoString((ZZ)this->alf.find(msn[i]));
		new_msn += AddLeftZero( letter, size1 );
	}
	for (int i = 0; i < (new_msn.size()/size2)+1; ++i){
		for (int o = i*size2; o < (i+1)*size2 and o < new_msn.size(); o++){
			cipher += new_msn[o];
		}
		cipher = AddRightZero(cipher, size2);
		new_cipher += AddLeftZero(ZZtoString(exp_mod( StringtoZZ(cipher) ,this->e, this->N)), size3);
		cipher.clear();
	}
	return new_cipher;
}
string RSA::_d(string msn){
	string letter, new_msn = msn, new_cipher = "",cipher = "";
	int size1, size2, size3, indice;

	ZZ Dpi, Dpq, dp, dq;
	vector<ZZ> modl, ent;
	modl.push_back(this->p);
	modl.push_back(this->q);
	dp = mod(this->d, this->p-1 );
	dq = mod(this->d, this->q-1 );

	size1 = ZZtoString((ZZ)this->alf.size()).size();//Zn
	size2 = ZZtoString(this->N).size()-1;			//N-1
	size3 = ZZtoString(this->N).size();				//N

	for (int i = 0; i < (new_msn.size()/size3); ++i){
		for (int o = i*size3; o < (i+1)*size3 and o < new_msn.size(); o++){
			cipher += new_msn[o];
		}
		Dpi = exp_mod(StringtoZZ(cipher), dp, p);
		Dpq = exp_mod(StringtoZZ(cipher), dq, q);
		ent.push_back(Dpi);
		ent.push_back(Dpq);
		cipher = ZZtoString(this->resto_chino(ent, modl));
		new_cipher += AddLeftZero(cipher, size2);
		cipher.clear();
		ent.clear();
	}
	new_msn = "";
	for (int i = 0; i < (new_cipher.size()/size1) ; ++i){
		for (int o = i*size1; o < (i+1)*size1 and o < new_cipher.size(); o++){
			letter += new_cipher[o];
		}
		conv(indice, StringtoZZ(letter));
		new_msn += this->alf[indice];
		letter = "";
	}
	cout << new_msn << endl;
	return new_msn;
}
ZZ RSA::resto_chino(vector<ZZ> a,vector<ZZ> p){
	bool st = true;
	ZZ P = (ZZ)1, x = (ZZ)0;
	vector<ZZ> Pi, qi, r;
	for(int i = 0; i < p.size(); i++)
		P *= p[i];

	for(int i = 0; i < p.size(); i++){
		Pi.push_back(P/p[i]);
		qi.push_back(inverse(mod(Pi[i],p[i]),p[i]));
		x += mod(a[i], P) * mod(Pi[i], P)  * mod(qi[i], P);
		x = mod(x, P);
	}
	return x;
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
    
    struct timeval ti, tf;
    double tiempo = 0;
    gettimeofday(&ti, NULL);  
	
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
    	gettimeofday(&tiq, NULL); 

	    if( (d & 1) )
			if(Miller( nnumber)) st = false;
		
		gettimeofday(&tfq, NULL);   
    	tiempoq = (tfq.tv_sec - tiq.tv_sec)*1000 + (tfq.tv_usec - tiq.tv_usec)/1000.0;        
    	printf("[Miller Termino en %f milisegundos]\n", tiempoq);
	}
	
    gettimeofday(&tf, NULL);   
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;        
    printf("[randomPrime Termino en %f milisegundos]\n", tiempo);
	
	cout << nnumber << endl  << endl << endl;
	
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
    
	int iteration = 1000;
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