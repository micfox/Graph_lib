#include "Graph.h"

namespace Graph_lib {

struct Arc : Ellipse{
	Arc(Point center, int ww, int hh, 
		int sr,
		int er)	 //use fl_arc(x,y,+x,+y,?,?) to draw
		:Ellipse{center, ww, hh}, start_radius{ sr }, end_radius{ er } {
	}
	void draw_lines() const;
private:
	int start_radius;
	int end_radius;
};

void Arc::draw_lines() const
{
    if (color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x,point(0).y,2*major(),2*minor(),start_radius,end_radius);
    }
}

}
