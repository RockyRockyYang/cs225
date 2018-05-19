/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
     int row = theSource.getRows();
     int column = theSource.getColumns();
     if(row == 0 || column == 0 || theTiles.empty())
     	return NULL;

     MosaicCanvas* convas = new MosaicCanvas(row, column);
     //map color to the TileImage
     map<Point<3>, TileImage> mapColor;
     vector<Point<3>> colorVector;

     for(unsigned long i=0; i< theTiles.size(); i++){
     	RGBAPixel color = theTiles[i].getAverageColor();
     	Point<3> point(color.red, color.green, color.blue);
     	mapColor[point] = theTiles[i];
     	colorVector.push_back(point);
     }

     KDTree<3> tree(colorVector);

     for(int i=0; i< row; i++){
     	for(int j=0; j< column; j++){
     		RGBAPixel pixelColor = theSource.getRegionColor(i, j);
     		Point<3> pixelPoint(pixelColor.red, pixelColor.green, pixelColor.blue);
     		Point<3> nearestPoint = tree.findNearestNeighbor(pixelPoint);
     		TileImage nearestImage = mapColor[nearestPoint];
     		convas->setTile(i, j, nearestImage);
     	}
     }

    return convas;
}

