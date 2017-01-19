#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"
#include "Regular_hexagon.h"

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	Regular_hexagon foo {{200,200}, 50};
	foo.set_fill_color (Color::white);
	foo.set_color(Color::invisible);
	win.attach(foo);
	win.wait_for_button();
}
