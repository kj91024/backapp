bool files::isFile(const char *fp){
	if(fopen(fp,"r"))
		return true;	
	else
		return false;
}
string files::readString(const char *fp){	
	char c;
	this->fp = fopen(fp,"r");
	while((c = fgetc(this->fp)) != EOF)
		s += c;
	return s;
}
ZZ files::readZZ(const char *fp){	
	char c;
	ZZ number = (ZZ)0;
	this->fp = fopen(fp,"r");
	while((c = fgetc(this->fp)) != EOF)
		number = (number * 10) + (c - '0');
	return number;
}
void files::writeString(const char *fp, string text){
	this->fp = fopen(fp,"w+");
	for(int i = 0;i<text.size();i++){
		fputc(text[i],this->fp);
	}
}
void files::writeZZ(const char *fp, ZZ text){
	string msn = ZZtoString(text);
	this->fp = fopen(fp,"w+");
	for(int i = 0;i<msn.size();i++)
		fputc(msn[i],this->fp);
}
void files::close(void){
	if(this->fp){
		fclose(this->fp);
		s.clear();
	}else
		cout << "ERROR: No hay ningun archivo abierto."<<endl;
}