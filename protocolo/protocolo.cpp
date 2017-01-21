#include "src/lib.cpp"
using namespace std;
using namespace NTL;
using namespace cv;

int main(int argc, char const *argv[]){
	
	files f;
	protocolo me, other;

	me.h = NULL;
    me.c = NULL;
    me.rsa = NULL;
    me.g = NULL;

    other.h = NULL;
    other.c = NULL;
    other.rsa = NULL;
    other.g = NULL;

	ZZ p, g, A, B, e,N, e1, e2;
	vector<ZZ> data, u;
	vector<string> o;
	string msn;
	
	bool t, t1, t2, t3;
	t = t1 = t2 = t3 = true;	
	int aux, temp, temp1, temp2, n_e, n_r;

	while(t){
		cout << "1. Iniciar Sesion" << endl;
		cout << "2. Salir" << endl;
		cout << "Opcion:  "; cin >> aux;
		cout << endl;
		switch(aux){
			case 1:
				me.takePhoto();
				data = me.getSeed();
				while(t1){
					cout << "1. Ver Informacion"<<endl;
					cout << "2. Conexion Diffie Hellman"<<endl;
					cout << "3. Conexion RSA"<<endl;
					cout << "4. Conexion Gamal"<<endl;
					cout << "5. Encripto" << endl;
					cout << "6. Desencripto" << endl;
					cout << "7. Cerrar Sesion" << endl;
					cout << "Opcion:  "; cin >> temp;
					cout << endl;
					switch(temp){
						case 1:
							cout << "--Diffie Hellan--" << endl;
							cout << "K: " << me.h->getK()<<endl;
							cout << "--RSA--" << endl;
							cout << "e: " << me.h->getPublic()[0]<<endl;
							cout << "N: " << me.h->getPublic()[1]<<endl;
							cout << "--Gamal--" << endl;
							cout << "e1: " << me.g->getPublic()[0]<<endl;
							cout << "e2: " << me.g->getPublic()[1]<<endl;
							cout << "p: " << me.g->getPublic()[1]<<endl;
							
						break;
						case 2://Diffie Hellman
							while(t2){
								cout << "1. Lo genero" << endl;
								cout << "2. Otro Genera" <<  endl;
								cout << "3. Salir"<<endl;
								cout << "Opcion:  "; cin >> temp1;
								cout << endl;
								switch(temp1){
									case 1:
										me.h = new hellman(20, data[0]);
										u = me.h->getPublic();
										cout << "Dar---" << endl;
										cout << "p: "<< u[0]<<endl;
										cout << "g: "<< u[1]<<endl;
										cout << "A: "<< u[2]<<endl;
										/*ocultar
										other.h = new hellman(20, data[1], u[0], u[1], u[2]);
										other.setK( other.h->getK() );
										cout << "Toma B: " << other.h->getB() << endl;
										ocultar*/
										cout << "Pedir---" << endl;
										cout << "B: ";cin>>B;
										me.h->setB( B );
										me.setK( me.h->getK() );
										cout <<	me.h->getK() << endl;	
									break;
									case 2:
										/*ocultar
										other.h = new hellman(20, data[1]);
										u = other.h->getPublic();
										cout << "Toma p: " << u[0]<<endl;
										cout << "Toma g: " << u[1]<<endl;
										cout << "Toma A: " << u[2]<<endl;
										ocultar*/
										cout << "Pedir---" << endl;
										cout << "p: "; cin >> p;
										cout << "g: "; cin >> g;
										cout << "A: "; cin >> A;
										me.h = new hellman(20, data[1], p, g, A);
										me.setK( me.h->getK() );
										cout << "Dar---" << endl;
										cout << "B:" << me.h->getB() << endl;
										cout <<	me.h->getK() << endl;
										/*ocultar
										other.h->setB( me.h->getB() );
										other.setK( other.h->getK() );
										ocultar*/
									break;
									case 3: t2 = false; break;
								}
							}
							t2 = true;
						break;
						case 3:
							while(t2){
								cout << "1. Añadir datos externos(cifrar)" <<  endl;
								cout << "2. Lo genero(decifrar)" << endl;
								cout << "3. Salir"<<endl;
								cout << "Opcion:  "; cin >> temp1;
								cout << endl;

								/*ocultar
								if(other.rsa == NULL)
									other.rsa = new RSA(data[2]);
								ocultar*/
								if(me.rsa == NULL)
									me.rsa = new RSA(data[2]);
								switch(temp1){
									case 1:
										/*ocultar
										u = other.rsa->getPublic();
										cout << "Toma e: " << u[0] << endl;
										cout << "Toma N: " << u[1] << endl;
										ocultar*/
										cout << "Pedir---" << endl;
										cout << "oe: "; cin >> e;
										cout << "oN: "; cin >> N;
										me.rsa->setRSA(e, N);
									break;
									case 2:
										u = me.rsa->getPublic();
										cout << "Dar---" << endl;
										cout << "e: "<< u[0]<<endl;
										cout << "N: "<< u[1]<<endl;
										/*ocultar
										other.rsa->setRSA(u[0], u[1]);
										ocultar*/	
									break;
									case 3: t2 = false; break;
								}
							}
							t2 = true;
						break;
						case 4:
							while(t2){
								cout << "1. Lo genero con datos externos(es para encriptar)" <<  endl;
								cout << "2. Lo genero con mis datos(es para desencriptar)" << endl;
								cout << "3. Salir"<<endl;
								cout << "Opcion:  "; cin >> temp1;
								cout << endl;
								switch(temp1){
									case 1:
										/*ocultar
										if(other.g == NULL)
											other.g = new gamal(20, data[1]);
										u = other.g->getPublic();
										cout << "Toma e1: " << u[0] << endl;
										cout << "Toma e2: " << u[1] << endl;
										cout << "Toma p: " << u[2] << endl;
										ocultar*/
										cout << "Pedir---" << endl;
										cout << "e1: "; cin >> e1;
										cout << "e2: "; cin >> e2;
										cout << "p: "; cin >> p;
										me.g = new gamal(20, data[2],e1, e2, p);
									break;
									case 2:
										if(me.g == NULL)
											me.g = new gamal(20, data[1]);
										u = me.g->getPublic();
										cout << "Dar---" << endl;
										cout << "e1: "<< u[0]<<endl;
										cout << "e2: "<< u[1]<<endl;	
										cout << "p: "<< u[2]<<endl;	
										/*ocultar
										other.g = new gamal(20, data[2], u[0], u[1], u[2]);
										ocultar*/
									break;
									case 3: t2 = false; break;
								}
							}
							t2 = true;
						break;
						case 5:
							msn = me._ccesar();				
							cout << "Se a cifrado con Cesar"<<endl;
							msn = me.rsa->_c( me.getEC() );
							cout << "Se a cifrado con RSA"<<endl;
							me.setEC(msn);
							msn = f.readString("files/msn.txt");
							cout << "Texto cifrado"<< endl;
							msn = me.g->_c(msn);
							msn += "#";
							cout << "Imagen cifrada"<< endl;
							msn += me.g->_ci(me.getEC());		
							me.setEC(msn);
							cout << "Se a cifrado con Gamal"<<endl;

							if(f.isFile("files/cifrado.txt")){
								f.writeString("files/cifrado.txt", msn);
								f.close();
								cout << "Guardado en el archivo cifrado.txt " << endl;
							}else cout << "El archivo cifrado.txt no existe" << endl;
							cout << endl;
						break;
						case 6:
							/*msn = f.readString("files/cifrado.txt");
							o = other.proc(msn);
							msn = other.g->_d(o[0]);

							cout << "Decifrado con Gamal"<< endl;
							cout << "Texto decifrado"<< endl;
							if(f.isFile("files/decifrado.txt")){
								f.writeString("files/decifrado.txt", msn);
								f.close();
								cout << "Guardado en el archivo decifrado.txt " << endl;
							}else cout << "El archivo decifrado.txt no existe" << endl;
							
							msn = other.g->_di(o[1]);
							cout << "Imagen decifrado"<< endl;
							
							cout << "Decifrado con RSA"<< endl;
							msn = other.rsa->_d(msn);
							other.setEC(msn);

							cout << "Decifrado con Cesar"<< endl;
							msn = other._dcesar(msn);				
							other.setEC(msn);
							cout << "Mostrando imagen"<<endl;
							other.showPhoto();*/

							msn = f.readString("files/cifrado.txt");
							cout << "cifrado" << msn << endl;
							o = me.proc(msn);
							msn = me.g->_d(o[0]);

							cout << "Decifrado con Gamal"<< endl;
							cout << "Texto decifrado"<< endl;
							if(f.isFile("files/decifrado.txt")){
								f.writeString("files/decifrado.txt", msn);
								f.close();
								cout << "Guardado en el archivo decifrado.txt " << endl;
							}else cout << "El archivo decifrado.txt no existe" << endl;
							
							msn = me.g->_di(o[1]);
							cout << "Imagen decifrado"<< endl;
							
							cout << "Decifrado con RSA"<< endl;
							msn = other.rsa->_d(msn);
							me.setEC(msn);

							cout << "Decifrado con Cesar"<< endl;
							msn = me._dcesar(msn);				
							me.setEC(msn);
							cout << "Mostrando imagen"<<endl;
							me.showPhoto();
						break;
						case 7: t1 = false; break;
					}
				}
				t1 = true;
			break;
			case 2: t = false; break;
		}
	}
	


	
	
	return 0;
}

//767147
//383574