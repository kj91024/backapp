/*
--------------------------- EJEMPLO 1
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
}*/


/*
--------------------------- EJEMPLO 2
#include <iostream>
#include <thread>

void foo() { std::cout << "foo()\n"; }
void bar() { std::cout << "bar()\n"; }

int main()
{
	std::thread t([]{
		        foo();
			bar();						 
	                });
	t.join();
	return 0;
}*/


/*
--------------------------- EJEMPLO 3
#include <iostream>
#include <thread>

using namespace std;

void foo(int i) { cout << "foo() i = " << i << endl; }

struct task_struct
{
	int& i;

	task_struct(int& ii):i(ii){ 
		cout << "task_struct constructor i = " << i << endl;
	}

	void operator()()
	{
		for(unsigned j = 0; j < 10; ++j)
		{
			cout << j << ": foo()\n";
			foo(i);
		}
	}
};

void A_function_creating_a_thread_within()
{
	int state = 99;
	task_struct task(state);

	cout << "Launching a thread\n";
	std::thread t(task);

	cout << "detaching the thread\n";
        // do not wait for the thread to finish
	t.detach();
}

int main()
{
	A_function_creating_a_thread_within();
	cout << "END OF PROGRAM\n";
	return 0;
}*/



/*
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;

condition_variable cond_var;
mutex m;

int main() {
    int value = 100;
    bool notified = false;
    thread reporter([&]() {
        
        //unique_lock<mutex> lock(m);
        //while (!notified) {
        //    cond_var.wait(lock);
        //}
        
        cout << "The value is " << value << endl;
    });

    thread assigner([&]() {
        value = 20;
        
        //notified = true;
        //cond_var.notify_one();
        
    });

    reporter.join();
    assigner.join();
    return 0;
}*/


/*#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <queue>
using namespace std;

int main() {
    int c = 0;
    bool done = false;
    queue<int> goods;

    thread producer([&]() {
        for (int i = 0; i < 500; ++i) {
            goods.push(i);
            c++;
        }

        done = true;
    });

    thread consumer([&]() {
        while (!done) {
            while (!goods.empty()) {
                goods.pop();
                c--;
            }
        }
    });

    producer.join();
    consumer.join();
    cout << "Net: " << c << endl;
}*/