
namespace Graph_lib {
struct Smiley : Closed_polyline {
	Smiley(initializer_list<Point> lst) :Closed_polyline{lst}, c1{{100,100}, 20} {}	
//	using Closed_polyline::Closed_polyline;
	void draw_lines() const {
		Closed_polyline::draw_lines();
		//calculate 3 position
		//then draw 3 circles
		c1.draw_lines();	
	}
private:
//	Circle c1 {{center().x - 20, center().y - 20}, 20};
//	Circle c1 {{100,100}, 20};
	Circle c1;
	int i = 0;
	int b;
};
}
