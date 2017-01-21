#include <iostream>
#include <gtkmm.h>

using namespace std;
using namespace Gtk;

void on_button_click();
int main(int argc, char *argv[]){
	Main kit(argc, argv);
	
	Window window;
	Button button("Click me please");

	window.set_default_size(640,480);
	window.set_position(WIN_POS_CENTER);
	
	button.signal_clicked().connect(
		sigc::ptr_fun(&on_button_click)
	);
	button.show();
	window.add(button);

	kit.run(window);
	
	return 0;
}
void on_button_click(){
	cout << "Clickkkk" << endl;
}