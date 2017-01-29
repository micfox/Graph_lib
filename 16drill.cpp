#include "16drill.h"

namespace Graph_lib {

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy, w, h, title},
	next_button{Point{x_max() - 150, 0}, 70, 20, "Next point",
		[](Address, Address pw){reference_to<Lines_window>(pw).next();}},
	quit_button{Point{x_max() - 70, 0}, 70, 20, "Quit", 
		[](Address, Address pw){reference_to<Lines_window>(pw).quit();}},
	next_x{Point{x_max() - 310, 0}, 50, 20, "next x:"},
	next_y{Point{x_max() - 210, 0}, 50, 20, "next y:"},
	xy_out{Point{100, 0}, 100, 20, "current (x,y):"},
	color_menu{Point{x_max() - 70, 40}, 70, 20, Menu::vertical, "color"},
	menu_button{Point{x_max() - 80, 30}, 80, 20, "color menu",
		[](Address, Address pw){reference_to<Lines_window>(pw).menu_pressed();}},
	style_menu{Point{x_max() - 150, 40}, 70, 20, Menu::vertical, "style"}, 
	style_menu_button{Point{x_max() - 160, 30}, 80, 20, "style menu",
		[](Address, Address pw){reference_to<Lines_window>(pw).style_menu_pressed();}}

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	color_menu.attach(new Button{Point{0,0}, 0, 0, "red", 
		[](Address, Address pw){reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0}, 0, 0, "blue", 
		[](Address, Address pw){reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0}, 0, 0, "black", 
		[](Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}});
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);
	style_menu.attach(new Button{Point{0,0}, 0, 0, "dash",
		[](Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}}),
	style_menu.attach(new Button{Point{0,0}, 0, 0, "dot",
		[](Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}}),
	style_menu.attach(new Button{Point{0,0}, 0, 0, "solid",
		[](Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}}),
	attach(style_menu);
	style_menu.hide();
	attach(style_menu_button);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x, y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}
}
