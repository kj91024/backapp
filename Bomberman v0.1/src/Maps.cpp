template <class al_b>
Maps<al_b>::Maps( void ){
	this->_level = 0;
	this->_init = true;
	this->_background = al_load_bitmap("img/block.jpg");
}

template <class al_b>
Maps<al_b>::~Maps(void){
	al_destroy_bitmap(this->_background);
}

template <class al_b>
int Maps<al_b>::getWidth(void){ return this->_w; }

template <class al_b>
void Maps<al_b>::setWidth(int c){this->_w = c;}

template <class al_b>
int Maps<al_b>::getHeight(void){ return this->_h; }

template <class al_b>
void Maps<al_b>::setHeight(int c){this->_h = c;}

template <class al_b>
int Maps<al_b>::getLevel( void ){return this->_level;}

template <class al_b>
int Maps<al_b>::setLevel( const int new_level ){ this->_level = new_level; }

template <class al_b>
bool Maps<al_b>::getInit( void ){ return this->_init;}

template <class al_b>
bool Maps<al_b>::changeInit( bool h ){  this->_init = h;}

template <class al_b>
char Maps<al_b>::getPositionMap(int x, int y){ return this->map[y][x];}

template <class al_b>
//char Maps::getMap(int x, int y){return this->map[y][x];}
char Maps<al_b>::loadMap(int type, int level = 0, bool b = false){
	switch(type){
		case 0://Menu
			this->map[0][0] = 'x';
			this->map[1][0] = 'x';
			this->_w = 1; this->_h = 2;
		break;
		case 1://ChoosePlayer
			this->map[0][0] = 'x'; this->map[0][1] = 'x'; this->map[0][2] = 'x';
			this->map[1][0] = 'x'; this->map[1][1] = 'x'; this->map[1][2] = 'x';
			this->_w = 3; this->_h = 2;
		break;
		case 2://ChooseMap
			this->map[0][0] = 'x'; this->map[0][1] = 'x'; this->map[0][2] = 'x';
			this->_w = 3; this->_h = 1;
		case 3:
			switch(level){
				case 0:
					map[0][0]  = 'p'; map[0][1]  = 'p';map[0][2]  = 'p';map[0][3]  = 'p';map[0][4]  = 'p';map[0][5]  = 'p';map[0][6]  = 'p'; map[0][7]  = 'p';map[0][8]  = 'p'; map[0][9]  = 'p';map[0][10]  = 'p'; map[0][11]  = 'p';  map[0][12]  = 'p';  map[0][13] = 'p';  map[0][14] = 'p';  map[0][15] = 'p';map[0][16]  = 'p';  map[0][17]  = 'p';map[0][18]  = 'p';map[0][19]  = 'p';
					map[1][0]  = 'p'; map[1][1]  = 'j';map[1][2]  = 'e';map[1][3]  = 'd';map[1][4]  = 'c';map[1][5]  = 'd';map[1][6]  = 'd'; map[1][7]  = 'd';map[1][8]  = 'd'; map[1][9]  = 'd';map[1][10]  = 'd'; map[1][11]  = 'd';  map[1][12]  = 'd';  map[1][13] = 'd';  map[1][14] = 'd';  map[1][15] = 'c';  map[1][16]  = 'd';  map[1][17]  = 'd';map[1][18]  = 'd';map[1][19]  = 'p';
					map[2][0]  = 'p'; map[2][1]  = 'e';map[2][2]  = 'd';map[2][3]  = 'd';map[2][4]  = 'c';map[2][5]  = 'd';map[2][6]  = 'd'; map[2][7]  = 'e';map[2][8]  = 'e'; map[2][9]  = 'e';map[2][10]  = 'e'; map[2][11]  = 'e';  map[2][12]  = 'e';  map[2][13] = 'd';  map[2][14] = 'd';  map[2][15] = 'c';  map[2][16]  = 'd';  map[2][17]  = 'd';map[2][18]  = 'd';map[2][19]  = 'p';
					map[3][0]  = 'p'; map[3][1]  = 'e';map[3][2]  = 'd';map[3][3]  = 'd'; map[3][4]  = 'c';map[3][5]  = 'd';map[3][6]  = 'd'; map[3][7]  = 'c';map[3][8]  = 'c'; map[3][9]  = 'c';map[3][10]  = 'c'; map[3][11]  = 'c';  map[3][12]  = 'c';  map[3][13] = 'd';  map[3][14] = 'd';  map[3][15] = 'c';  map[3][16]  = 'd';  map[3][17]  = 'd';map[3][18]  = 'd';map[3][19]  = 'p';
					map[4][0]  = 'p'; map[4][1]  = 'd';map[4][2]  = 'd';map[4][3]  = 'd';map[4][4]  = 'c';map[4][5]  = 'd';map[4][6]  = 'd'; map[4][7]  = 'd';map[4][8]  = 'd'; map[4][9]  = 'd';map[4][10]  = 'd'; map[4][11]  = 'd';  map[4][12]  = 'd';  map[4][13] = 'd';  map[4][14] = 'd';  map[4][15] = 'c';  map[4][16]  = 'd';  map[4][17]  = 'd';map[4][18]  = 'd';map[4][19]  = 'p';
					map[5][0]  = 'p'; map[5][1]  = 'd';map[5][2]  = 'd';map[5][3]  = 'd';map[5][4]  = 'c';map[5][5]  = 'd';map[5][6]  = 'd'; map[5][7]  = 'd';map[5][8]  = 'd'; map[5][9]  = 'd'; map[5][10]  = 'd'; map[5][11]  = 'd';  map[5][12]  = 'd';  map[5][13] = 'd';  map[5][14] = 'd';  map[5][15] = 'c';map[5][16]  = 'd';  map[5][17]  = 'd';map[5][18]  = 'd';map[5][19]  = 'p';
					map[6][0]  = 'p'; map[6][1]  = 'c';map[6][2]  = 'd';map[6][3]  = 'd';map[6][4]  = 'd';map[6][5]  = 'd'; map[6][6]  = 'd'; map[6][7]  = 'd';map[6][8]  = 'd'; map[6][9]  = 'd';map[6][10]  = 'd'; map[6][11]  = 'd';  map[6][12]  = 'd';  map[6][13] = 'd';  map[6][14] = 'd';  map[6][15] = 'd';map[6][16]  = 'd';  map[6][17]  = 'd';map[6][18]  = 'c';map[6][19]  = 'p';
					map[7][0]  = 'p'; map[7][1]  = 'c';map[7][2]  = 'd';map[7][3]  = 'd';map[7][4]  = 'd';map[7][5]  = 'd';map[7][6]  = 'd'; map[7][7]  = 'd';map[7][8]  = 'd'; map[7][9]  = 'd';map[7][10]  = 'd'; map[7][11]  = 'd';  map[7][12]  = 'd';  map[7][13] = 'd';  map[7][14] = 'd';  map[7][15] = 'd';  map[7][16]  = 'd';  map[7][17]  = 'd';map[7][18]  = 'c';map[7][19]  = 'p';
					map[8][0]  = 'p'; map[8][1]  = 'd';map[8][2]  = 'd';map[8][3]  = 'd';map[8][4]  = 'c';map[8][5]  = 'd';map[8][6]  = 'd'; map[8][7]  = 'd'; map[8][8]  = 'd'; map[8][9]  = 'd'; map[8][10]  = 'd'; map[8][11]  = 'd';  map[8][12]  = 'd';  map[8][13] = 'd';  map[8][14] = 'd';  map[8][15] = 'c';  map[8][16]  = 'd';  map[8][17]  = 'd';map[8][18]  = 'd';map[8][19]  = 'p';
					map[9][0]  = 'p'; map[9][1]  = 'd';map[9][2]  = 'd';map[9][3]  = 'd';map[9][4]  = 'c';map[9][5]  = 'd';map[9][6]  = 'd'; map[9][7]  = 'd';map[9][8]  = 'd'; map[9][9]  = 'd';map[9][10]  = 'd'; map[9][11]  = 'd';  map[9][12]  = 'd';  map[9][13] = 'd';  map[9][14] = 'd';  map[9][15] = 'c';  map[9][16]  = 'd';  map[9][17]  = 'd';map[9][18]  = 'd';map[9][19]  = 'p';
					map[10][0] = 'p'; map[10][1] = 'd'; map[10][2] = 'd'; map[10][3] = 'd';map[10][4] = 'c'; map[10][5] = 'd'; map[10][6] = 'd'; map[10][7] = 'c'; map[10][8] = 'c'; map[10][9] = 'c'; map[10][10] = 'c'; map[10][11] = 'c';  map[10][12] = 'c'; map[10][13] = 'd'; map[10][14] = 'd'; map[10][15] = 'c';  map[10][16] = 'd';  map[10][17] = 'd';map[10][18] = 'e';map[10][19] = 'p';
					map[11][0] = 'p'; map[11][1] = 'd'; map[11][2] = 'd'; map[11][3] = 'd'; map[11][4] = 'c'; map[11][5] = 'd'; map[11][6] = 'd'; map[11][7] = 'e'; map[11][8] = 'e'; map[11][9] = 'e'; map[11][10] = 'e'; map[11][11] = 'e';  map[11][12] = 'e'; map[11][13] = 'd'; map[11][14] = 'd'; map[11][15] = 'c';  map[11][16] = 'd';  map[11][17] = 'd';map[11][18] = 'e';map[11][19] = 'p';
					map[12][0] = 'p'; map[12][1] = 'd'; map[12][2] = 'd'; map[12][3] = 'd'; map[12][4] = 'c'; map[12][5] = 'd'; map[12][6] = 'd'; map[12][7] = 'd'; map[12][8] = 'd'; map[12][9] = 'd'; map[12][10] = 'd'; map[12][11] = 'd';  map[12][12] = 'd'; map[12][13] = 'd'; map[12][14] = 'd'; map[12][15] = 'c';  map[12][16] = 'd';  map[12][17] = 'e';map[12][18] = 'g';map[12][19] = 'p';
					map[13][0] = 'p'; map[13][1] = 'p'; map[13][2] = 'p'; map[13][3] = 'p'; map[13][4] = 'p'; map[13][5] = 'p'; map[13][6] = 'p'; map[13][7] = 'p'; map[13][8] = 'p'; map[13][9] = 'p'; map[13][10] = 'p'; map[13][11] = 'p';  map[13][12] = 'p'; map[13][13] = 'p'; map[13][14] = 'p'; map[13][15] = 'p';  map[13][16] = 'p';  map[13][17] = 'p';map[13][18] = 'p';map[13][19] = 'p';
					this->_w = 20; this->_h = 14;
				break;
				case 1:
					map[0][0]  = 'p'; map[0][1]  = 'p';map[0][2]  = 'p';map[0][3]  = 'p';map[0][4]  = 'p';map[0][5]  = 'p';map[0][6]  = 'p'; map[0][7]  = 'p';map[0][8]  = 'p'; map[0][9]  = 'p';map[0][10]  = 'p'; map[0][11]  = 'p';  map[0][12]  = 'p';  map[0][13] = 'p';  map[0][14] = 'p';  map[0][15] = 'p';map[0][16]  = 'p';  map[0][17]  = 'p';map[0][18]  = 'p';map[0][19]  = 'p';
					map[1][0]  = 'p'; map[1][1]  = 'e';map[1][2]  = 'e';map[1][3]  = 'e';map[1][4]  = 'e';map[1][5]  = 'e';map[1][6]  = 'e'; map[1][7]  = 'e';map[1][8]  = 'e'; map[1][9]  = 'e';map[1][10]  = 'e'; map[1][11]  = 'e';  map[1][12]  = 'e';  map[1][13] = 'e';  map[1][14] = 'e';  map[1][15] = 'e';  map[1][16]  = 'e';  map[1][17]  = 'e';map[1][18]  = 'e';map[1][19]  = 'p';
					map[2][0]  = 'p'; map[2][1]  = 'e';map[2][2]  = 'd';map[2][3]  = 'd';map[2][4]  = 'd';map[2][5]  = 'd';map[2][6]  = 'd'; map[2][7]  = 'd';map[2][8]  = 'd'; map[2][9]  = 'd';map[2][10]  = 'd'; map[2][11]  = 'd';  map[2][12]  = 'd';  map[2][13] = 'd';  map[2][14] = 'd';  map[2][15] = 'd';  map[2][16]  = 'd';  map[2][17]  = 'd';map[2][18]  = 'e';map[2][19]  = 'p';
					map[3][0]  = 'p'; map[3][1]  = 'e';map[3][2]  = 'd';map[3][3]  = 'd'; map[3][4]  = 'd';map[3][5]  = 'd';map[3][6]  = 'd'; map[3][7]  = 'c';map[3][8]  = 'd'; map[3][9]  = 'c';map[3][10]  = 'c'; map[3][11]  = 'd';  map[3][12]  = 'c';  map[3][13] = 'd';  map[3][14] = 'd';  map[3][15] = 'd';  map[3][16]  = 'd';  map[3][17]  = 'c';map[3][18]  = 'e';map[3][19]  = 'p';
					map[4][0]  = 'p'; map[4][1]  = 'e';map[4][2]  = 'c';map[4][3]  = 'd';map[4][4]  = 'd';map[4][5]  = 'd';map[4][6]  = 'd'; map[4][7]  = 'd';map[4][8]  = 'j'; map[4][9]  = 'e';map[4][10]  = 'e'; map[4][11]  = 'e';  map[4][12]  = 'd';  map[4][13] = 'd';  map[4][14] = 'd';  map[4][15] = 'd';  map[4][16]  = 'c';  map[4][17]  = 'c';map[4][18]  = 'e';map[4][19]  = 'p';
					map[5][0]  = 'p'; map[5][1]  = 'e';map[5][2]  = 'd';map[5][3]  = 'c';map[5][4]  = 'd';map[5][5]  = 'd';map[5][6]  = 'd'; map[5][7]  = 'c';map[5][8]  = 'e'; map[5][9]  = 'c'; map[5][10]  = 'c'; map[5][11]  = 'e';  map[5][12]  = 'c';  map[5][13] = 'd';  map[5][14] = 'd';  map[5][15] = 'd';map[5][16]  = 'd';  map[5][17]  = 'd';map[5][18]  = 'e';map[5][19]  = 'p';
					map[6][0]  = 'p'; map[6][1]  = 'e';map[6][2]  = 'd';map[6][3]  = 'd';map[6][4]  = 'c';map[6][5]  = 'd'; map[6][6]  = 'd'; map[6][7]  = 'd';map[6][8]  = 'e'; map[6][9]  = 'c';map[6][10]  = 'c'; map[6][11]  = 'e';  map[6][12]  = 'd';  map[6][13] = 'd';  map[6][14] = 'd';  map[6][15] = 'd';map[6][16]  = 'd';  map[6][17]  = 'd';map[6][18]  = 'e';map[6][19]  = 'p';
					map[7][0]  = 'p'; map[7][1]  = 'e';map[7][2]  = 'd';map[7][3]  = 'c';map[7][4]  = 'd';map[7][5]  = 'd';map[7][6]  = 'd'; map[7][7]  = 'c';map[7][8]  = 'e'; map[7][9]  = 'c';map[7][10]  = 'c'; map[7][11]  = 'e';  map[7][12]  = 'c';  map[7][13] = 'd';  map[7][14] = 'd';  map[7][15] = 'd';  map[7][16]  = 'd';  map[7][17]  = 'd';map[7][18]  = 'e';map[7][19]  = 'p';
					map[8][0]  = 'p'; map[8][1]  = 'e';map[8][2]  = 'c';map[8][3]  = 'd';map[8][4]  = 'd';map[8][5]  = 'd';map[8][6]  = 'd'; map[8][7]  = 'd'; map[8][8]  = 'e'; map[8][9]  = 'e'; map[8][10]  = 'e'; map[8][11]  = 'g';  map[8][12]  = 'd';  map[8][13] = 'd';  map[8][14] = 'd';  map[8][15] = 'd';  map[8][16]  = 'd';  map[8][17]  = 'd';map[8][18]  = 'e';map[8][19]  = 'p';
					map[9][0]  = 'p'; map[9][1]  = 'e';map[9][2]  = 'd';map[9][3]  = 'd';map[9][4]  = 'd';map[9][5]  = 'd';map[9][6]  = 'd'; map[9][7]  = 'c';map[9][8]  = 'd'; map[9][9]  = 'c';map[9][10]  = 'c'; map[9][11]  = 'd';  map[9][12]  = 'c';  map[9][13] = 'd';  map[9][14] = 'd';  map[9][15] = 'd';  map[9][16]  = 'd';  map[9][17]  = 'd';map[9][18]  = 'e';map[9][19]  = 'p';
					map[10][0] = 'p'; map[10][1] = 'e'; map[10][2] = 'd'; map[10][3] = 'd';map[10][4] = 'd'; map[10][5] = 'd'; map[10][6] = 'd'; map[10][7] = 'd'; map[10][8] = 'd'; map[10][9] = 'd'; map[10][10] = 'd'; map[10][11] = 'd';  map[10][12] = 'd'; map[10][13] = 'd'; map[10][14] = 'd'; map[10][15] = 'd';  map[10][16] = 'd';  map[10][17] = 'd';map[10][18] = 'e';map[10][19] = 'p';
					map[11][0] = 'p'; map[11][1] = 'e'; map[11][2] = 'd'; map[11][3] = 'd'; map[11][4] = 'd'; map[11][5] = 'd'; map[11][6] = 'd'; map[11][7] = 'd'; map[11][8] = 'd'; map[11][9] = 'd'; map[11][10] = 'd'; map[11][11] = 'd';  map[11][12] = 'd'; map[11][13] = 'd'; map[11][14] = 'd'; map[11][15] = 'd';  map[11][16] = 'd';  map[11][17] = 'd';map[11][18] = 'e';map[11][19] = 'p';
					map[12][0] = 'p'; map[12][1] = 'e'; map[12][2] = 'e'; map[12][3] = 'e'; map[12][4] = 'e'; map[12][5] = 'e'; map[12][6] = 'e'; map[12][7] = 'e'; map[12][8] = 'e'; map[12][9] = 'e'; map[12][10] = 'e'; map[12][11] = 'e';  map[12][12] = 'e'; map[12][13] = 'e'; map[12][14] = 'e'; map[12][15] = 'e';  map[12][16] = 'e';  map[12][17] = 'e';map[12][18] = 'e';map[12][19] = 'p';
					map[13][0] = 'p'; map[13][1] = 'p'; map[13][2] = 'p'; map[13][3] = 'p'; map[13][4] = 'p'; map[13][5] = 'p'; map[13][6] = 'p'; map[13][7] = 'p'; map[13][8] = 'p'; map[13][9] = 'p'; map[13][10] = 'p'; map[13][11] = 'p';  map[13][12] = 'p'; map[13][13] = 'p'; map[13][14] = 'p'; map[13][15] = 'p';  map[13][16] = 'p';  map[13][17] = 'p';map[13][18] = 'p';map[13][19] = 'p';
					this->_w = 20; this->_h = 14;
				break;
				case 2:
					map[0][0]  = 'p'; map[0][1]  = 'p';map[0][2]  = 'p';map[0][3]  = 'p';map[0][4]  = 'p';map[0][5]  = 'p';map[0][6]  = 'p'; map[0][7]  = 'p';map[0][8]  = 'p'; map[0][9]  = 'p';map[0][10]  = 'p'; map[0][11]  = 'p';  map[0][12]  = 'p';  map[0][13] = 'p';  map[0][14] = 'p';  map[0][15] = 'p';map[0][16]  = 'p';  map[0][17]  = 'p';map[0][18]  = 'p';map[0][19]  = 'p';
					map[1][0]  = 'p'; map[1][1]  = 'j';map[1][2]  = 'e';map[1][3]  = 'c';map[1][4]  = 'c';map[1][5]  = 'c';map[1][6]  = 'd'; map[1][7]  = 'd';map[1][8]  = 'd'; map[1][9]  = 'd';map[1][10]  = 'd'; map[1][11]  = 'd';  map[1][12]  = 'd';  map[1][13] = 'd';  map[1][14] = 'd';  map[1][15] = 'd';  map[1][16]  = 'd';  map[1][17]  = 'd';map[1][18]  = 'd';map[1][19]  = 'p';
					map[2][0]  = 'p'; map[2][1]  = 'e';map[2][2]  = 'd';map[2][3]  = 'd';map[2][4]  = 'c';map[2][5]  = 'c';map[2][6]  = 'd'; map[2][7]  = 'd';map[2][8]  = 'd'; map[2][9]  = 'd';map[2][10]  = 'd'; map[2][11]  = 'd';  map[2][12]  = 'd';  map[2][13] = 'd';  map[2][14] = 'd';  map[2][15] = 'd';  map[2][16]  = 'd';  map[2][17]  = 'd';map[2][18]  = 'd';map[2][19]  = 'p';
					map[3][0]  = 'p'; map[3][1]  = 'e';map[3][2]  = 'd';map[3][3]  = 'c'; map[3][4]  = 'd';map[3][5]  = 'c';map[3][6]  = 'd'; map[3][7]  = 'd';map[3][8]  = 'd'; map[3][9]  = 'd';map[3][10]  = 'd'; map[3][11]  = 'd';  map[3][12]  = 'd';  map[3][13] = 'd';  map[3][14] = 'd';  map[3][15] = 'd';  map[3][16]  = 'd';  map[3][17]  = 'd';map[3][18]  = 'd';map[3][19]  = 'p';
					map[4][0]  = 'p'; map[4][1]  = 'd';map[4][2]  = 'd';map[4][3]  = 'd';map[4][4]  = 'd';map[4][5]  = 'd';map[4][6]  = 'd'; map[4][7]  = 'd';map[4][8]  = 'd'; map[4][9]  = 'd';map[4][10]  = 'd'; map[4][11]  = 'd';  map[4][12]  = 'd';  map[4][13] = 'd';  map[4][14] = 'd';  map[4][15] = 'd';  map[4][16]  = 'd';  map[4][17]  = 'd';map[4][18]  = 'd';map[4][19]  = 'p';
					map[5][0]  = 'p'; map[5][1]  = 'd';map[5][2]  = 'd';map[5][3]  = 'c';map[5][4]  = 'd';map[5][5]  = 'c';map[5][6]  = 'd'; map[5][7]  = 'd';map[5][8]  = 'd'; map[5][9]  = 'd'; map[5][10]  = 'd'; map[5][11]  = 'd';  map[5][12]  = 'd';  map[5][13] = 'd';  map[5][14] = 'd';  map[5][15] = 'd';map[5][16]  = 'd';  map[5][17]  = 'd';map[5][18]  = 'd';map[5][19]  = 'p';
					map[6][0]  = 'p'; map[6][1]  = 'd';map[6][2]  = 'd';map[6][3]  = 'd';map[6][4]  = 'd';map[6][5]  = 'd'; map[6][6]  = 'd'; map[6][7]  = 'd';map[6][8]  = 'd'; map[6][9]  = 'd';map[6][10]  = 'd'; map[6][11]  = 'd';  map[6][12]  = 'd';  map[6][13] = 'd';  map[6][14] = 'd';  map[6][15] = 'd';map[6][16]  = 'd';  map[6][17]  = 'd';map[6][18]  = 'd';map[6][19]  = 'p';
					map[7][0]  = 'p'; map[7][1]  = 'd';map[7][2]  = 'd';map[7][3]  = 'c';map[7][4]  = 'd';map[7][5]  = 'c';map[7][6]  = 'd'; map[7][7]  = 'd';map[7][8]  = 'd'; map[7][9]  = 'd';map[7][10]  = 'd'; map[7][11]  = 'd';  map[7][12]  = 'd';  map[7][13] = 'd';  map[7][14] = 'd';  map[7][15] = 'd';  map[7][16]  = 'd';  map[7][17]  = 'd';map[7][18]  = 'd';map[7][19]  = 'p';
					map[8][0]  = 'p'; map[8][1]  = 'd';map[8][2]  = 'd';map[8][3]  = 'd';map[8][4]  = 'd';map[8][5]  = 'd';map[8][6]  = 'd'; map[8][7]  = 'd'; map[8][8]  = 'd'; map[8][9]  = 'd'; map[8][10]  = 'd'; map[8][11]  = 'd';  map[8][12]  = 'd';  map[8][13] = 'd';  map[8][14] = 'd';  map[8][15] = 'd';  map[8][16]  = 'd';  map[8][17]  = 'd';map[8][18]  = 'd';map[8][19]  = 'p';
					map[9][0]  = 'p'; map[9][1]  = 'd';map[9][2]  = 'd';map[9][3]  = 'c';map[9][4]  = 'd';map[9][5]  = 'c';map[9][6]  = 'd'; map[9][7]  = 'd';map[9][8]  = 'd'; map[9][9]  = 'd';map[9][10]  = 'd'; map[9][11]  = 'd';  map[9][12]  = 'd';  map[9][13] = 'd';  map[9][14] = 'd';  map[9][15] = 'd';  map[9][16]  = 'd';  map[9][17]  = 'd';map[9][18]  = 'e';map[9][19]  = 'p';
					map[10][0] = 'p'; map[10][1] = 'd'; map[10][2] = 'd'; map[10][3] = 'd';map[10][4] = 'd'; map[10][5] = 'd'; map[10][6] = 'd'; map[10][7] = 'd'; map[10][8] = 'd'; map[10][9] = 'd'; map[10][10] = 'd'; map[10][11] = 'd';  map[10][12] = 'd'; map[10][13] = 'd'; map[10][14] = 'd'; map[10][15] = 'd';  map[10][16] = 'd';  map[10][17] = 'd';map[10][18] = 'e';map[10][19] = 'p';
					map[11][0] = 'p'; map[11][1] = 'd'; map[11][2] = 'd'; map[11][3] = 'd'; map[11][4] = 'd'; map[11][5] = 'd'; map[11][6] = 'd'; map[11][7] = 'd'; map[11][8] = 'd'; map[11][9] = 'd'; map[11][10] = 'd'; map[11][11] = 'd';  map[11][12] = 'd'; map[11][13] = 'd'; map[11][14] = 'd'; map[11][15] = 'd';  map[11][16] = 'd';  map[11][17] = 'e';map[11][18] = 'g';map[11][19] = 'p';
					map[12][0] = 'p'; map[12][1] = 'p'; map[12][2] = 'p'; map[12][3] = 'p'; map[12][4] = 'p'; map[12][5] = 'p'; map[12][6] = 'p'; map[12][7] = 'p'; map[12][8] = 'p'; map[12][9] = 'p'; map[12][10] = 'p'; map[12][11] = 'p';  map[12][12] = 'p'; map[12][13] = 'p'; map[12][14] = 'p'; map[12][15] = 'p';  map[12][16] = 'p';  map[12][17] = 'p';map[12][18] = 'p';map[12][19] = 'p';
					map[13][0] = 'p'; map[13][1] = 'p'; map[13][2] = 'p'; map[13][3] = 'p'; map[13][4] = 'p'; map[13][5] = 'p'; map[13][6] = 'p'; map[13][7] = 'p'; map[13][8] = 'p'; map[13][9] = 'p'; map[13][10] = 'p'; map[13][11] = 'p';  map[13][12] = 'p'; map[13][13] = 'p'; map[13][14] = 'p'; map[13][15] = 'p';  map[13][16] = 'p';  map[13][17] = 'p';map[13][18] = 'p';map[13][19] = 'p';
					this->_w = 20; this->_h = 14;
				break;
			}
		break;
	}
}

template <class al_b>
char Maps<al_b>::showBackground( void ){
	for(int y = 0;y<16;y++){
		for(int x=0;x<21;x++){
			al_draw_scaled_bitmap(this->_background, 37, 20, 59, 59, 45*x, 45*y, 45, 45, 0);
		}
	}
}