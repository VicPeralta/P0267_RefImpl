#include "io2d.h"
#include "sample_draw.h"
#include <chrono>
#include <assert.h>

using namespace std;
using namespace std::chrono;
using namespace std::experimental::io2d;

int main() {
	assert(steady_clock::is_steady);
	auto ds = make_display_surface(800, 600, format::argb32);
	sample_draw sd;
	ds.draw_fn(sd);
	//ds.draw_fn([](display_surface& sfc) {
	//	sfc.paint(rgba_color::cornflower_blue);
	//	sfc.set_font_size(48.0);
	//	sfc.show_text("Hello ISO C++!", { 50.0, 50.0 }, rgba_color::white);
	//});
	return ds.join();
}

