afin::afin(int clave){
	this->clave = clave;
	this->alf = "abcdefghijklmnopqrstuvwxyz ";
	
	/*Generando claves*/
	while(true){
		RandomBits(this->kpublic,10);
		this->kprivate = inverse(this->kpublic,ZZ(27));
		if( this->kprivate != -1) break;
	}
}
ZZ afin::getKeyPublic(void){return this->kpublic;}
ZZ afin::getKeyPrivate(void){return this->kprivate;}
string afin::_c(ZZ a, string msn){
	string new_msn;
	ZZ new_l, size;
	int indice;
	for (int i = 0; i < msn.size(); ++i){
		new_l = ZZ(a*this->alf.find(msn[i])+clave);
		size = ZZ(this->alf.size());
		conv(indice,mod(new_l, size));
		new_msn += alf[indice];
	}
	return new_msn;
}
string afin::_d(ZZ a, string msn){
	string new_msn;
	ZZ new_l, size;
	int indice;
	for (int i = 0; i < msn.size(); ++i){
		new_l = ZZ(a*(this->alf.find(msn[i])) - clave);
		size = ZZ(this->alf.size());
		conv(indice,mod(new_l, size));
		new_msn += alf[indice];
	}
	return new_msn;
}