#include <cmath>
#define PI 3.14159265

namespace Graph_lib {

struct Regular_hexagon : Polygon {
	Regular_hexagon(Point center, int radius) {
		add_six_points(center, radius);
	}

private:
	void add_six_points(Point center, int radius) {
		for (int i = 0; i < 360; i += 60)
			add({center.x + static_cast<int>( round( radius * cos(i * PI / 180.0))),
				center.y + static_cast<int>( round( radius * sin(i * PI / 180.0)))});
	}
};
}
