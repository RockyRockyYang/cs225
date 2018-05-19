#include "png.h"

int main(){
PNG input = PNG("in.png");
size_t height = input.height();
size_t width = input.width();
PNG output =PNG(width, height);

for(int x=0; x < width; x++) {
	for(int y=0; y < height; y++) {
		int iy = height - y -1;
		int ix = width - x -1;
	        RGBAPixel pix = *input(ix, iy);
               output(x, y)->red = pix.red;
               output(x, y)->green = pix.green;
               output(x, y)->blue = pix.blue;
		
	}
}
output.writeToFile("out.png");
return 0;
}
