#ifndef __CARTESIAN_HISTOGRAM_HPP__
#define __CARTESIAN_HISTOGRAM_HPP__

#include<algorithm>
#include<cmath>
#include<vector>

#include "color.hpp"

class Cartesian_Histogram{
	private:
		double x_lower_bound, y_lower_bound;
		double x_upper_bound, y_upper_bound;
		double pixel_size;
		int image_width, image_height;

		std::vector<std::vector<int>> histogram;
		std::vector<std::vector<Color>> color_data;

		Color (*color_map) (int, int, Point);
	public:
		Cartesian_Histogram(){
		}

		Cartesian_Histogram(double xl, double yl, double xu, double yu, double ps, int iw, int ih){
			x_lower_bound = xl;
			y_lower_bound = yl;
			x_upper_bound = xu;
			y_upper_bound = yu;
			pixel_size = ps;
			image_width = iw;
			image_height = ih;
			
			std::vector<std::vector<int>> hist;
			std::vector<std::vector<Color>> color;
			Color black = create_color(0, 0, 0);
			for (int i = 0; i < image_height; i++){
				std::vector<int> row (image_width, 0);
				std::vector<Color> row2 (image_width, black);
				hist.push_back(row);
				color.push_back(row2);
			}
			histogram = hist;
			color_data = color;
		}

		void set_color_map(Color (*map)(int, int, Point)){
			color_map = map;
		}

		std::pair<int, int> point_to_pixel(Point p){
			int j = (int) floor((p.x - x_lower_bound) / pixel_size);
			int i = (int) floor((p.y - y_lower_bound) / pixel_size);
			std::pair<int, int> indices (i, j);
			return indices;
		}

		Point pixel_to_point(int i, int j){
			return create_point(x_lower_bound + j * pixel_size, y_lower_bound + i * pixel_size);
		}

		void increment_point(Point p){
			std::pair<int, int> indices = point_to_pixel(p);
			if (indices.first >= 0 && indices.second >= 0 && indices.first < (int) histogram.size() && indices.second < (int) histogram[indices.first].size())
				histogram[indices.first][indices.second]++;
		}

		int find_histogram_max(){
			int max = 0;
			for (unsigned int i = 0; i < histogram.size(); i++)
				for (unsigned int j = 0; j < histogram[i].size(); j++)
					if (histogram[i][j] > max)
						max = histogram[i][j];
			return max;
		}

		void histogram_to_color_data(int max){
			for (unsigned int i = 0; i < histogram.size(); i++)
				for (unsigned int j = 0; j < histogram[i].size(); j++)
					color_data[i][j] = color_map(histogram[i][j], max, pixel_to_point(i, j));
		}

		std::vector<std::vector<Color>> get_color_data(){
			return color_data;
		}
};

#endif
