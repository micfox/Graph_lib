#include "Graph.h"
#include "Simple_window.h"

int main() {
	Point tl {50,50};
	constexpr int xmax = 600;
	constexpr int ymax = 600;
	constexpr int x_orig = xmax / 2;
	constexpr int y_orig = ymax / 2;
	constexpr int xlength = 400;
	constexpr int ylength = 400;
	constexpr int scale_px = 20;

	Simple_window win {tl, xmax, ymax, "Function graphs"};
	Axis x_axis {Axis::x, Point{(xmax - xlength) / 2, y_orig},
		xlength, xlength / scale_px, "1 == 20 pixels"};
	Axis y_axis {Axis::y, Point{x_orig, (ymax - ylength) / 2 + ylength}, //y axis draw bottom up
		ylength, ylength / scale_px, "1 == 20 pixels"};

	x_axis.set_color(Color::red);
	y_axis.set_color(Color::red);

	win.attach(x_axis);
	win.attach(y_axis);
	
	Function s {[](double){return 1.0;}, -10, 11, {300, 300}, 400, 20, 20};
	Function s2 {[](double x){return x / 2.0;}, -10, 11, {300, 300}, 400, 20, 20};
	Function s3 {[](double x){return x * x;}, -10, 11, {300, 300}, 400, 20, 20};
	Function s4 {[](double x){return cos(x);}, -10, 11, {300, 300}, 400, 20, 20};
	Function s5 {[](double x){return x / 2.0 + cos(x);}, -10, 11, {300, 300}, 400, 20, 20};
	s4.set_color(Color::blue);
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	
	Text ts2 {Point{x_orig + (-10)*scale_px, y_orig - (-10)/2*scale_px - 10}, "x/2"};
	win.attach(ts2);
//	gui_main();
	win.wait_for_button();
}
