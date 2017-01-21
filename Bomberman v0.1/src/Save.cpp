template <class al_f,class f>
Save<al_f,f>::Save(void){
	this->_font30 = al_load_font("fonts/free_sans.ttf",30,0);
	this->_font20 = al_load_font("fonts/free_sans.ttf",20,0);
	
	this->name_files.push_back("save/1.txt");
	this->name_files.push_back("save/2.txt");
	this->name_files.push_back("save/3.txt");
	this->_file = 0;
}

template <class al_f,class f>
Save<al_f,f>::~Save(void){
	al_destroy_font(this->_font30);
	al_destroy_font(this->_font20);
}

template <class al_f,class f>
f *Save<al_f,f>::File(char *t){
	fp = fopen(this->name_files[this->_file],t);
	if(!fp)
		cout << "No se pudo abrir el archivo" << endl;

	return fp;
}

template <class al_f,class f>
void Save<al_f,f>::showSave(Maps<ALLEGRO_BITMAP> &m, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,bool st){
	this->_file = input.getX(0); 
	m.showBackground();
	al_draw_text(this->_font30, al_map_rgb(0,0,0), 255, 130, 0, "Guardar o Recuperar partida");
	for(int y = 0; y<1;y++){
		for(int x = 0;x<3;x++){
		al_draw_filled_rectangle(80+(250*x), 200, 320+(250*x), 368, al_map_rgb(255,255,255));
		al_draw_rectangle(90+(250*x), 210, 310+(250*x), 358, al_map_rgb(200,200,200), 2);
		}
	}
	fp = fopen(this->name_files[0],"r");
	if(fgetc(fp) != EOF)
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*0), 265, 0, "FULL");
	else
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*0), 265, 0, "EMPTY");
	fclose(fp);

	fp = fopen(this->name_files[0],"r");
	if(fgetc(fp) != EOF)
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*1), 265, 0, "FULL");
	else
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*1), 265, 0, "EMPTY");
	fclose(fp);

	fp = fopen(this->name_files[0],"r");
	if(fgetc(fp) != EOF)
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*2), 265, 0, "FULL");
	else
		al_draw_text(this->_font20, al_map_rgb(70,70,70), 165 + (250*2), 265, 0, "EMPTY");
	fclose(fp);


	al_draw_rectangle(90+(250*input.getX(0)), 210, 310+(250*input.getX(0)), 358, al_map_rgb(140,40,40), 3);

	al_draw_filled_rectangle(368,380,532,420,al_map_rgb(40,40,40));

	if(st)
		al_draw_text(this->_font20, al_map_rgb(250,250,250), 395, 383, 0, "Guardar (G)");
	else
		al_draw_text(this->_font20, al_map_rgb(250,250,250), 395, 383, 0, "Cargar  (C)");
}