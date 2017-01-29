#include "16drill.h"

int main()

try {
	using namespace Graph_lib;
	Lines_window win {Point{100, 100}, 600, 400, "lines"};
	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "Some exception\n";
	return 2;
}
