/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:
	Quadtree();
	Quadtree(PNG const & source, int resolution);	
	void buildTree(PNG const & source, int resolution);
	Quadtree(Quadtree const& other);
	~Quadtree();
	Quadtree const& operator=(Quadtree const& other);
	RGBAPixel getPixel(int x, int y) const;
	PNG decompress()const;
	
	
	void clockwiseRotate();
	void prune(int tolerance);
	int pruneSize(int tolerance) const;
	int idealPrune(int numLeaves) const;

  private:
	/**
	void buildTree(PNG const & source, int d, QuadtreeNode* subRoot);
	void clear(QuadtreeNode* & subRoot);
	QuadtreeNode* copy(QuadtreeNode* subRoot);
	QuadtreeNode* find(QuadtreeNode* subRoot, int x, int y);
	bool inCell(QuadtreeNode* subRoot, int x, int y);
	
	void clockwiseRotate();
	void prune(int tolerance);
	int pruneSize(int tolerance) const;
	int idealPrune(int numLeaves) const;
	*/
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */
	int x;			// x coordinate
	int y;			// y coordinate
	int r;			// remember resolution
	QuadtreeNode(): nwChild(NULL), neChild(NULL), swChild(NULL), seChild(NULL), element(RGBAPixel()), x(0), y(0), r(1){/* nothing*/}

	QuadtreeNode(const RGBAPixel& elem):nwChild(NULL), neChild(NULL), swChild(NULL), seChild(NULL), element(elem), x(0), y(0),r(1){/* nothing*/}
  	
	QuadtreeNode(const RGBAPixel& elem, int xCoord, int yCoord, int resolution):nwChild(NULL), neChild(NULL), swChild(NULL), seChild(NULL), element(elem), x(xCoord), y(yCoord),r(resolution){/* nothing*/}

	QuadtreeNode(int xCoord, int yCoord, int resolution){
		nwChild = NULL;
		neChild = NULL;
		swChild = NULL;
		seChild = NULL;
		element = RGBAPixel();
		x = xCoord;
		y = yCoord;
		r = resolution;
	}

    };

    QuadtreeNode* root; /**< pointer to root of quadtree */

	void buildTree(PNG const & source, int d, QuadtreeNode* subRoot);
	void clear(QuadtreeNode* & subRoot);
	QuadtreeNode* copy(QuadtreeNode* subRoot);
	QuadtreeNode* find(QuadtreeNode* subRoot, int x, int y) const;
	bool inCell(QuadtreeNode* subRoot, int x, int y) const;
	void decompress(PNG & img, QuadtreeNode* subRoot,int d)const;
	void clockwiseRotate(QuadtreeNode* subRoot);
	void prune(QuadtreeNode* subRoot, int tolerance);
	bool condition(QuadtreeNode* subsubRoot, QuadtreeNode* subRoot, int tolerance) const;
	int pruneSize(int tolerance, QuadtreeNode* subRoot) const;
	int idealPrune(int numLeaves,int lo, int hi) const;
/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
