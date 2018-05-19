/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
#include "quadtree.h"
#include "math.h"
#include<iostream>
using namespace std;

Quadtree::Quadtree():root(NULL){}

Quadtree::Quadtree(PNG const & source, int resolution)
{
	root = NULL;	//turn garbage into null
	buildTree(source, resolution);
}

Quadtree::Quadtree(Quadtree const& other)
{
	if(other.root == NULL)
		root = NULL;
	root = copy(other.root);
}

Quadtree::~Quadtree()
{
	clear(root);
}

Quadtree const & Quadtree::operator=(Quadtree const & other)
{
	if(this == &other)
		return *this;
	clear(root);
	if(other.root == NULL)
		root = NULL;
	root = copy(other.root);
	return *this;
}

void Quadtree::buildTree(PNG const & source, int resolution)
{
	if(root != NULL)	
		clear(root);
	root = new QuadtreeNode(0,0,resolution);	// create new root	
	//call helper function with subRoot parameter
	buildTree(source, resolution, root);	

}
//helper method with *subRoot
void Quadtree::buildTree(PNG const & source, int d, QuadtreeNode* subRoot)
{
	if(d == 1){
		subRoot->element = *source(subRoot->x, subRoot->y);
		return;
	}
	subRoot->nwChild = new QuadtreeNode(subRoot->x, subRoot->y, d/2);
	subRoot->neChild = new QuadtreeNode(subRoot->x + d/2, subRoot->y, d/2);
	subRoot->swChild = new QuadtreeNode(subRoot->x, subRoot->y + d/2, d/2);
	subRoot->seChild = new QuadtreeNode(subRoot->x + d/2, subRoot->y + d/2, d/2);

	buildTree(source, d/2, subRoot->nwChild);
	buildTree(source, d/2, subRoot->neChild);
	buildTree(source, d/2, subRoot->swChild);
	buildTree(source, d/2, subRoot->seChild);

//average color
	subRoot->element.red = (subRoot->nwChild->element.red + subRoot->neChild->element.red + subRoot->swChild->element.red + subRoot->seChild->element.red)/4;
	subRoot->element.green = (subRoot->nwChild->element.green + subRoot->neChild->element.green + subRoot->swChild->element.green + subRoot->seChild->element.green)/4;
	subRoot->element.blue = (subRoot->nwChild->element.blue + subRoot->neChild->element.blue + subRoot->swChild->element.blue + subRoot->seChild->element.blue)/4;

}

RGBAPixel Quadtree::getPixel(int x, int y) const
{
	if(root == NULL || !inCell(root, x, y))
		return RGBAPixel();
	QuadtreeNode* pointer = find(root, x, y);	//call helper function with *root
	return pointer->element;
}

typename Quadtree::QuadtreeNode* Quadtree::find(QuadtreeNode* subRoot, int x, int y) const
{
	// no according coordinate and leaf
	if(subRoot->nwChild == NULL)	
		return subRoot;

	else if(subRoot->x == x && subRoot->y == y && subRoot->r ==1)
		return subRoot;

	else if(inCell(subRoot->nwChild, x, y))
		return find(subRoot->nwChild, x, y);

	else if(inCell(subRoot->neChild, x, y))
		return find(subRoot->neChild, x, y);

	else if(inCell(subRoot->swChild, x, y))
		return find(subRoot->swChild, x, y);

	else //if(inCell(subRoot->seChild, x, y))
		return find(subRoot->seChild, x, y);
}
//return whether in this field or not
bool Quadtree::inCell(QuadtreeNode* subRoot, int x, int y) const
{
	return (x>=subRoot->x && x< subRoot->x + subRoot->r) && (y>=subRoot->y && y< subRoot->y + subRoot->r);
}

PNG Quadtree::decompress()const
{
	if(root == NULL)
		return PNG();
	PNG output = PNG(root->r, root->r);
	decompress(output, root, root->r);
	return output;
}
void Quadtree::decompress(PNG & img, QuadtreeNode* subRoot,int d)const
{
	if(subRoot->nwChild == NULL){
		for(int i=0; i< d;i++){
			for(int j=0; j< d; j++){
				*img(subRoot->x + i,subRoot->y + j) = subRoot->element;
			}
		}
		return;
	}
	decompress(img, subRoot->nwChild, d/2);
	decompress(img, subRoot->neChild, d/2);
	decompress(img, subRoot->swChild, d/2);
	decompress(img, subRoot->seChild, d/2);
}
void Quadtree::clockwiseRotate()
{
	/* nothing*/
	if(root == NULL)
		return;
	clockwiseRotate(root);
}

