#include "Graph.h"

namespace Graph_lib{

struct Arc : Ellipse {
	Arc(Point center, int w, int h, int sr, int er)
	:Ellipse{center, w, h}, start_radius{sr}, end_radius{er} {}

	void draw_lines() const {
	if (color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,2*major(),2*minor(),start_radius,end_radius);
    }
}

private:
	int start_radius;
	int end_radius;
};
		
}
