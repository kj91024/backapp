#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h> // Crear objetos graficos
#include <allegro5/allegro_image.h> // Insertar imagenes
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cmath>
using namespace std; 

#define ScreenWidth 800
#define ScreenHeight 600

bool Collision(float x,float y, float ex, float ey, int width, int height){
	if(x + width < ex || x > ex + width || y + height < ey || y > ey + height){
	//if(sqrt(pow(x - ex,2) + pow (y - ey,2)) < width + height){
		return false;
	}
	return true;
}

int main(int argc, char **argv){
	al_init();
	
	ALLEGRO_DISPLAY *display;
	ALLEGRO_COLOR a = al_map_rgb(44, 117, 255);
	ALLEGRO_COLOR b = al_map_rgb(225, 225, 0);

	enum Direction { DOWN, UP, LEFT, RIGHT };

	const int FPS = 60.0;

	if(!al_init()){
		cout << "No se pudo iniciar Allegro" << endl;
		return -1;
	}
	display = al_create_display(ScreenWidth,ScreenHeight);
	if(!display){
		cout << "Fallo a crear el display" << endl;
		return -1;
	}
	al_set_window_title(display,"DragonCity v0.1");

	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_SAMPLE *sound;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_BITMAP *file_image = al_load_bitmap("spritesheet7.png");
	ALLEGRO_BITMAP *file_image1 = al_load_bitmap("spritesheet7.png");
	sound = al_load_sample("muerte.wav");

	al_reserve_samples(1);


    ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
    ALLEGRO_TIMER *frame_timer = al_create_timer(1.0/FPS);
	event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(frame_timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

 	al_start_timer(timer);
 	al_start_timer(frame_timer);

    bool done = false, draw = true, active = false;
    int x = 0, y = 0, step = 5,sourceX = 0, sourceY = 0, dir = DOWN;

    while(!done){
    	ALLEGRO_EVENT events;
	    al_wait_for_event(event_queue,&events);
	    al_get_keyboard_state(&key_state);

	    if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
	    	done = true;
	    }else if(events.type == ALLEGRO_EVENT_TIMER){
	    	if(events.timer.source == timer){
		    	active = true;
		    	if(al_key_down(&key_state,ALLEGRO_KEY_DOWN)){
		    		y += step;
		    		dir = DOWN;
		    		//al_play_sample(sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
		    	}else if(al_key_down(&key_state,ALLEGRO_KEY_UP)){
		    		y -= step;
		    		dir = UP;
		    	}else if(al_key_down(&key_state,ALLEGRO_KEY_LEFT)){
		    		x -= step;
		    		dir = LEFT;
		    	}else if(al_key_down(&key_state,ALLEGRO_KEY_RIGHT)){
		    		x += step;
		    		dir = RIGHT;
		    	} else
		    		active = false;

		   		if(Collision(x, y, 200, 200, 130, 130)){
		   			cout << "choque"<<endl;
		   			if(dir == DOWN){
			    		y -= step;
			    	}else if(dir == UP){
			    		y += step;
			    	}else if(dir == LEFT){
			    		x += step;
			    	}else if(dir = RIGHT){
			    		x -= step;
			    	}	
		   		}else{
		   			cout << "sin choque"<<endl;
		   		}

	    	} else if (events.timer.source == frame_timer){
			    if(active)
			    	sourceX += al_get_bitmap_width(file_image) / 6;
			    else  
			    	sourceX = 130;

			    if(sourceX >= al_get_bitmap_width(file_image))
			    	sourceX = 0;

			    sourceY = dir;
	    	}
	    	draw = true;
	    }

	    if(draw){
		    al_draw_bitmap_region(file_image, sourceX, sourceY * al_get_bitmap_width(file_image) / 6, 130, 130, x, y, 0);
		    al_draw_bitmap_region(file_image1, 0, 0, 130, 130, 200, 200, 0);
		    al_flip_display();
			al_clear_to_color(al_map_rgb(10,10,10));
		}
	}

	// al_rest(2.0); 
	al_destroy_display(display);
	al_destroy_timer(frame_timer);
	al_destroy_event_queue(event_queue);
	al_destroy_sample(sound);
	return 0;
}