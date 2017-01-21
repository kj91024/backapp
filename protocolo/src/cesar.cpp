cesar::cesar(ZZ clave){
	this->clave = clave;
	
	for(int i=0; i<256; i++) alf.push_back(NumberToString(i));
	alf.push_back(",");
	for(char i='a'; i<='z'; i++) alf.push_back(CharToString(i));
	alf.push_back(" ");
	for(char i='A'; i<='Z'; i++) alf.push_back(CharToString(i));
	alf.push_back("-");
	alf.push_back(".");
}
string cesar::_c(int msn){
	ZZ c;
	c = msn + clave;
	c = mod(c, (ZZ)alf.size());
	return ZZtoString(c);
}
string cesar::_d(ZZ msn){
	ZZ c;
	c = msn - clave;
	c = mod(c, (ZZ)alf.size());
	return ZZtoString(c);
}
string cesar::ZZtoString(const ZZ num){
	stringstream buffer;
	buffer << num;
	return buffer.str();
}