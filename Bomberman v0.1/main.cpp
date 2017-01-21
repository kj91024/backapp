#include "src/HeaderManager.cpp"
#define displayWidth 901
#define displayHeight 675
#define FPS 13.0
int main(){
	FILE *fp;
	/*Initializer Allegro*/
	if(!al_init()){
		cout << "Allegro no se pudo iniciar";
		return -1;
	}
	/*Create Window*/
	ALLEGRO_DISPLAY *display;
	display = al_create_display(displayWidth,displayHeight);
	if(!display){ cout << "Fallo a crear el display" << endl; }
	al_set_window_title( display, "BomberMan" );

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

	
	al_reserve_samples(1);

	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	ALLEGRO_TIMER *frame_timer = al_create_timer(1.0/FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_SAMPLE *sound = al_load_sample("sound/title_music.ogg");
	ALLEGRO_SAMPLE *select = al_load_sample("sound/earth.ogg");	
	ALLEGRO_SAMPLE *enter = al_load_sample("sound/fire_1.ogg");
	

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frame_timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	

	ScreenManager s;
	InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> input;
	Maps<ALLEGRO_BITMAP> m;
	Player<ALLEGRO_BITMAP> p;
	
   	al_start_timer(timer);
    al_start_timer(frame_timer);
	
    bool done = false,draw = false,st = false,active1 = false,active2 = false,once = false,key_timer = false,sourceX = 0;
    char c;
	int x = 0, y = 0,ap1 = 0, ap2 = 0;
				
    while(!done){
		ALLEGRO_EVENT events;
	    al_wait_for_event(event_queue,&events);
	    al_get_keyboard_state(&key_state);

	    pressClose(done, events);
		pressEscape(events,s,input,p);
		pressEnter(done,once,events,s,input,p);
	    

	   	// Escoger el jugador
	   	actionChoosePlayer(events,s,input);
	   	
		useSave(st,m,events,fp,s,input,p);
	
		//Secciones del Juego
 	    if(events.type == ALLEGRO_EVENT_TIMER){
			if(events.timer.source == timer){
				draw = true;
		   		if(s.isCreateMenu()){

	    			//Player 1
	    			if(input.getX(0) >= 0 ) { input.setX(0, 0);}	    			
	    			if(input.getY(0) >= 3 ){ input.setY(0, 2);}

		   			s.showMenu(m, input);
		   		}
	    		else if(s.isCreateChoosePlayer()){
	    			m.loadMap(1);
	    			//Player 1
	    			if(input.getX(0) >= m.getWidth() ) { input.setX(0, m.getWidth()-1);}	    			
	    			if(input.getY(0) >= m.getHeight() ){ input.setY(0, m.getHeight()-1);}

	    			//Player 2
	    			if(input.getX(1) >= m.getWidth() ) { input.setX(1, m.getWidth()-1);}	    			
	    			if(input.getY(1) >= m.getHeight() ){ input.setY(1, m.getHeight()-1);}

	    			s.showChoosePlayer(m, input);
	    			s.drawButton();
	    		}else if(s.isCreateChooseMap()){
	    			//Player 1
	    			if(input.getX(0) >= 3 ) { input.setX(0, 2);}	    			
	    			if(input.getY(0) >= 1 ){ input.setY(0, 0);}
	    			s.showChooseMap(m, input);
	    			s.drawButton();
	    		}else if(s.isCreateBeginPlay()){
	    			// Descargamos el mapa en donde se va a jugar
	    			s.downloadMapPlayer(m, p);
	    			if(!once){
	    				//Activamos el uso del teclado
		   				input.setUserKeyboard(0, true);
		   				input.setUserKeyboard(1, true);

	    				s.showCreatePlay(m,p,input);
	    				
	    				once = true;
	    			}else{
	    				// Actualizar posicion actual
	    				p << input;
	    				s.showPlay(m,p,input);

	    				if(s.getMap(p.getX(0),p.getY(0)) == '5' || s.getMap(p.getX(1),p.getY(1)) == 'b'){
	    					s.setBeginPlay(false);
	    					s.setShowResults(true);
	    				}
	    			}
					p >> input;
	    		}else if(s.isCreateShowResults()){
	    			s.showCreatePlay(m,p,input);
	    			s.showResults(p);
	    		}else if(s.isCreateShowPause()){
	    			s.showCreatePlay(m,p,input);

					input.setUserKeyboard(0,true);
	    			
	    			//Player 1
	    			if(input.getX(0) >= 0 ) { input.setX(0, 0);}	    			
	    			if(input.getY(0) >= 3 ) { input.setY(0, 2);}

	    			s.showPause(p,input);
	    		}else if(s.isCreateSave()){
	    			//Player 1
	    			if(input.getX(0) >= 3 ) { input.setX(0, 2);}	    			
	    			if(input.getY(0) >= 1 ){ input.setY(0, 0);}
	    			s.showSave(m,input,s.getLoadMapPlayer());
	    			s.drawButton();
	    		}
	    	}
		}
		putBomb(events,s,input,p);

	    if(draw){
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
			draw = false;
		}

		actionKeyboard(events,active1,active2,key_state,frame_timer,timer,input,p);
	}
	//Destroys all libraries
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(frame_timer);
	al_destroy_event_queue(event_queue);
	al_destroy_sample(sound);
	al_destroy_sample(select);
	al_destroy_sample(enter);
	return 0;
}