namespace Graph_lib {
struct Box : Lines {
	Box(Point sp, int ww, int hh, int rr)
		:start_point{sp}, width{ww}, height{hh}, 
		diameter{2 * rr}, round_radius{rr} {
		add(Point{sp.x + rr, sp.y}, Point{sp.x + ww - rr, sp.y});
		add(Point{sp.x + rr, sp.y + hh}, Point{sp.x + ww - rr, sp.y + hh});
		add(Point{sp.x, sp.y +rr}, Point{sp.x, sp.y + hh - rr});
		add(Point{sp.x + ww, sp.y + rr}, Point{sp.x + ww, sp.y + hh - rr});
	}
	void draw_lines() const {
		Lines::draw_lines();
		fl_arc(start_point.x, start_point.y, 
				2 * round_radius, 2 * round_radius, 90, 180);
		fl_arc(start_point.x + width - diameter, start_point.y, 
				2 * round_radius, 2 * round_radius, 0, 90);
		fl_arc(start_point.x, start_point.y + height - diameter, 
				2 * round_radius, 2 * round_radius, 180, 270);
		fl_arc(start_point.x + width - diameter, 
				start_point.y + height - diameter,
				2 * round_radius, 2 * round_radius, 270, 360); 
	}


private:
	Point start_point;
	int round_radius;
	int diameter; // diameter of round corner
	int width;
	int height;
};
}

