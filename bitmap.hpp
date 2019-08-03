#ifndef __BITMAP_HPP__
#define __BITMAP_HPP__

#include<string>
#include<vector>
#include<fstream>

#include "bitmap_header.hpp"
#include "color.hpp"
#include "point.hpp"

class Bitmap{
	private:
		int p_width;
		int p_height;

		std::vector<std::vector<Color>> color_data;

		std::string file_name;
//		char* buffer;

	public:
		Bitmap (std::string fn, int pixel_width, int pixel_height){
			file_name = fn;
			//TODO: Check. Potentially dangerous??
			set_size(pixel_width, pixel_height);
//			buffer = create_header(pixel_width, pixel_height);
		}

		void set_size(int pixel_width, int pixel_height){
			p_width = pixel_width;
			p_height = pixel_height;
		}

		void set_color_data(std::vector<std::vector<Color>> colors){
			color_data = colors;
		}

		void write(){
			std::ofstream file;
			file.open(file_name);

			char* header = create_header(p_width, p_height);
			file.write(header, HEADER_SIZE);
			delete [] header;

			int pad = p_width % 4;
			for (unsigned int i = 0; i < color_data.size(); i++){
				for (unsigned int j = 0; j < color_data[i].size(); j++){
					char* buffer = new char[3];
					buffer[0] = color_data[i][j].b;
					buffer[1] = color_data[i][j].g;
					buffer[2] = color_data[i][j].r;
					file.write(buffer, 3);
					delete [] buffer;
				}
				if (pad > 0){
					char* buffer = new char[pad];
					for (int k = 0; k < pad; k++)
						buffer[k] = 0x00;
					file.write(buffer, pad);
					delete [] buffer;
				}
			}

			file.close();
		}
};

std::pair<int, int> point_to_pixel(Point p, double x_lower_bound, double y_lower_bound, double pixel_size){
	int j = (int) floor((p.x - x_lower_bound) / pixel_size);
	int i = (int) floor((p.y - y_lower_bound) / pixel_size);
	std::pair<int, int> indices (i, j);
	return indices;
}

#endif
