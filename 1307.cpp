#include "Graph.h"
#include "Simple_window.h"

Simple_window win{{50,50}, 800, 600, "Color chart"};
int block_width = 45;
int block_height = 20;
Point sp {5,5}; //start position
Point cp {0,0}; //current position to place color retangle
Point cp_text;
static int text_shift = 1;
static int text_width = 42;
int down_increase = 22;
int right_increase = block_width + 30;
static int text_up_shift = 5;

int main()
{


	void get_next_position();
	string get_hex(int);

	Vector_ref<Rectangle> color_block;
	Vector_ref<Text> side_text;
	int color_value;
//we want to draw colored rectangle from col to col
//we increse color value by 0x33 of each RGB value
	for (int i = 0; i <= 0xff; i += 0x33)
		for (int j = 0; j <= 0xff; j += 0x33)
			for (int k = 0; k <= 0xff; k += 0x33) {
				get_next_position();
				color_value = i * 0x10000 + j * 0x100 + k;
				color_block.push_back(new Rectangle {cp, block_width, block_height});
				color_block[color_block.size() - 1].set_fill_color( Color(i, j, k) );
				string t = get_hex(color_value);
				side_text.push_back(new Text {cp_text, t});
				side_text[ side_text.size() - 1 ].set_font( Graph_lib::Font::courier );
				side_text[ side_text.size() - 1 ].set_font_size( 12 );
			}

	cout << "color.size() :" << color_block.size() << '\n';

	for (int i = 0; i < color_block.size(); ++i) 
		win.attach(color_block[i]);
	for (int i = 0; i < side_text.size(); ++i) 
		win.attach(side_text[i]);

	win.wait_for_button();		

}

void get_next_position() 
{
		if ( cp == Point{0,0} )
			cp += sp;	
		else {
			cp.y += down_increase;
			if ( cp.y > win.y_max() - block_height ) {
				cp.x += block_width + text_width + 2 * text_shift;
				cp.y = sp.y;
			}
		}
		cp_text.x = cp.x + block_width + text_shift;
		cp_text.y = cp.y + block_height - text_up_shift; 
}

string get_hex(int i)//we want get_hex(15) return "0xf"
{
	ostringstream os;
	//showbase or not
	os << hex << uppercase << setfill('0') << setw(6) << hex << i;
	return os.str();
}

