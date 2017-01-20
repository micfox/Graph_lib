#include "Simple_window.h"
#include "Graph.h"
#include "Regular_hexagon.h"
#include <cmath>

#define PI 3.14159265

Point tl {100,100};
Simple_window win {tl,600,400,"test"};

Point p {0,0};
static int r = 50;
static int y_shift = static_cast<int>( round( 2 * r * sin (60 * PI /180))); // short radius
static int x_shift = static_cast<int>( round( 3 * r / 2 ));
bool col_odd = true;

void get_next_point()
//get position for next hexagon
{
	p.y += y_shift;
	if ( p.y > win.y_max() + y_shift ) {
		p.x += x_shift;
		if (col_odd) { 
			//if odd col, y add a shift, if even col, y = 0
			p.y = y_shift / -2;
		} else {
			p.y = 0;
		}
		col_odd = !col_odd;
	}  
}

int main()
{
	using namespace Graph_lib;

	Vector_ref<Regular_hexagon> foo;
	//how many Regs we will display?
	while( p.x < win.x_max() + r ) {
		foo.push_back( new Regular_hexagon {p, r} );	
		get_next_point();
	}

	for (int i=0; i < foo.size(); ++i)
		win.attach(foo[i]);
	win.wait_for_button();
}
