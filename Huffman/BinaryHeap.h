/* 
 * File:   BinaryHeap.h
 * Author: Knowles Atchison, Jr.
 * http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "HuffNode.h"

class BinaryHeap{
private:
    HuffNode** storage;
    int heapSize;
    int capacity;
 
    void percUp(int);
    void percDown(int);
    int numChildren(int);
     
    void inOrder(int);
    void postOrder(int);
    void preOrder(int);
    
public:
    BinaryHeap(int);
    ~BinaryHeap();
    void insert(HuffNode*);
    HuffNode* removeMin();
    HuffNode peekMin();

    bool isEmpty();
    int getHeapSize()       {return heapSize;};
    HuffNode* getRoot()     {return storage[0];};
    //traversal
    //not really necessary for Huffman, left for debug purposes
    void inOrderTraversal();
    void postOrderTraversal();
    void preOrderTraversal();
    void linearDisplay();
    //debug
    void emptyHeap();
};

#endif /* BINARYHEAP_H */

