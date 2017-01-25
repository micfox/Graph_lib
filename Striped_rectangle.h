namespace Graph_lib {
struct Striped_rectangle : Rectangle {
	using Rectangle::Rectangle;
	void draw_lines() const {
		draw_hr_lines();
		//prvt_draw();
		if (color().visibility()) {
			fl_color(color().as_int());
			fl_rect(point(0).x, point(0).y, width(), height());
		}
	}
private:
	void prvt_draw() const {
		fl_line(50, 50, 100, 100);
	}
	void draw_hr_lines() const{
		if (fill_color().visibility()) {
			cout << "fill color is " << fill_color().as_int() << '\n';
			fl_color(fill_color().as_int());
			for (int i = point(0).y; i < point(0).y + height(); i+=2) {
				//Line_style ls {0};
				//fl_line_style(ls.style(), ls.width());
				fl_line(point(0).x, i, point(0).x + width() - 1, i);
			}
			fl_color(color().as_int());
		}
	} 
};
}
