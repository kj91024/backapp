gamal::gamal(int bits, ZZ seed){
	this->alf = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
	this->seed = seed;
	
	//struct timeval tiq, tfq;
    //double tiempoq = 0;
    //gettimeofday(&tiq, NULL);
	
	p = randomPrime(bits);
	
	//gettimeofday(&tfq, NULL);
    //tiempoq = (tfq.tv_sec - tiq.tv_sec)*1000 + (tfq.tv_usec - tiq.tv_usec)/1000.0;
    //printf("[Miller Termino en %f milisegundos]\n", tiempoq);
	//cout << p << endl;
	
	e1 = findGen(p);
	while( (d = mod(seed, p-2)) < 2 ) seed = seed << 1;
	e2 = exp_mod(e1, d, p);
}
gamal::gamal(int bits, ZZ seed, ZZ e1, ZZ e2, ZZ p){
	this->alf = "0123456789,abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ-.";
	this->seed = seed;
	
	this->p = p;
	this->e1 = e1;
	this->e2 = e2;

	while( (r = mod(seed, p-2)) < 2 ) seed = seed << 1;
	c1 = exp_mod(e1, r, p);
}
vector<ZZ> gamal::getPublic(void){
	vector<ZZ> v;
	v.push_back(e1);
	v.push_back(e2);
	v.push_back(p);
	return v;
}
string gamal::_c(string msn){
	string new_msn, letter;
	int size = ZZtoString(p).size();
	new_msn += AddLeftZero(ZZtoString(c1), size);
	for (int i = 0; i < msn.size(); ++i){
		c2 = exp_mod(e2, r, p);
		letter = ZZtoString(mod(c2*(ZZ)this->alf.find(msn[i]), p));
		new_msn += AddLeftZero(letter, size);
	}
	return new_msn;
}
string gamal::_d(string msn){
	string new_msn;
	ZZ s, letter;
	int in, size = ZZtoString(p).size(), ls;
	c1 = StringtoZZ(msn.substr(0, size));
	ZZ p1 = exp_mod(c1, d, p);
	ZZ p2 = inverse(p1, p);

	msn = msn.substr(size, msn.size());
	ls = msn.size()/size;
	for (int i = 0; i < ls; ++i){
		s = StringtoZZ(msn.substr(0, size));
		conv(in, mod(s*p2, p));
		new_msn += alf[in];
		msn = msn.substr(size, msn.size());
	}
	return new_msn;
}

ZZ gamal::findGen(ZZ p){
	ZZ g = p/2;
	ZZ q = (p-1)/2;
	int found = 0;
	for (; g < (p-1) and found != 1; ++g)
		if(exp_mod(g,(ZZ)2,p) != 1 and exp_mod(g,q,p) != 1)	found = 1;
	return g;
}
ZZ gamal::randomPrime(int n){
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
		// Mejora para ir a por un primo
		newnumber[0] = '1';
		newnumber[newnumber.size()-1] = '1';
		number = newnumber;
		nnumber = StringtoZZBits(number);
		

	    //struct timeval tiq, tfq;
    	//double tiempoq = 0;
    	//gettimeofday(&tiq, NULL); 
		
		//cout << "normal" << endl;
		if(Miller( nnumber ) and Miller( (nnumber-1)/2 )) return nnumber;
		nnumber = StringtoZZBits(giro(newnumber));
		//cout << "mejora" << endl;
		if(Miller( nnumber ) and Miller( (nnumber-1)/2 )) return nnumber;
		newnumber.clear();
		//gettimeofday(&tfq, NULL);   
    	//tiempoq = (tfq.tv_sec - tiq.tv_sec)*1000 + (tfq.tv_usec - tiq.tv_usec)/1000.0;        
    	//printf("[Miller Termino en %f milisegundos]\n", tiempoq);
	}
	
    //gettimeofday(&tf, NULL);   
    //tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;        
    //printf("[randomPrime Termino en %f milisegundos]\n", tiempo);
	
	//cout << nnumber << endl  << endl << endl;
}
string gamal::ZZtoStringBits(ZZ num){
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
ZZ gamal::StringtoZZBits(string num){
	ZZ n = (ZZ)0;
	for (int i = num.size()-1; i >= 0; --i){
		if(num[i]-'0' == 1)
			n += ZZ(1)<<((num.size()-1) - i) ;
	}
	return n;
}
bool gamal::Miller(ZZ p){
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
string gamal::giro(string m){                       
	char temp;                                        
	for (int i = 0, j = m.size()-1; i < j; ++i,--j){   
		temp = m[i];                                
		m[i] = m[j];                                
		m[j] = temp;                                
	}                                               
	return m;                                       
}
string gamal::ZZtoString(const ZZ num){
	stringstream buffer;
	buffer << num;
	return buffer.str();
}
ZZ gamal::StringtoZZ(string num){
	if(num != ""){
		ZZ b(INIT_VAL, num.c_str());
		return b;
	}else
		return ZZ(0);
}
string gamal::AddRightZero(string num, int n){
	int count = n-num.size();
	for (int i = 0; i < count; ++i){
		num += "0";
	}
	return num;
}
string gamal::AddLeftZero(string num, int n){
	int count = n-num.size();
	for (int i = 0; i < count; ++i)
		num.insert(0,"0");
	return num;
}