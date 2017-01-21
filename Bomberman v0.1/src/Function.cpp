void pressClose(bool &done,ALLEGRO_EVENT &events){
	if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)		{ done = true; }
}
void pressEscape(ALLEGRO_EVENT &events,ScreenManager &s,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,Player<ALLEGRO_BITMAP> &p){
	if(input.IsKeyPressed(events,ALLEGRO_KEY_ESCAPE)){
			if(s.isCreateChoosePlayer()){
	   			s.setMenu(true);
				s.setChoosePlayer(false);
				s.restartInput(input);
			}else if(s.isCreateChooseMap()){
	   			s.setChoosePlayer(true);	
				s.setChooseMap(false);
				s.restartInput(input);				

				s.setReadyPlayer(0,false);
				s.setReadyPlayer(1,false);			
			}else if(s.isCreateBeginPlay()){
				s.setBeginPlay(false);
				s.setShowPause(true);
				
				s.restartInput(input);

				input.setUserKeyboard(0,false);
				input.setUserKeyboard(1,false);

				s.setNoAnimatePlay(true);

			}else if(s.isCreateSave()){
				s.setNoAnimatePlay(false);
				if(s.getLoadMapPlayer()){
					s.setBeginPlay(true);
					s.setSave(false);

			   		input.setUserKeyboard(0, true);
			   		input.setUserKeyboard(1, true);

			   		input.setX(0, p.getLastX(0));
			   		input.setY(0, p.getLastY(0));

			   		input.setX(1, p.getLastX(1));
			   		input.setY(1, p.getLastY(1));
				}else{
					s.setSave(false);
					s.setMenu(true);
					s.restartInput(input);
				}
			}
		}
}


void pressEnter(bool &done,bool &once,ALLEGRO_EVENT &events,ScreenManager &s,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,Player<ALLEGRO_BITMAP> &p){
	if(input.IsKeyPressed(events,ALLEGRO_KEY_ENTER)){
	   		if(s.isCreateMenu()){
	   			//&s = menu;
	   			switch(s.getButtonSelectMenu()){
	   				case 0: 
	   					s.setMenu(false);
	   					s.setChoosePlayer(true);
	   				break;
	   				case 1:
	   					s.setMenu(false);
						s.setSave(true);
	   					s.setButtonSelectMenu(-1);
	   				break;
	   				case 2: done = true; break;	
	   			}

				s.restartInput(input);
				s.setReadyPlayer(0,false);
				s.setReadyPlayer(1,false);
	   		}else if(s.isCreateChoosePlayer()){
	   			if(s.getReadyPlayer(0) == 1 && s.getReadyPlayer(1) == 1){	   				
	   				p.pushAvatar(s.getAvatarCodePlayer1(), s.getAvatarCodePlayer2());
	   				s.setChoosePlayer(false);
	   				s.setChooseMap(true);
	   			
	   				input.setUserKeyboard(0, true);
	   				s.restartInput(input);
	   			}
	   		}else if(s.isCreateChooseMap()){
	   			s.setChooseMap(false);
	   			s.setBeginPlay(true);

	   			input.setUserKeyboard(0, true);
	   			input.setUserKeyboard(1, false);

	   			s.restartInput(input);
	   		}else if(s.isCreateShowResults()){
	   			input.setUserKeyboard(0, true);
	   			input.setUserKeyboard(1, true);

				s.setMenu(true);
	   			s.setBeginPlay(false);
	   			s.setShowResults(false);
	   			
				s.restartInput(input);

				s.setLoadMapPlayer(false);
				once = false;
			}else if(s.isCreateShowPause()){
				switch(s.getButtonSelectPause()){
	   				case 0: 
	   					s.setShowPause(false);
	   					s.setBeginPlay(true);

			   			input.setUserKeyboard(0, true);
			   			input.setUserKeyboard(1, true);

			   			input.setX(0, p.getLastX(0));
			   			input.setY(0, p.getLastY(0));

			   			input.setX(1, p.getLastX(1));
			   			input.setY(1, p.getLastY(1));

						s.setNoAnimatePlay(false);
	   				break;
	   				case 1:
	   					s.setShowPause(false);
						s.setSave(true);
	   					s.setButtonSelectPause(-1);
	   				break;
	   				case 2: done = true; break;	
	   			}
			}else if(s.isCreateSave()){

			}else{
				done = false;
			}
	   	}
}

