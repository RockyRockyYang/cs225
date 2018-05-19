#include "image.h"
#include <cstdint>

using namespace std;

void Image::flipleft() {
	size_t width = this->width();
	size_t height = this->height();
	RGBAPixel temPixel;
	for(int x=0; x<(int)width/2; x++) {
		for(int y=0; y<(int)height; y++) {
			RGBAPixel *temp = (*this)(x,y);
			temPixel.red = temp->red;
			temPixel.blue = temp->blue;
			temPixel.green = temp->green;
			
			temp->red = (*this)(width-x-1,y)->red;
			temp->green = (*this)(width-x-1,y)->green;
			temp->blue = (*this)(width-x-1,y)->blue;

			(*this)(width-x-1,y)->red = temPixel.red;
			(*this)(width-x-1,y)->green = temPixel.green;
			(*this)(width-x-1,y)->blue = temPixel.blue;
		}
	}	
}

void Image::adjustbrightness(int r, int g, int b) {
	size_t width = this->width();
	size_t height = this->height();
	for(int x=0; x<(int) width; x++) {
		for(int y=0; y<(int)height; y++) {
			RGBAPixel *temp = (*this)(x,y);
			int red = temp->red;
			int green = temp->green;
			int blue = temp->blue;

			if(red + r >255)
				temp->red = 255;
			else if(red + r <0)
				temp->red = 0;
			else
				temp->red = red +r;
			
			if(green + g >255)
				temp->green = 255;
			else if(green + g <0)
				temp->green = 0;
			else
				temp->green = green +g;
			
			if(blue + b >255)
				temp->blue = 255;
			else if(blue + b <0)
				temp->blue = 0;
			else
				temp->blue = blue +b;
			
		}	
	}
}

void Image::invertcolors() {
	size_t width = this->width();
	size_t height = this->height();
	for(int x=0; x<(int)width; x++) {
		for(int y=0; y<(int)height; y++) {
			RGBAPixel *temp = (*this)(x,y);
			int red = temp->red;
			int green = temp->green;
			int blue = temp->blue;
			temp->red = 255-red;
			temp->green = 255-green;
			temp->blue = 255-blue;
		}
	}
}
