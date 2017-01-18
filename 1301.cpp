#include "Graph.h"
#include "Arc.h"
#include "Simple_window.h"

int main()
{
	Simple_window win {Point{50,50}, 600, 400, "Exer 1201"};
	Ellipse ell {{100,100}, 150, 50};
	win.attach(ell);

	Arc arc_test {{200,200}, 150, 50, 210, 390};
	win.attach(arc_test);
	Arc arc_test2 {{200,200}, 50, 100, 180, 450};
	arc_test2.set_color(Color::red);
	win.attach(arc_test2);

	win.wait_for_button();
}
