#include <cmath>
using namespace std;
#include "MaxHeap.h"

void prune(MaxHeap& heap, int m)
{
    // Your code here
	int length = heap.elements.size();
	for(int i=0; i< heap.elements.size(); i++){
		if(heap.elements[i] < m){
			heap.elements[i] = heap.elements[length - 1];
        		heap.elements.pop_back();
			heap.heapifyDown(i);
			i--;
		}
								
	}

}
