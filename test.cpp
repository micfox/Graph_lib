#include "Simple_window.h"
#include "Graph.h"
#include "Striped_rectangle.h"
#include "Fct_reg.h"

double one(double) {return 1;}
double slope(double x) {return x+2;}

int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"test"};

	Fct_reg foo {one, -10, 10, {200,200}}; 
	win.attach(foo);	
	win.wait_for_button();

	foo.reset_fct(slope);
	//foo.reset_fct([](double x) {return x+2;});
	win.attach(foo);
	win.wait_for_button();
}
