#include "io2d.h"
#include "xio2dhelpers.h"
#include "xcairoenumhelpers.h"

using namespace std;
using namespace std::experimental::io2d;

font_options::native_handle_type font_options::native_handle() const {
	return _Font_options.get();
}

font_options::font_options(font_options&& other) {
	_Font_options = move(other._Font_options);
	other._Font_options = nullptr;
}

font_options& font_options::operator=(font_options&& other) {
	if (this != &other) {
		_Font_options = move(other._Font_options);
		other._Font_options = nullptr;
	}
	return *this;
}

font_options::font_options(::std::experimental::io2d::antialias a, ::std::experimental::io2d::subpixel_order so)
: _Font_options(shared_ptr<cairo_font_options_t>(cairo_font_options_create(), &cairo_font_options_destroy)) {
	_Throw_if_failed_cairo_status_t(cairo_font_options_status(_Font_options.get()));
	cairo_font_options_set_antialias(_Font_options.get(), _Antialias_to_cairo_antialias_t(a));
	_Throw_if_failed_cairo_status_t(cairo_font_options_status(_Font_options.get()));
	cairo_font_options_set_subpixel_order(_Font_options.get(), _Subpixel_order_to_cairo_subpixel_order_t(so));
	_Throw_if_failed_cairo_status_t(cairo_font_options_status(_Font_options.get()));
	cairo_font_options_set_hint_style(_Font_options.get(), CAIRO_HINT_STYLE_DEFAULT);
	_Throw_if_failed_cairo_status_t(cairo_font_options_status(_Font_options.get()));
	cairo_font_options_set_hint_metrics(_Font_options.get(), CAIRO_HINT_METRICS_DEFAULT);
	_Throw_if_failed_cairo_status_t(cairo_font_options_status(_Font_options.get()));
}

font_options::font_options(font_options::native_handle_type nh) {
	_Font_options = shared_ptr<cairo_font_options_t>(nh, &cairo_font_options_destroy);
}

antialias font_options::antialias() const {
	return _Cairo_antialias_t_to_antialias(cairo_font_options_get_antialias(_Font_options.get()));
}

subpixel_order font_options::subpixel_order() const {
	return _Cairo_subpixel_order_t_to_subpixel_order(cairo_font_options_get_subpixel_order(_Font_options.get()));
}
