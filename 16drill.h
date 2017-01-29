#include "GUI.h"
//#include "Window.h"

namespace Graph_lib {

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu style_menu;
	Button style_menu_button;

	void next();
	void quit();
	void change(Color c) {lines.set_color(c);}
	void change_style(Line_style ls) {lines.set_style(ls);}
	void red_pressed() {change(Color::red);hide_menu();}
	void blue_pressed() {change(Color::blue);hide_menu();}
	void black_pressed() {change(Color::black);hide_menu();}
	void menu_pressed() {
		menu_button.hide();
		color_menu.show();
	}
	void hide_menu() {
		color_menu.hide();
		menu_button.show();
	}
	void style_menu_pressed() {
		style_menu_button.hide();
		style_menu.show();
	}
	void hide_style_menu() {
		style_menu.hide();
		style_menu_button.show();
	}
	void dash_pressed() {change_style(Line_style::dash);hide_style_menu();}
	void dot_pressed() {change_style(Line_style::dot);hide_style_menu();}
	void solid_pressed() {change_style(Line_style::solid);hide_style_menu();}
};


}
