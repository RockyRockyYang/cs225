/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num)
{
	for(int i=0; i< num; i++){
		vertex.push_back(-1);
	}

}

int DisjointSets::find(int elem)
{
	if(vertex[elem] < 0)
		return elem;
	else
		return vertex[elem] = find(vertex[elem]); 
}

void DisjointSets::setunion(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	unionBySize(root1, root2);
}

void DisjointSets::unionBySize(int root1, int root2)
{
	int newSize = vertex[root1] + vertex[root2];
	if(isBigger(root1, root2)){
		vertex[root2] = root1;
		vertex[root1] = newSize;
	}
	else{
		vertex[root1] = root2;
		vertex[root2] = newSize;
	}
}

bool DisjointSets::isBigger(int root1, int root2)
{
	if(vertex[root1] > vertex[root2])
		return false;
	else
		return true;
}

void DisjointSets::clear()
{
	vertex.erase(vertex.begin(), vertex.end());
}

int DisjointSets::fsize(int elem){
	if(vertex[elem]<0)
		return vertex[elem];
	else return fsize(find(elem));
}
