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

	Point p {radius, 0};
	Mark m {p, 'o'};
	for (int i=0; true; i+=10) {
		win.wait_for_button();
		m.set_point(0, Point {
			center.x + radius * cos ((i+10) * PI / 180 ),
			center.y - radius * sin ((i+10) * PI / 180)
		});		
	}

}
