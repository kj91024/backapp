Bomberman DeadMatch v0.1
El juego es libre y muy facil de entender como logica de juego.

Instalacion solo en Linux - Ubuntu:
	- Allegro 5.0
	- Compilador de C++ (g++)

Instalacion de Allegro 5.0 en Ubuntu
	- Pagina oficial http://liballeg.org/, donde se puede descargar el archivo
	  tambien podemos clonarlo o descargarlo desde su repositorio https://github.com/liballeg/allegro5
	
	- Abrimos terminal
	
	- Entramos al archivo donde esta ubicado allegro5
	  ejemplo:
	  	cd Descargas/allegro5
	
	- Ahora tenemos que instalarlo, usamos los siguientes comandos:
		Primero paso - cmake .
		Segundo paso - make
		Tercer paso  - sudo make install

	- Para saber si se a instalado correctamente digitamos el siguiente comando:
		pkg-config --list-all | grep allegro
		Aqui veremos todas las librerias de allegro instaladas, algo como esto:
			allegro-5 
			allegro_font-5 
			allegro_color-5 
			allegro_image-5 
			allegro_memfile-5 
			allegro_ttf-5 
			allegro_physfs-5 
			allegro_dialog-5 
			allegro_acodec-5 
			allegro_video-5 
			allegro_main-5 
			allegro_primitives-5 
			allegro_audio-5

Para la compilacion del main.cpp se deve tener las librerias declaradas antes;
	
	Librerias a Declarar:
	pkg-config --libs allegro-5 allegro_font-5 allegro_color-5 allegro_image-5 allegro_memfile-5 allegro_ttf-5 
	allegro_physfs-5 allegro_dialog-5 allegro_acodec-5 allegro_video-5 allegro_main-5 allegro_primitives-5 allegro_audio-5

	En Consola:
	g++ '${file}' -o '${file_path}/${file_base_name}' `pkg-config --libs allegro-5 allegro_font-5 allegro_color-5
	llegro_image-5 allegro_memfile-5 allegro_ttf-5 allegro_physfs-5 allegro_dialog-5 allegro_acodec-5 allegro_video-5 
	allegro_main-5 allegro_primitives-5 allegro_audio-5` && ./${file_base_name}

	NOTA: Es muy necesario instalar allegro 5.0 o mayor

Instalacion de G++ en Ubuntu:
	- Abrir terminal y escribir esto: 
		sudo apt-get install g++
		El sistema lo va a descomprimir e instalar automaticamente.