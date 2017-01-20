#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

#define PI 3.14159265
int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	int radius = 80;
	Point center {300, 200};
	Circle c {center, radius};
	win.attach(c);

	Point p {center.x + radius, center.y};
	Mark m {p, 'o'};
	win.attach(m);

	for (int i=0; true; i+=10) {
		win.wait_for_button();
		m.set_mark_point(Point {
			center.x + (int) round (radius * cos ((i+10) * PI / 180)),
			center.y - (int) round (radius * sin ((i+10) * PI / 180))
		});		
		win.attach(m);
	}

	win.wait_for_button();

}
