/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. Heavily based on
 * old MP4 by CS225 Staff, Fall 2010.
 *
 * @author Chase Geigle
 * @date Fall 2012
 */
#include "filler.h"
#include <cmath>
#include <iostream>

animation filler::dfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
	solidColorPicker color(fillColor);
    return filler::fill<Stack>(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
	gridColorPicker color(gridColor, gridSpacing);
    return filler::fill<Stack>(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
	gradientColorPicker color(fadeColor1, fadeColor2, radius, x, y);
    return filler::fill<Stack>(img, x, y, color, tolerance, frameFreq);
}

animation filler::dfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */ 
    return filler::fill<Stack>(img, x, y, fillColor, tolerance, frameFreq); 
}

animation filler::bfs::fillSolid(PNG& img, int x, int y, RGBAPixel fillColor,
                                 int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
  	solidColorPicker color(fillColor);
    	return filler::fill<Queue>(img, x, y, color, tolerance, frameFreq);
}

animation filler::bfs::fillGrid(PNG& img, int x, int y, RGBAPixel gridColor,
                                int gridSpacing, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
  	gridColorPicker color(gridColor, gridSpacing);
    	return filler::fill<Queue>(img, x, y, color, tolerance, frameFreq);
}

animation filler::bfs::fillGradient(PNG& img, int x, int y,
                                    RGBAPixel fadeColor1, RGBAPixel fadeColor2,
                                    int radius, int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to fill with the correct colorPicker parameter.
     */
   	gradientColorPicker color(fadeColor1, fadeColor2, radius, x, y);
   	return filler::fill<Queue>(img, x, y, color, tolerance, frameFreq);
}

animation filler::bfs::fill(PNG& img, int x, int y, colorPicker& fillColor,
                            int tolerance, int frameFreq)
{
    /**
     * @todo Your code here! You should replace the following line with a
     * correct call to filler::fill with the correct template parameter
     * indicating the ordering structure to be used in the fill.
     */
    return filler::fill<Queue>(img, x, y, fillColor, tolerance, frameFreq);
}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       int tolerance, int frameFreq)
{
  	animation output; 
	OrderingStructure<int> xlist;
	OrderingStructure<int> ylist;
	OrderingStructure<RGBAPixel> pixels;
	int frame = 0;

	int** processed = new int*[img.width()];
	for(int i=0; i< (int)img.width(); i++){
		processed[i] = new int[img.height()];
		for(int j=0; j< (int)img.height(); j++){
			processed[i][j] = false;		
		} 
	}

	int originalRed = img(x,y)-> red;
	int originalBlue = img(x,y)-> blue;
	int originalGreen = img(x,y)-> green;

	pixels.add(*img(x,y));
	xlist.add(x);
	ylist.add(y);

	while(!pixels.isEmpty()){	
		RGBAPixel currentPixel = pixels.remove();
		int currRed = currentPixel.red;
		int currBlue = currentPixel.blue;
		int currGreen = currentPixel.green;
		int currX = xlist.remove();
		int currY = ylist.remove();
		
		int d = pow(currRed - originalRed, 2) + pow(currBlue-originalBlue, 2) + pow(currGreen - originalGreen, 2);
		if(d <= tolerance && !processed[currX][currY]) {
		//cout<<frame<<endl;
		//cout<<<<endl
			processed[currX][currY] = true;
			*img(currX, currY) = fillColor(currX,currY);
			frame ++;

			if(frame % frameFreq == 0){
				output.addFrame(img);
				frame = 0;
			}		
			if(currX+1 < (int)img.width()){
				pixels.add(*img(currX+1,currY));
				xlist.add(currX+1);
				ylist.add(currY);
			}
			if(currY+1 < (int)img.height()){
				pixels.add(*img(currX,currY+1));
				xlist.add(currX);
				ylist.add(currY+1);
			}
			if(currX-1 >= 0){
				pixels.add(*img(currX-1,currY));
				xlist.add(currX-1);
				ylist.add(currY);
			}
			if(currY-1 >= 0){
				pixels.add(*img(currX,currY-1));
				xlist.add(currX);
				ylist.add(currY-1);
			}

	
		}

	}
	for(int i=0; i< (int)img.width(); i++){
		delete []processed[i];
		processed[i] = NULL;
	}
	delete []processed;
	processed = NULL;
    return output;

}

