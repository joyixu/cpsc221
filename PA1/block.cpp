#include "block.h"

int Block::width() const{
	return data.size();
}
int Block::height() const{
	return data[0].size();
}

void Block::build(PNG & im, int column, int width) {
	//From im, grabs the vertical strip of pixels whose upper left corner is at position (column,0)
	//and whose width is width.
	for (int i = column; i < column + width; i++) {
		vector<HSLAPixel> temp;
		int height = im.height();
		for (int j = 0; j < height; j++) {
			HSLAPixel* pixel = im.getPixel(i, j);
			temp.push_back(*pixel);
		}
		data.push_back(temp);
	}
	return;
}


void Block::render(PNG & im, int column ) const{
	//Draws the current block at position (column,0) in im.
   	for (int i = column; i < column + width(); i++) {
		for (int j = 0; j < height(); j++) {
			HSLAPixel* pixel = im.getPixel(i, j);
			*pixel = data[i-column][j];
		}
	}
}


void Block::greyscale(){
	for (int i = 0; i < width(); i++) {
		for (int j = 0; j < height(); j++) {
			HSLAPixel* pixel = &data[i][j];
			pixel->s=0;
		}
	}
}