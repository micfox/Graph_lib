#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"
#include "Regular_hexagon.h"

void add_axis_lines (Lines&, Point, int, int);

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};
	
	Ellipse foo {{300,200}, 150, 100};
	Lines axis;
	add_axis_lines (axis, {300,200}, 400, 300);
	Mark m {{300,200}, 'x'};

	win.attach (axis);
	win.attach(foo);
	win.attach(m);
	win.wait_for_button();
}

void add_axis_lines (Lines& l, Point p, int x_len, int y_len)
{
	l.add( Point {p.x - x_len / 2, p.y}, Point {p.x + x_len / 2, p.y} );
	l.add( Point {p.x, p.y - y_len / 2}, Point {p.x, p.y + y_len / 2} );
}	
