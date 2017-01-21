#include <iostream>
#include <string>
#include <curl/curl.h>
#include "src/function.cpp"

using namespace std;

int main(void){
    /** carrieBOT **/
    string txt = getPage("http://www.identi.li/");
    

    cout << txt << endl;
    return 0;
}