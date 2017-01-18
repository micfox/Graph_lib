
namespace Graph_lib {
struct Box : Shape {
	Box(Point p, int width, int height, int radius){
		if(radius*2 > min(width,height))
			error("corner radius exceed line length");
		straight_line.add({p.x + radius,p.y},{p.x+width-radius,p.y}); //top
		straight_line.add({p.x + radius,p.y+height},{p.x+width-radius,p.y+height}); //bot
		straight_line.add({p.x, p.y+radius},{p.x,p.y+height-radius}); //left
		straight_line.add({p.x + width, p.y+radius},{p.x+width,p.y+height-radius}); //right
		round_corner.push_back(new Arc {{p.x + radius, p.y + radius}, radius, radius, 90, 180});
		round_corner.push_back(new Arc {{p.x + width - radius, p.y + radius}, radius, radius, 0, 90});
		round_corner.push_back(new Arc {{p.x + radius, p.y + height - radius}, radius, radius, 180, 270});
		round_corner.push_back(new Arc {{p.x + width - radius, p.y + height - radius}, radius, radius, 270, 360});
//		arc_test = new Arc {{p.x + width/2, p.y + height/2}, radius, radius, 0, 360};

		
	}
	void draw_lines() const {
			straight_line.draw_lines();	
		arc_test.draw_lines();
		for(int a = 0; a < round_corner.size(); ++a)
			round_corner[a].draw_lines();
	}
/*
	void set_color(Color col) {
		straight_line.set_color(col);
		for(int i; i < round_corner.size(); ++i)
			round_corner[i].set_color(col);
	}
*/
private:
	Lines straight_line;
	Arc arc_test {{100, 100}, 80, 80, 0, 360};
	Vector_ref<Arc> round_corner;
};

}
