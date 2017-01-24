hellman::hellman(int bits, ZZ seed){
	this->alf = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
 	this->seed = seed;
 	p = criba_(bits);	//	p
	g = findGen(p);	// {1,3,...,p-2}
	a = randomPrime(bits, true);
	A = exp_mod((ZZ)g, a, (ZZ)p);
}
vector<ZZ> hellman::getPublic(void){
	vector<ZZ> v;
	v.push_back((ZZ)p);
	v.push_back((ZZ)g);
	v.push_back(A);
	return v;
}
void hellman::setB(ZZ B){
	K = exp_mod(B, a, (ZZ)p);
	//K = mod(exp_mod(B, a, p), (ZZ)alf.size());
}

hellman::hellman(int bits, ZZ seed, ZZ p, ZZ g, ZZ A){
	this->alf = "abcdefghijklmnopqrstuvwxyz ";
	this->seed = seed;
	b = criba_(bits);
	B = exp_mod(g, b, p);
	K = exp_mod(A, b, p);
	//K = mod(exp_mod(A, b, p), (ZZ)alf.size());
}
ZZ hellman::getB(void){ return B; }
ZZ hellman::getK(void){ return K; }


string hellman::_c(string msn){
	string new_msn = "";
	int c;
	for(int i = 0;i<msn.size();i++){
		conv(c, alf.find(msn[i]) + K);
		if(c > this->alf.size() - 1)
			c = c % this->alf.size();
		new_msn += this->alf[c];
	}
	
	return new_msn;
}
string hellman::_d(string msn){
	string new_msn = "";
	int c;
	for(int i = 0;i<msn.size();i++){
		conv(c, alf.find(msn[i]) - K);
		if(c < 0){
			c = this->alf.size() + (c % (int)this->alf.size());
		}
		new_msn += this->alf[c];
	}
	
	return new_msn;
}

bool hellman::Miller(ZZ p){
    int z;

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
unsigned hellman::criba_(int bt){
	int64_t t = 1;
	t = (t<<bt)-1;
	cout << t << endl;
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
	cout << "olas" << endl;
	return 0;
}
unsigned hellman::findGen(unsigned p){
	unsigned g = p/2;
	unsigned q = (p-1)/2;
	unsigned found = 0;
	for (; g < (p-1) and found != 1; ++g)
		if(exp_mod((ZZ)g,(ZZ)2,(ZZ)p) != 1 and exp_mod((ZZ)g,(ZZ)q,(ZZ)p) != 1)	found = 1;
	return g;
}

ZZ hellman::randomPrime(int n, bool flag){
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
	n = (flag) ? ((3*n)/4) : n;
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
	
	    if( (d & 1) )
			if(Miller( nnumber)) st = false;
	}
	
    //gettimeofday(&tf, NULL);   
    // Instante final    
    //tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;        
    //printf("[Termino en %f milisegundos]\n", tiempo);
	//cout << nnumber << endl;
	return nnumber;
}
string hellman::ZZtoStringBits(ZZ num){
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
ZZ hellman::StringtoZZBits(string num){
	ZZ n = (ZZ)0;
	for (int i = num.size()-1; i >= 0; --i){
		if(num[i]-'0' == 1)
			n += ZZ(1)<<((num.size()-1) - i) ;
	}
	return n;
}