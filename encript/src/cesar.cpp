cesar::cesar(int clave){
	this->clave = clave;
	this->alf = "abcdefghijklmnopqrstuvwxyz ";
}
string cesar::_c(string msn){
	string new_msn = "";
	int c;
	for(int i = 0;i<msn.size();i++){
		c = alf.find(msn[i]) + this->clave;
		if(c > this->alf.size() - 1)
			c = c % this->alf.size();
		new_msn += this->alf[c];
	}
	
	return new_msn;
}
string cesar::_d(string msn){
	string new_msn = "";
	int c;
	for(int i = 0;i<msn.size();i++){
		c = alf.find(msn[i]) - this->clave;
		if(c < 0){
			c = this->alf.size() + (c % (int)this->alf.size());
		}
		new_msn += this->alf[c];
	}
	
	return new_msn;
}