void Quadtree::clockwiseRotate(QuadtreeNode* subRoot)
{
	if(subRoot->nwChild == NULL)
		return;
	QuadtreeNode* temp = subRoot->nwChild;
	subRoot->nwChild = subRoot->swChild;
	subRoot->swChild = subRoot->seChild;
	subRoot->seChild = subRoot->neChild;
	subRoot->neChild = temp;

	subRoot->nwChild->x = subRoot->x;
	subRoot->nwChild->y = subRoot->y;

	subRoot->neChild->x = subRoot->x + (subRoot->r)/2;
	subRoot->neChild->y = subRoot->y;

	subRoot->swChild->x = subRoot->x;
	subRoot->swChild->y = subRoot->y + (subRoot->r)/2;

	subRoot->seChild->x = subRoot->x + (subRoot->r)/2;
	subRoot->seChild->y = subRoot->y + (subRoot->r)/2;

	clockwiseRotate(subRoot->nwChild);
	clockwiseRotate(subRoot->neChild);
	clockwiseRotate(subRoot->swChild);
	clockwiseRotate(subRoot->seChild);
}

void Quadtree::prune(int tolerance)
{
	/* nothing*/
	if(root == NULL)
		return;
	prune(root, tolerance);
}

void Quadtree::prune(QuadtreeNode* subRoot, int tolerance)
{
	if(condition(subRoot,subRoot, tolerance) == true){
		//cout<<"print" <<endl;
		clear(subRoot->nwChild);
		clear(subRoot->neChild);
		clear(subRoot->swChild);
		clear(subRoot->seChild);
		return;
	}
	else{
		prune(subRoot->nwChild, tolerance);
		prune(subRoot->neChild, tolerance);
		prune(subRoot->swChild, tolerance);
		prune(subRoot->seChild, tolerance);
	}

}
bool Quadtree::condition(QuadtreeNode* subsubRoot, QuadtreeNode* subRoot, int tolerance) const
{
	if(subsubRoot->nwChild == NULL)
		return ((pow((subsubRoot->element.red - subRoot->element.red), 2) + 
				 pow((subsubRoot->element.green - subRoot->element.green), 2) + 
				 pow((subsubRoot->element.blue - subRoot->element.blue), 2)) <= tolerance);

	return (condition(subsubRoot->nwChild, subRoot, tolerance) && 
			condition(subsubRoot->neChild, subRoot, tolerance) &&
			condition(subsubRoot->swChild, subRoot, tolerance) &&
			condition(subsubRoot->seChild, subRoot, tolerance) );

}

int Quadtree::pruneSize(int tolerance) const
{
	if(root == NULL)
		return 0;
	return pruneSize(tolerance, root);
}
int Quadtree::pruneSize(int tolerance, QuadtreeNode* subRoot) const
{
	if(condition(subRoot,subRoot, tolerance) == true)
		return 1;
	if(subRoot->nwChild == NULL)
		return 1;

	return pruneSize(tolerance, subRoot->nwChild) + pruneSize(tolerance, subRoot->neChild) +
		pruneSize(tolerance, subRoot->swChild) + pruneSize(tolerance, subRoot->seChild);

}

int Quadtree::idealPrune(int numLeaves) const
{
	int tolerance = idealPrune(numLeaves, 0 ,(3*255*255));
	return tolerance;
}

int Quadtree::idealPrune(int numLeaves,int lo, int hi) const
{
	int mid = (lo + hi)/2;

	if(pruneSize(mid) <= numLeaves && pruneSize(mid-1)> numLeaves)
		return mid;

	else if(pruneSize(mid) <= numLeaves){
		return idealPrune(numLeaves, lo, mid-1);
	}
	else{
		return idealPrune(numLeaves, mid+1, hi);
	}
}

//copy helper function, return QuadtreeNode*
typename Quadtree::QuadtreeNode* Quadtree::copy(QuadtreeNode* subRoot)
{
	QuadtreeNode *t = NULL;
	if(subRoot != NULL){
		t = new QuadtreeNode(subRoot->element, subRoot->x, subRoot->y, subRoot->r);
		t->nwChild = copy(subRoot->nwChild);
		t->neChild = copy(subRoot->neChild);
		t->swChild = copy(subRoot->swChild);
		t->seChild = copy(subRoot->seChild);
	}
	return t;
}

void Quadtree::clear(QuadtreeNode * & subRoot)
{
	if(subRoot == NULL)
		return;
	clear(subRoot->nwChild);
	clear(subRoot->neChild);
	clear(subRoot->swChild);
	clear(subRoot->seChild);
	delete subRoot;
	subRoot = NULL;
}
