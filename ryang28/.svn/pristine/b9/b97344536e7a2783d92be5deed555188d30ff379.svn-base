/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include<iostream>
using namespace std;

template <class T>
List<T>::~List()
{
    clear();/// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
	while(head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    /// @todo Graded in MP3.1
	ListNode* p = new ListNode(ndata);
	if(length == 0) {
		head = p;
		tail = p;
		length++;
	}
	else {
		head->prev = p;
		p->next = head;
		head = p;
		length++;
	}
	p = NULL;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    /// @todo Graded in MP3.1
	ListNode* p = new ListNode(ndata);
	if(length == 0) {
		head = p;
		tail = p;
		length++;
	}
	else {
		tail->next = p;
		p->prev = tail;
		tail = p;
		length++;
	}
	p = NULL;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
{
    /// @todo Graded in MP3.1

    if(startPoint == endPoint || length == 0 || startPoint== NULL || endPoint== NULL)
        return;
    ListNode* curr = startPoint;
    ListNode* temp = startPoint;
    ListNode* temp2 = startPoint;
    ListNode* endnext = endPoint->next;
    ListNode* startprev = startPoint->prev;

    while(curr != endnext){
	if(curr == startPoint) {
		temp = curr->next;
		curr->next = endnext;
		if(endnext != NULL)
			endnext->prev = curr;
		curr->prev = temp;
		curr = curr->prev;
	}
	if(curr == endPoint) {
		temp = curr->prev;
		curr->next = temp;
		curr->prev = startprev;
		if(startprev != NULL)
			startprev->next = curr;
		curr = curr->prev;
		break;
	}
        if(curr != NULL) {
            temp = curr->next;
            temp2 = curr->prev;
            curr->prev = temp;
            curr->next = temp2;
	    curr = curr->prev;
        }
    }

    temp = startPoint;
    startPoint = endPoint;
    endPoint = temp;
    curr = NULL;
    temp = NULL;
    temp2 = NULL;
    endnext = NULL;
    startprev = NULL;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
	if(n <=1 || length <=1 || head == NULL || tail == NULL)
		return;

	ListNode* curr = head;
	ListNode* nhead = head;
	ListNode* temp = NULL;
	int remain = length;
	bool flag = true;

	if(length == n) {
		reverse(curr, tail);
		head = curr;
		return;		
	}

	while(curr != NULL && remain >0) {
		for(int i=0; i< n-1; i++) {
			if(curr->next == NULL)
				break;
			curr = curr->next;
		}
		temp = curr->next;
		reverse(nhead, curr);
		if(flag)
			head = nhead;
		flag = false;
		if(curr->next == NULL)//change since last time
			tail = curr;
		curr = temp;
		nhead = temp;
		remain = remain -n;
	}
	curr = NULL;
	nhead = NULL;
	temp = NULL;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1
	if(length ==0)
		return;
	bool nextcycle = true;
	ListNode* curr = head;
	ListNode* skip = head;
	while(skip->next != tail && skip != tail && skip != NULL) {
		while(nextcycle) {

			curr = skip;
			skip = skip->next;
			nextcycle = false;
		}
		//skip = skip->next;
		curr->next = skip->next; 
		skip->next->prev = curr;
		tail->next = skip;
		skip->prev = tail; // connect tail to skip
		skip->next = NULL;
		
		tail = skip;	// make skip become new tail
		skip = curr->next;
		nextcycle = true;
	}
	curr = NULL;
	skip = NULL;
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
	int count = splitPoint;
	ListNode* temp = start;
	ListNode* secondHead = start;	
	while(count >1) {
		temp = temp->next;
		count--;
}
	secondHead = temp->next;
	temp->next = NULL;
	secondHead->prev = NULL;
	temp = NULL;
	return secondHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    /// @todo Graded in MP3.2
	ListNode* currFirst = first;
	ListNode* currSecond = second;
	ListNode* curr = first;

	if(currFirst->data < currSecond->data) {
		head = currFirst;
		curr = first;
		currFirst = currFirst->next;	
	}
	else {
		head = currSecond;
		curr = second;
		currSecond = currSecond->next;
	}

	while(currFirst != NULL || currSecond != NULL) {
		if(currFirst == NULL && currSecond != NULL) {
			curr->next = currSecond;
			currSecond->prev = curr;
			curr = curr->next;
			currSecond = currSecond->next;
		}
		if(currFirst != NULL && currSecond == NULL) {
			curr->next = currFirst;
			currFirst->prev = curr;
			curr = curr->next;
			currFirst = currFirst->next;
		}
		if(currFirst != NULL && currSecond != NULL) {
			if(currFirst->data < currSecond->data){
				curr->next = currFirst;
				currFirst->prev = curr;
				curr = curr->next;
				currFirst = currFirst->next;				
			}
			else {
				curr->next = currSecond;
				currSecond->prev = curr;
				curr = curr->next;
				currSecond = currSecond->next;
			}
		}
	}
	tail = curr;
	return head;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
    /// @todo Graded in MP3.2
	if(chainLength == 1)
		return start;
	int length = chainLength/2;
	ListNode* first = start;
	ListNode* second = split(start, length);
	first = mergesort(first, length);
	second = mergesort(second, chainLength - length);
	return merge(first, second);   
}
