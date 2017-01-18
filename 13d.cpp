#include "Graph.h"
#include "Simple_window.h"

int main()
{
	Simple_window win {Point{50,50}, 1000, 800, "Cp13 drill"};
	
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x=x_grid; x <= x_size; x+=x_grid)
		grid.add(Point{x,0}, Point{x,y_size});
	for (int y = y_grid; y<= y_size; y += y_grid)
		grid.add(Point{0,y}, Point{x_size,y});
//	win.attach(grid);

	Vector_ref<Rectangle> rect;
	for (int i = 0; i < x_size; i += x_grid) {
		rect.push_back(new Rectangle{ Point{i,i}, 
			Point{i+x_grid, i + x_grid} });
		rect[rect.size() - 1].set_fill_color(Color::red);
		rect[rect.size() - 1].set_color(Color::invisible);
		win.attach(rect[rect.size() - 1]);
	}
	win.attach(grid);

	Image img {Point{0,200}, "gum.jpg"};
	img.set_mask(Point{0,0}, 200, 200);
	win.attach(img);
	Image img2 {Point{200,400}, "gum.jpg"};
	img2.set_mask(Point{50,50}, 200, 200);
	win.attach(img2);
	Image img3 {Point{600,0}, "gum.jpg"};
	img3.set_mask(Point{10,10}, 200, 200);
	win.attach(img3);
	
	Image img_move {Point{0,0}, "img2.jpeg"};
	img_move.set_mask(Point{0,0}, 100, 100);
	win.attach(img_move);

	win.wait_for_button();

	//move from line to line
	for (int y = 0; y < y_size; y += y_grid) {
		for ( int x = x_grid; x < x_size; x += x_grid) {
			img_move.move(x_grid, 0);
			win.wait_for_button();
		}
		img_move.move(x_grid - x_size, y_grid);
		win.wait_for_button();
	}

}
