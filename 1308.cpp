#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"
#include <cmath>

#define PI 3.14159265
Point p {0,0};
int r = 50;

void get_next_point()
//get position for next hexagon
{
	int d = static_cast<int> (rount (2 * r * sin (60 * PI /180)));
	p.y += d;
	if ( (p.y - r) > win.y_max() ) {
		p.x += d;
		p.y = //if odd col, y add a shift, if even col, y = 0
	}  
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
