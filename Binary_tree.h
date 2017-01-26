namespace Graph_lib {
struct Binary_tree : Shape {
	Binary_tree(Point sp, int level)
	:lvl{level} {
		add(sp);
		int last_size = 0;
		int added_number = 0;
		for (int i=1; i <= lvl; ++i) {
			//draw lines and sub nodes for all nodes in np
		/*  i = 1, add 1 point 
			i = 2, add 2
			i = 3, add 4
			i = 4, add 8
			i = 5, add 16
*/
			last_size = np.size();

			if (np.size() == 0) {
				np.push_back(sp);
				added_number = 1;
			} else {
				//calculate new points from upper level points
				int range = added_number;
				added_number = 0;	//reset count
				for (int j = last_size - range; j < last_size; ++j) {
					//	
					np.push_back(Point{np[j].x - xshift, np[j].y + yshift});
					line_shapes.add(np[j], np[np.size() - 1]);
					np.push_back(Point{np[j].x + xshift, np[j].y + yshift});	
					line_shapes.add(np[j], np[np.size() - 1]);
					added_number += 2;
				}
			}
			xshift /= 2;
		}

	}

	virtual void draw_lines() const {
		line_shapes.draw();
		for (Point p : np) {
			Circle(p, 5).draw();
		}
	}
private:
	vector<Point> np;	//keep all nodes positions
	Lines line_shapes;
	int xshift = 256;
	const int yshift = 30;
	int lvl = 0;
};
}
