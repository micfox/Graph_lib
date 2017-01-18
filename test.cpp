#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"
#include "Box.h"

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	Box foo {{50,50}, 200, 200, 50};
	foo.set_color(Color::red);
	win.attach(foo);
	win.wait_for_button();
}
