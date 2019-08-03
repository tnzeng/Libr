#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include<cmath>

class Color{
	public:
		int r;
		int g;
		int b;

		Color (){}

		Color(int r_, int g_, int b_){
			r = r_;
			if (r > 255)
				r = 255;
			g = g_;
			if (g > 255)
				g = 255;
			b = b_;
			if (b > 255)
				b = 255;
		}

		Color(double r_, double g_, double b_){
			r = (int) round(r_);
			if (r > 255)
				r = 255;
			g = (int) round(g_);
			if (g > 255)
				g = 255;
			b = (int) round(b_);
			if (b > 255)
				b = 255;
		}
};

Color create_color(double r, double g, double b){
	Color ans (r, g, b);
	return ans;
}

Color scale_color(Color c, double s){
	Color ans (c.r * s, c.g * s, c.b * s);
	return ans;
}

Color add_color(Color c1, Color c2){
	Color ans (c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
	return ans;
}

#endif
