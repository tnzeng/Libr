#ifndef  __BITMAP_HEADER_HPP__
#define  __BITMAP_HEADER_HPP__

#define HEADER_SIZE (54)

char* create_header(int image_width, int image_height){
	int pad = image_width % 4;
	long long image_data_size = (3 * image_width + pad) * image_height;
	long long file_size = image_data_size + 0x36;

	char* buffer = new char[54];
	buffer[0] = 0x42; 	//B
	buffer[1] = 0x4d; 	//M

	//TODO: Change
	buffer[2] = file_size % 256; 	//Size of file
	buffer[3] = file_size / 256 % 256; 	//
	buffer[4] = file_size / 256 / 256 % 256; 	//
	buffer[5] = file_size / 256 /256 /256 % 256; 	//

	buffer[6] = 0x00; 	//Reserved to 0
	buffer[7] = 0x00; 	//
	buffer[8] = 0x00; 	//Reserved to 0
	buffer[9] = 0x00; 	//

	buffer[10] = 0x36;	//Offset to start of data
	buffer[11] = 0x00;  //
	buffer[12] = 0x00;  //
	buffer[13] = 0x00;  //

	buffer[14] = 0x28;  //Size of BITMAPINFOHEADER
	buffer[15] = 0x00;  //
	buffer[16] = 0x00;  //
	buffer[17] = 0x00;  //

	//TODO: Change
	buffer[18] = image_width % 256;  //Image width in pixels
	buffer[19] = image_width / 256 % 256;  //
	buffer[20] = image_width / 256 / 256 % 256;  //
	buffer[21] = image_width / 256 / 256 / 256 % 256;  //
	buffer[22] = image_height % 256;  //Image height in pixels
	buffer[23] = image_height / 256 % 256;  //
	buffer[24] = image_height / 256 / 256 % 256;  //
	buffer[25] = image_height / 256 / 256 / 256 % 256;  //

	buffer[26] = 0x01;  //Reserved to 1
	buffer[27] = 0x00;  //

	buffer[28] = 0x18;  //Bits per pixel
	buffer[29] = 0x00;  //

	buffer[30] = 0x00;  //Compression type
	buffer[31] = 0x00;  //
	buffer[32] = 0x00;  //
	buffer[33] = 0x00;  //

	//TODO: Change
	buffer[34] = image_data_size % 256;  //Size of image data in bytes (includes padding)
	buffer[35] = image_data_size / 256 % 256;  //
	buffer[36] = image_data_size / 256 / 256 % 256;  //
	buffer[37] = image_data_size / 256 / 256 / 256 % 256;  //

	buffer[38] = 0x00;  //Pixel per meter???
	buffer[39] = 0x00;  //
	buffer[40] = 0x00;  //
	buffer[41] = 0x00;  //
	buffer[42] = 0x00;  //Pixel per meter???
	buffer[43] = 0x00;  //
	buffer[44] = 0x00;  //
	buffer[45] = 0x00;  //

	buffer[46] = 0x00;  //Reserved to 0?
	buffer[47] = 0x00;  //
	buffer[48] = 0x00;  //
	buffer[49] = 0x00;  //
	buffer[50] = 0x00;  //Reserved to 0?
	buffer[51] = 0x00;  //
	buffer[52] = 0x00;  //
	buffer[53] = 0x00;  //

	return buffer;
}

#endif
