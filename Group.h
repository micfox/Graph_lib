namespace Graph_lib {
struct Group : Shape {
//	Group() {}
/*
//dunno how to use initlist
	Group(initializer_list<Shape&> lst) {
		for (auto s : lst)
			shapes.push_back(s);
	}
*/
	//override
	void draw_lines() const {
		for (int i=0; i < shapes.size(); ++i) 
			shapes[i].draw();
	}

	void add(Shape& s) {shapes.push_back(s);}
	void move(int x, int y) {
		for (int i=0; i < shapes.size(); ++i)
			shapes[i].move(x, y);
	}	
	void set_color(Color c) {
		cout << "calling Group::set_color(c)" << '\n';
		for (int i=0; i < shapes.size(); ++i)
			shapes[i].set_color(c);
	}
	int count() {return shapes.size();}
	Shape& get(int i) {
		if (i < 0 || i > shapes.size())
			error("out of bound");
		return shapes[i];
	}
private:
	void set_point();
	Vector_ref<Shape> shapes;
};
}
