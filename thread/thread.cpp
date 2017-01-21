//THREAD BASICO
#include <iostream>
#include <thread>
using namespace std;

static const int n_thread = 10;

void fun(int x){
	cout << "Hello from thread" << x << endl;
}

int main(){
	thread t[n_thread];
	for(int i = 0;i<n_thread;i++)
		t[i] = thread(fun,i);
	cout << "Main" << endl;

	for(int i = 0;i<n_thread;i++)
		t[i].join();
	
	thread th(fun,1);
	cout << "Hello world"<<endl;
	th.join();

	return 0;
}