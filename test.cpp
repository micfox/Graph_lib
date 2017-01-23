#include "Simple_window.h"
#include "Graph.h"
#include "Poly.h"

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	Poly foo {{200,200}, {133,392}, {362,96}};
	foo.set_fill_color (Color::white);
	foo.set_color(Color::invisible);
	win.attach(foo);
	win.wait_for_button();
}
