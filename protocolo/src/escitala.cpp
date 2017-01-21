escitala::escitala(int clave){
	this->clave = clave;
}
string escitala::_c(string msn){
	string new_msn;
	for( int i = 0; i < msn.size() % clave; i++) msn += '-';
	for( int i = 0; i < clave; i++ ){
		for( int j = i; j < msn.size(); j = j + clave )
			new_msn += msn[j];
	}
	return new_msn;
}
string escitala::_d(string msn){
	string new_msn;
	int n = (int)( (msn.size() + (msn.size() % clave)) /clave);
	for( int i = 0; i < n; i++ ){
		for( int j = i; j < msn.size(); j = j + n )
			if(msn[j] != '-') new_msn += msn[j];
	}
	return new_msn;
}