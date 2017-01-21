protocolo::protocolo(void){
	for(int i=0; i<256; i++) alf.push_back(NumberToString(i));
	alf.push_back(",");
	for(char i='a'; i<='z'; i++) alf.push_back(CharToString(i));
	alf.push_back(" ");
	for(char i='A'; i<='Z'; i++) alf.push_back(CharToString(i));
	alf.push_back("-");
	alf.push_back(".");

    alto = 256; //256
    ancho = 256; //256
}
int protocolo::getAlfSize(void){
    return alf.size();
}
Mat protocolo::getFrame(void){
    return frame;
}

void protocolo::takePhoto(void){
	VideoCapture cap;
    cap.open(0);
    if( !cap.isOpened() ){
        cout << "Could not initialize capturing...\n";
    }else{
        Mat frame(alto,ancho,CV_8UC3,Scalar(0,0,0));
        char key;
        bool t=true;
        while (t && cap.grab()) {
            cap.retrieve(frame);
            imshow("BGR image", frame);
            if (key == 115){
                imwrite("photo.png", frame);
                t = false;
                destroyWindow("BGR image");
            }
            key = waitKey(20);
        }

        ZZ sum = (ZZ)1;
        Vec2b numeric;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 1; j++){
                numeric = frame.at<Vec2b>(i, j);
                if(numeric[0] != 0 and numeric[1] != 0){
                    sum *= numeric[0];
                    sum *= numeric[1];
                }
                if((i == (ZZ)0 and j == (ZZ)0 ) or (i == (ZZ)1 and j == (ZZ)0) or (i == (ZZ)2 and j == (ZZ)0) ){
                    seedCamera.push_back(sum);
                    sum = (ZZ)1;
                }
            }
        }
        this->frame = frame.clone();
    }
}

vector<ZZ> protocolo::getSeed(void){ return seedCamera; }

string protocolo::_ccesar(void){
    c = new cesar(K);
    int initi, initj;
    if(frame.rows > alto and frame.cols > ancho){
        initi = (frame.rows/2) - (alto/2);
        initj = (frame.cols/2) - (ancho/2);
    }else{
        initi = 0;
        initj = 0;
    }

    for(int i = initi; i< (initi+alto); i++){
        for(int j = initj; j< (initj+ancho); j++){
            Vec3b bgrPixel = frame.at<Vec3b>(i, j);
            cout << "pixel:"<<bgrPixel << endl;
            ec += AddLeftZero(c->_c(bgrPixel[0]), 3);
            ec += AddLeftZero(c->_c(bgrPixel[1]), 3);
            ec += AddLeftZero(c->_c(bgrPixel[2]), 3);
        }
    }
    return ec;    
}
string protocolo::_dcesar(string msn){
    string letter, new_msn, cipher;
    c = new cesar(K);

    //ZZ num = mod(msn.size(),(ZZ)3);
    
    int size = 3, i = 0 ,j = 0;
    while(msn.size() > 0  and i <= 3*alto){
        if(msn.size()-1 > size){
            cipher = msn.substr(0, size);
            msn = msn.substr(size, msn.size()-1);
        }else{
            cipher = msn;
            msn.clear();
        }

        //cout << cipher << endl;
        letter = c->_d(StringtoZZ(cipher));    
        //cout << letter << endl;
        new_msn += AddLeftZero(letter, size);
        
        ++j;
        if(j >= ancho){
            j = 0;
            i++;
        }  
    }
    cout << new_msn << endl;
        
    return new_msn;
}
void protocolo::showPhoto(void){
    Mat s(alto,ancho,CV_8UC3,Scalar(00,00,00));     
    string msn = ec, cipher;
    int c;
    int i=0, j=0, size = 9;
    //cout << "showphoto "<< msn << endl;
    
    while(msn.size() > 0 and i <= alto){
        if(msn.size()-1 > size){
            cipher = msn.substr(0, size);
            msn = msn.substr(size, msn.size()-1);
        }else{
            cipher = msn;
            msn.clear();
        }
        //cout << "----------"<<endl;
        //cout << "cipher "<<cipher<<endl;
        Vec3b bgrPixel = s.at<Vec3b>(i, j);
        conv(c, StringtoZZ(cipher.substr(0,3)) );
        bgrPixel[0] = c;
        conv(c, StringtoZZ(cipher.substr(3,3)) );
        bgrPixel[1] = c;
        conv(c, StringtoZZ(cipher.substr(6,3)) );
        bgrPixel[2] = c;
        //cout << bgrPixel << endl;
        //cout  <<" asd: "<<(int)bgrPixel[0]<<"-"<<(int)bgrPixel[1]<<"-"<<(int)bgrPixel[2]<<endl;
        s.at<Vec3b>(Point(j,i)) = bgrPixel;
            
        ++j;
        if(j >= ancho){
            j = 0;
            i++;
        }    
    }
    imwrite("pho.png", s);
    
    cout << "Cargando..." << endl;
    Mat src = imread("pho.png", CV_LOAD_IMAGE_UNCHANGED);
    if (src.empty())    cout << "Error : Image cannot be loaded..!!" << endl;
    namedWindow("window", WINDOW_NORMAL); //window name 
    resizeWindow("window", ancho, alto); //window name 
    imshow("window", src);
    waitKey(0);
}

vector<string> protocolo::proc(string msn){
    vector<string> v;
    int n = 0;
    for(int i = 0; i<msn.size() and n == 0;i++)
        if(msn[i] == '#') n = i;
    v.push_back(msn.substr(0,n));
    v.push_back(msn.substr(n+1,msn.size()-1));
    return v;
}


string protocolo::ZZtoString(const ZZ num){
    stringstream buffer;
    buffer << num;
    return buffer.str();
}
ZZ protocolo::StringtoZZ(string num){
    if(num != ""){
        ZZ b(INIT_VAL, num.c_str());
        return b;
    }else
        return ZZ(0);
}
string protocolo::AddRightZero(string num, int n){
    int count = n-num.size();
    for (int i = 0; i < count; ++i){
        num += "0";
    }
    return num;
}
string protocolo::AddLeftZero(string num, int n){
    int count = n-num.size();
    for (int i = 0; i < count; ++i)
        num.insert(0,"0");
    return num;
}

void protocolo::setEC(string msn){ ec = msn; }
string protocolo::getEC(void){ return ec; }
void protocolo::setK(ZZ K){ this->K = K; }
