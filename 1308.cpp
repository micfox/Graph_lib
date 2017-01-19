#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"

Point p {0,0};
int r = 50;

void get_next_point()
//get position for next hexagon
{
	p.y += 2 * sin60 * r;
}

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	Point p {0,0};
	int r = 50;

	Regular_hexagon foo {{200,200}, 50};
	foo.set_fill_color (Color::white);
	win.attach(foo);
	win.wait_for_button();
}
