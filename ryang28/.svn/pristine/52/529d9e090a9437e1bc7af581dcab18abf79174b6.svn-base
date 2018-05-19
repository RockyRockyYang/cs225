/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <iostream>
using namespace std;

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL)
        return;
    if(t->right == NULL)
        return;
    Node* temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;
    t->left->height = max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right)) +1;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) +1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL)
        return;
    if(t->left == NULL)
        return;
    Node* temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;
    temp->right->height = max(heightOrNeg1(temp->right->left), heightOrNeg1(temp->right->right)) +1;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) +1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(subtree == NULL)
        return;
    int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
    //cout<< balance <<endl;
    int leftBalance = 0;
    int rightBalance = 0;
    if(subtree->left != NULL)
        leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
    if(subtree->right != NULL)
        rightBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
    if(balance == -2){
        if(leftBalance == -1)
            rotateRight(subtree);
        else
            rotateLeftRight(subtree);
    }
    if(balance == 2){
        if(rightBalance == 1){
            rotateLeft(subtree);
        }
        else
            rotateRightLeft(subtree);
    }
    //cout<< balance <<endl;
    //cout<< leftBalance <<endl;
    // if(balance == -2){
    //     if(subtree->left != NULL)
    //         leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
    //     if(leftBalance == -1)
    //         rotateRight(subtree);
    //     else
    //         rotateLeftRight(subtree);
    // }
    // if(balance == 2){
    //     if(subtree->right != NULL)
    //         rightBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
    //     if(rightBalance == 1){
    //         rotateLeft(subtree);
    //         cout << "yelling"<< endl;
    //     }
    //     else
    //         rotateRightLeft(subtree);
    // }

}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL)
        subtree = new Node(key, value);
    else if(key < subtree->key){
        insert(subtree->left, key, value);
        //rebalance(subtree);
    }
    else if(key > subtree->key){
        insert(subtree->right, key, value);
        //rebalance(subtree);
    }
    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) +1;
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);

    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);

    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* iop = rightMostChild(subtree->left);
            swap(subtree, iop);
            remove(subtree->left, key);

        } else {
            /* one-child remove */
            // your code here
            if(subtree->left == NULL){
                Node* temp = subtree;
                subtree = subtree->right;
                delete temp;
                temp = NULL;
            }
            if(subtree->right == NULL){
                Node* temp = subtree;
                subtree = subtree->left;
                delete temp;
                temp = NULL;
            }

        }
        // your code here
    }
    rebalance(subtree);
}


template <class K, class V>
typename AVLTree<K, V>::Node* & AVLTree<K, V>::rightMostChild(Node*& subtree)
{
    if(subtree->right == NULL)
        return subtree;
    else
        return rightMostChild(subtree->right);
}

