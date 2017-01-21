beaufort::beaufort(string clave){
	this->clave = clave;
	this->alf = "abcdefghijklmnopqrstuvwxyz ";
}
string beaufort::_cd(string msn){
	string new_msn = "";
	int c = 0, l = 0;
	for(int i = 0;i<msn.size();i++){
		c = alf.find(this->clave[l]) - this->alf.find(msn[i]);
		//cout << c;
		if(c < 0)
			c = this->alf.size() + c;
		//cout << " "<< c << endl;
		new_msn += this->alf[c];
		
		if(l++ >= this->clave.size()-1)
			l = 0;
	}
	
	return new_msn;
}