#include "Simple_window.h"
#include "Graph.h"

int main()
//draw Olympic five rings
{
          using namespace Graph_lib;

          Point tl {50,50};

          Simple_window win {tl,600,400,"Canvas"};

	Circle c1 {Point(100,100),50};
	Circle c2 {Point(210,100),50};
	Circle c3 {Point(320,100),50};
	Circle c4 {Point(155,150),50};
	Circle c5 {Point(265,150),50};

	int line_width = 8;
	c1.set_style(Line_style(Line_style::solid,line_width));
	c2.set_style(Line_style(Line_style::solid,line_width));
	c3.set_style(Line_style(Line_style::solid,line_width));
	c4.set_style(Line_style(Line_style::solid,line_width));
	c5.set_style(Line_style(Line_style::solid,line_width));

	c1.set_color(Color::blue);
	c2.set_color(Color::black);
	c3.set_color(Color::red);
	c4.set_color(Color::yellow);
	c5.set_color(Color::green);
	
	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

	

          win.wait_for_button();
}
