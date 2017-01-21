#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

//Allegro Inits
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
class PLAYER{
private:
	int lx, ly, x, y, heart, score;
public:
	PLAYER(void){
		this->lx = this->ly = this->x = this->y = this->score = 0;
		this->heart = 3;
	}
	void setPosition(const int x,const int y){
		this->x = x; 
		this->y = y;
	}
	void setLastPosition(const int x,const int y){ 
		this->lx = x;
		this->ly = y;
	}
	void incScore(void){ this->score = this->score+20; }
	void decScore(void){ this->score = this->score-10; }
	void incHeart(void){ this->heart++; }
	void decHeart(void){ this->heart--; }
	void decX(void){ this->lx = this->x--; }
	void decY(void){ this->ly = this->y--; }
	void incX(void){ this->lx = this->x++; }
	void incY(void){ this->ly = this->y++; }
	int getX(void){ return this->x;}
	int getY(void){ return this->y;}
	int getLastX(void){ return this->lx;}
	int getLastY(void){ return this->ly;}
	int getHeart(void){ return this->heart;}
	const char* getScore(void){
		int n = 0;
		int power = 1;
		int nalone;
		int num = this->score;
		char *s = new char;

		for( ; num > 0 ; power = power * 10, n++) {
			num = num/10;
			nalone = (this->score % (power*10)) / power;
			s[n] = '0'+nalone;
		}

		if(n == 0)	s[n] = '0';
		else{
			for(int a = n-1,b = 0;a >= b;a--,b++){
				char temp = s[a];	
				cout<<temp<<endl;
				s[a] = s[b];
				s[b] = temp;
			}
			s[n++] = '\0';
		}
		return s;
	}
};
class BOTS{
private:
	
public:
	void follow(){

	};
};
class MAP{
private:
	FILE *f;
	ALLEGRO_FONT *f15;
	vector<char> m[20];
	int mx,my;
	bool once;
public:
	MAP(void){
		this->my = 0;
		this->mx = 0;
		this->f = fopen("map/1.txt","r");
		this->once = false;
		this->f15 = al_load_font("fonts/free_sans.ttf",15,0);
	}
	~MAP(void){ al_destroy_font(this->f15); }
	char get(const int y,const int x){ return m[y][x]; }
	void set(const int y,const int x, const char c){ this->m[y][x] = c; }
	void load(PLAYER &p){
		if( !this->once ){
			char c;
			int x = 0;
			while( (c = fgetc(this->f)) != EOF ){
				if(c == 'j'){ 
					p.setPosition(x*20,my*20);
					p.setLastPosition(x*20,my*20);
					this->m[my][x] = ' ';
				}
				if(c != '\n') 
					m[this->my].push_back(c);
				
				if(c == '\n'){
					this->my++;
					x = 0;
				}else{ 
					this->mx++;
					x++;
				}
			}
			this->mx = (this->mx/my)-1;
			this->my++;
			this->once = true;
		}
	}
	bool colissionWall(PLAYER p){
		bool b = false;
		int wallHi, wallWi, wallHf, wallWf;
		int pHi, pWi, pHf, pWf;
		wallWi = wallHi = wallHf = wallWf = 0;
		pHi = p.getY(); pHf = pHi+20; 
		pWi = p.getX(); pWf = pWi+20;

		for(int y = 0; y < this->my ; y++){
			for(int x = 0; x < this->mx ; x++){
				//Detectando Choque
				if(this->m[y][x] == '+'){
					wallWi = x*20; wallWf = wallWi+20;
					wallHi = y*20; wallHf = wallHi+20;
					if((pWi == wallWi && ( (pHi > wallHi && pHi < wallHf) || (pHf > wallHi && pHf < wallHf))) || (pHi == wallHi && ( (pWi > wallWi && pWi < wallWf) || (pWf > wallWi && pWf < wallWf))) || ( ( ((pHi > wallHi && pHi < wallHf) || (pHf > wallHi && pHf < wallHf)) && ((pWi > wallWi && pWi < wallWf) || (pWf > wallWi && pWf < wallWf)) ) ))
						return true;
				}

			}
		}
		return false;
	}
	bool eating(PLAYER &p){
		bool b = false;
		int fruitHi, fruitWi, fruitHf, fruitWf;
		int pHi, pWi, pHf, pWf;
		fruitWi = fruitHi = fruitHf = fruitWf = 0;
		pHi = p.getY(); pHf = pHi+20; 
		pWi = p.getX(); pWf = pWi+20;

		for(int y = 0; y < this->my ; y++){
			for(int x = 0; x < this->mx ; x++){
				//Detectando Choque
				if(this->m[y][x] == '-'){
					fruitWi = (x*20)+6; fruitWf = fruitWi+8;
					fruitHi = (y*20)+6; fruitHf = fruitHi+8;
					if( (pWi < fruitWi && pWf > fruitWf) && (pHi < fruitHi && pHf > fruitHf) ){
						this->m[y][x] = ' ';
						p.incScore();
						return -1;
					}
				}
			}
		}
	}
	void print(PLAYER &p){
		for(int y = 0; y<this->my ; y++){
			for(int x = 0; x<this->mx ; x++){
				al_draw_filled_rectangle(x*20, y*20, (x*20)+20, (y*20)+20, al_map_rgb(30,30,30));
				switch(this->m[y][x]){
					case '+': 
						al_draw_filled_rectangle(x*20, y*20, (x*20)+20, (y*20)+20, al_map_rgb(20,20,20));
						al_draw_rectangle( (x*20)+6, (y*20)+6, (x*20)+14, (y*20)+14, al_map_rgb(50,50,50),2); 
					break;
					case '-': al_draw_filled_circle((x*20)+10, (y*20)+10, 4, al_map_rgb(100,100,100)); break;
					case 'a': al_draw_filled_rectangle(x*20, y*20, (x*20)+20, (y*20)+20, al_map_rgb(0,137,255)); break;
				}
			}
		}
		//Usuario
		//al_draw_filled_rectangle(p.getX()*20, p.getY()*20, (p.getX()*20)+20, (p.getY()*20)+20, al_map_rgb(255,212,0));
		al_draw_filled_rectangle(p.getX(), p.getY(), p.getX()+20, p.getY()+20, al_map_rgb(255,212,0));
		
		//Panel
		al_draw_filled_rectangle(0, 240, 260, 260, al_map_rgb(10,10,10));
		al_draw_text(this->f15, al_map_rgb(250,250,250), 5, 237, 0, "Score:");
		al_draw_text(this->f15, al_map_rgb(250,250,250), 50, 237, 0, p.getScore()); 
		//p.getScore();

		for(int i = 0;i<p.getHeart();i++)
			al_draw_filled_rectangle(215+(15*i), 245, 225+(15*i), 255, al_map_rgb(150,10,0));
		
	}
};
#define FPS 1.0 / 60.0
int main(){
	if(!al_init()){
		cout << "Allegro no se pudo iniciar";
		return -1;
	}

	ALLEGRO_DISPLAY *display;	
	display = al_create_display(260,260);
	if(!display){ cout << "Fallo a crear el display" << endl; }
	al_set_window_title( display, "Following" );

	/*Inserts libraries of Allegro*/
	al_install_keyboard();
	al_install_mouse();

	al_init_image_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	ALLEGRO_TIMER *frame_timer = al_create_timer(1.0/FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();


	MAP m;
	PLAYER p;
	PLAYER bot[4];

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frame_timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);
    al_start_timer(frame_timer);

    bool done = false;
    bool draw = false;
    int x,y;
    x = y = 0;
    while(!done){
		ALLEGRO_EVENT events;
	    al_wait_for_event(event_queue,&events);
	    al_get_keyboard_state(&key_state);

		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)		done = true;
		if(events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)	done = true;
	
		if(events.type == ALLEGRO_EVENT_TIMER){
			if(events.timer.source == timer){
				m.load(p);
				m.eating(p);
				draw = true;
			}
		}

		if(draw){
			m.print(p);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
			draw = false;
		}

		if(al_key_down(&key_state, ALLEGRO_KEY_DOWN))		{ p.incY(); if(m.colissionWall(p)) p.decY(); } 
		else if(al_key_down(&key_state, ALLEGRO_KEY_RIGHT)) { p.incX();	if(m.colissionWall(p)) p.decX(); } 
		else if(al_key_down(&key_state, ALLEGRO_KEY_UP)) 	{ p.decY();	if(m.colissionWall(p)) p.incY(); }
		else if(al_key_down(&key_state, ALLEGRO_KEY_LEFT)) 	{ p.decX();	if(m.colissionWall(p)) p.incX(); }
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frame_timer);
	al_destroy_event_queue(event_queue);
}