void actionKeyboard(ALLEGRO_EVENT &events,bool &active1,bool &active2,ALLEGRO_KEYBOARD_STATE key_state,ALLEGRO_TIMER *frame_timer,ALLEGRO_TIMER *timer,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,Player<ALLEGRO_BITMAP> &p){
	// Accion del Keyboard
	    if(events.type == ALLEGRO_EVENT_TIMER){
	
			if(events.timer.source == timer){
				active1 = true;
				active2 = true;
					 if(al_key_down(&key_state, ALLEGRO_KEY_S))	{
					 	input.incY(0); 
					 	if (input.getUserKeyboard(0) && input.getUserKeyboard(1))
					 		p.setDir(0, 0);
					 }
				else if(al_key_down(&key_state, ALLEGRO_KEY_D)) {
					input.incX(0); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(0, 3);
				}
				else if(al_key_down(&key_state, ALLEGRO_KEY_W)) {
					input.decY(0); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(0, 2);
				}
				else if(al_key_down(&key_state, ALLEGRO_KEY_A)) {
					input.decX(0); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(0, 1);
				}
				else active1 = false;

					 if(al_key_down(&key_state, ALLEGRO_KEY_DOWN))	{
					 	input.incY(1); 
					 	if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
					 		p.setDir(1, 0);
					 }
				else if(al_key_down(&key_state, ALLEGRO_KEY_RIGHT)) {
					input.incX(1); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(1, 3);
				}
				else if(al_key_down(&key_state, ALLEGRO_KEY_UP)) 	{
					input.decY(1); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(1, 2);
				}
				else if(al_key_down(&key_state, ALLEGRO_KEY_LEFT)) 	{
					input.decX(1); 
					if(input.getUserKeyboard(0) && input.getUserKeyboard(1))
						p.setDir(1, 1);
				}
				else active2 = false;				
			
			} else if (events.timer.source == frame_timer && input.getUserKeyboard(0) && input.getUserKeyboard(1)){
			    /*Graficos de Movimiento de player 1*/
			    if(active1) p.incSource(0);
			    else   	    p.setSource(0,-4);

			    if(p.getSource(0) >= 224) p.setSource(0,-4);

			    /*Graficos de Movimiento de player 2*/
			    if(active2) p.incSource(1);
			    else    	p.setSource(1,-4);

			    if(p.getSource(1) >= 224) p.setSource(1,-4);
	    	}
		}
}

void putBomb(ALLEGRO_EVENT &events,ScreenManager &s,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,Player<ALLEGRO_BITMAP> &p){
	//Poner bomba
	   	if(s.isCreateBeginPlay() && input.getUserKeyboard(0) && input.getUserKeyboard(1)){
	   		if(input.IsKeyPressed(events, ALLEGRO_KEY_T))
	   			p.putBomb(p.getX(0),p.getY(0),0);
	   		
	   		if(input.IsKeyPressed(events, ALLEGRO_KEY_P))
	   			p.putBomb(p.getX(1),p.getY(1),1);
	   	}
}

void useSave(bool &st,Maps<ALLEGRO_BITMAP> &m,ALLEGRO_EVENT &events,FILE* fp,ScreenManager &s,InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input,Player<ALLEGRO_BITMAP> &p){
	//Cargar Partida o Guardar Partida
	   	if(s.isCreateSave()){
	   		if(input.IsKeyPressed(events, ALLEGRO_KEY_C) && !s.getLoadMapPlayer()){
	   			cout << "Cargar Partida" << endl;
	   			fp = s.File("r");
	   			char c;
	   			int x,y,ap1,ap2;
	   			x = y = ap1 = ap2 = 0;
	   			while((c = fgetc(fp)) != EOF){
					if(y < 14){
						if(c == '\n'){
							y++;
							x = -1;
						}else{
							st = true;
							s.setMap(x,y,c);
							switch(c){
								case 'j': p.setX(0,x); p.setY(0,y); p.setLastX(0,x); p.setLastY(0,y); p.setDir(0,0); break;
								case 'g': p.setX(1,x); p.setY(1,y); p.setLastX(1,x); p.setLastY(1,y); p.setDir(1,0); break;

								case 'x': p.setX(0,x); p.setY(0,y); p.setLastX(0,x); p.setLastY(0,y); p.setDir(0,0); p.putBomb(x,y,0); break;
								case 'y': p.setX(1,x); p.setY(1,y); p.setLastX(1,x); p.setLastY(1,y); p.setDir(1,0); p.putBomb(x,y,1); break;
								
								case 'z': p.putBomb(x,y,0); break;  
							}
						}
						x++;
					}else{
						if(y == 15 ){
							ap1 = c - '0'; 	
						}else if( y == 17){
							ap2 = c - '0';
						}
						y++;
					}
				}
				
				if(st){
					s.setNoAnimatePlay(false);
					m.setWidth(20);
					m.setHeight(14);
					x = y = 0;
					p.pushAvatar(ap1, ap2);
					s.setLoadMapPlayer(true);
					s.setSave(false);
					s.setBeginPlay(true);
					st = false;
				}

				fclose(fp);
	   		}else if(input.IsKeyPressed(events, ALLEGRO_KEY_G) && s.getLoadMapPlayer()){
	   			cout << "Guardar Partida" << endl;
	   			fp = s.File("w");
	   			for(int y = 0;y<m.getHeight();y++){
					for(int x = 0;x<m.getWidth();x++){
						fputc(s.getMap(x,y),fp);	
						if(x == (m.getWidth()-1) && y >= 0){
							fputc('\n',fp);
						}
					}
				}

				fputc('\n',fp);
				fputc(s.getAvatarCodePlayer1()+'0',fp);	fputc('\n',fp);
				fputc(s.getAvatarCodePlayer2()+'0',fp);

				fclose(fp);
	   		}
	   	}
}
void actionChoosePlayer(ALLEGRO_EVENT &events,ScreenManager &s, InputManager<ALLEGRO_EVENT,ALLEGRO_KEYBOARD_STATE> &input){
	if(s.isCreateChoosePlayer()){
	   		if(input.IsKeyPressed(events, ALLEGRO_KEY_T)){
	   			if(s.readyPlayer(0, input))
	   				input.setUserKeyboard(0, false);
	   			else
	   				input.setUserKeyboard(0, true);
	   		}
	   		if(input.IsKeyPressed(events, ALLEGRO_KEY_P)){
	   			if(s.readyPlayer(1, input))
	   				input.setUserKeyboard(1, false);
	   			else
	   				input.setUserKeyboard(1, true);
	   		}
	   	}
}

