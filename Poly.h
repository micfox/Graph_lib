#include "Graph.h"

namespace Graph_lib {

struct Poly : Polygon {
	Poly () { }
	Poly(initializer_list<Point> lst) { //we want Poly {{x,y}, {a,b}, {c,d},...,{w,z}} construct a Polygon if all the points
	// in lst satisfy a Polygon definition
	// ?? how to use initializer_list
		for (int i=0; i < lst.size(); ++i) {
			check_points_sequence_intersect();
		Polygon::Polygon(lst);
	}	

};

}
