#include "binarytree.h"
#include <math.h>

int BinaryTree::minHeight() {
    /* Your code here! */
	int height = 0;
	if(root == NULL)
		return -1;
    	else
		return minHeight(root, height);
}

int BinaryTree::minHeight(Node* subRoot, int height)
{
	if(subRoot->left == NULL && subRoot->right == NULL)
		return height;
	else if(subRoot->left == NULL && subRoot->right != NULL)
		return minHeight(subRoot->right, height+1);
	else if(subRoot->left != NULL && subRoot->right == NULL)
		return minHeight(subRoot->left, height+1);
	else
		return min(minHeight(subRoot->left, height+1) , minHeight(subRoot->right, height+1));
}

