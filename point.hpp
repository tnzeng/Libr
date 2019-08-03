#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point{
	public:
		double x;
		double y;

		Point (){
		}

		Point (double x_, double y_){
			x = x_;
			y = y_;
		}

		void print(){
			std::cout << "POINT: " << x << ", " << y << std::endl;
		}
};

Point create_point(double x, double y){
	Point ans (x, y);
	return ans;
}

Point add_point(Point a, Point b){
	return create_point(a.x + b.x, a.y + b.y);
}

Point scale_point(double s, Point a){
	return create_point(s * a.x, s * a.y);
}

#endif
