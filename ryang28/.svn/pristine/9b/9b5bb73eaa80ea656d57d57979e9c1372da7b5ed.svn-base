/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <math.h>

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(first[curDim] < second[curDim])
        return true;
    else if(first[curDim] == second[curDim])
        return first < second;
    else
        return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
	if(distance(potential, target) < distance(currentBest, target))
		return true;
	else if(distance(potential, target) == distance(currentBest, target))
		return potential < currentBest;
	else
    		return false;
}

//helper function distance, acutally distance_squre
template <int Dim>
int KDTree<Dim>::distance(const Point<Dim>& first,
                                const Point<Dim>& second) const
{
	int distance = 0;
	for(int i=0; i< Dim; i++){
		distance += pow((first[i]-second[i]), 2);
	}
	return distance;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     //assume at least one point in vector
     points = newPoints;
     buildTree(points, 0, newPoints.size() -1, 0);
}

template <int Dim>
void KDTree<Dim>::buildTree(vector<Point<Dim>>& points, int left, int right, int dimension)
{
    if(left >= right)
        return;
    int median = floor((left+right)/2);
    quickSelect(points, median, left, right, dimension);
    if(left<median)
        buildTree(points, left, median-1, (dimension+1)%Dim);
    if(right>median)
        buildTree(points, median+1, right, (dimension+1)%Dim);

}

template <int Dim>
void KDTree<Dim>::quickSelect(vector<Point<Dim>>& points, int n, int left, int right, int dimension)
{
    if(left >= right)
        return;
    int pivotIndex = n;     //randomly choose a pivotIndex
    pivotIndex = partition(points, pivotIndex, left, right, dimension);
    if(n == pivotIndex)
        return;
    else if(n < pivotIndex)
        return quickSelect(points, n, left, pivotIndex-1, dimension);
    else
        return quickSelect(points, n, pivotIndex+1, right, dimension);

}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& points, int pivotIndex, int left, int right, int dimension)
{
    Point<Dim> pivotValue = points[pivotIndex];
    //move pivot to the end
    Point<Dim> temp = points[pivotIndex];
    points[pivotIndex] = points[right];
    points[right] = temp;
    int storeIndex = left;
    for(int i= left; i<right; i++){
        if(smallerDimVal(points[i], pivotValue, dimension)){
            //swap points[storeIndex] and points[i]
            temp = points[storeIndex];
            points[storeIndex] = points[i];
            points[i] = temp;
            //increment storeIndex
            storeIndex++;
        }
    }
    //swap points[right] and points[storeIndex]
    temp = points[right];
    points[right] = points[storeIndex];
    points[storeIndex] = temp;

    return storeIndex;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    Point<Dim> root = points[(points.size()-1)/2];
    return findNearestNeighbor(query, root, 0, points.size()-1, 0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query, Point<Dim>& currentBest, int left, int right, int dimension) const
{
    // at leaf node
    if(left >= right){
        if(shouldReplace(query, currentBest, points[left])){
            currentBest = points[left];
        }
        return currentBest;
    }

    // serach down the tree
    int median = floor((left+right)/2);     //points[median] is our current node
    if(shouldReplace(query, currentBest, points[median])){
        currentBest = points[median];
    }
    // go down the left sub-tree                                                                                                           
    if(smallerDimVal(query, points[median], dimension) ) {
        currentBest = findNearestNeighbor(query, currentBest, left, median-1, (dimension+1)%Dim); //currentBest or points[median]
        if(shouldReplace(query, currentBest, points[median])){
            currentBest = points[median];
        }
        int radiusCurrentBest = distance(query, currentBest);
        int distanceDim = pow(points[median][dimension] - query[dimension],2);
        if(distanceDim <= radiusCurrentBest){           // could be a better node in right sub-tree
            currentBest = findNearestNeighbor(query, currentBest, median+1, right, (dimension+1)%Dim);
            return currentBest;
        }
    }
    // go down to the right sub-tree
    else if(smallerDimVal(points[median], query, dimension) ) {
        currentBest = findNearestNeighbor(query, currentBest, median+1, right, (dimension+1)%Dim); //currentBest or points[median]
        if(shouldReplace(query, currentBest, points[median])){
            currentBest = points[median];
        }
        int radiusCurrentBest = distance(query, currentBest);
        int distanceDim = pow(points[median][dimension] - query[dimension],2);
        if(distanceDim <= radiusCurrentBest){           // could be a better node in left sub-tree
            currentBest = findNearestNeighbor(query, currentBest, left, median-1, (dimension+1)%Dim);
            return currentBest;
        }
    }

    return currentBest;
}





