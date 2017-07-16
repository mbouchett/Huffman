/*
 * File:   BinaryHeap.cpp
 * Author: Knowles Atchison, Jr.
 * http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
 */
#include "BinaryHeap.h"
#include <iostream>
using namespace std;
	 
	 
BinaryHeap::BinaryHeap(int size){
    capacity = size;
    heapSize = 0;
    storage = new HuffNode*[capacity];
    for(int i = 0; i < capacity; i++){
        storage[i] = NULL;
    }
}
	 
BinaryHeap::~BinaryHeap(){
    if(storage != NULL){
        for(int i = 0; i < capacity; i++){
            if(storage[i] != NULL){
                delete storage[i];
                heapSize--;
            }
        }
        delete[] storage;
        //for debug purposes
        cout << "heap size is (should be zero): " << heapSize << endl;
    }
}

void BinaryHeap::insert(HuffNode* rhs){
    if(heapSize == capacity){
        cerr << "No more room in this heap!" << endl;
        return;
    }

    //insert at end
    heapSize++;
    storage[heapSize-1] = rhs;
    percUp(heapSize-1);
}

void BinaryHeap::percUp(int curIndex){
    int parentIndex;
    HuffNode* temp;
    if(curIndex != 0) { //are we at the "top"?
        parentIndex = (curIndex-1)/2;
        //min heap
        if(storage[parentIndex]->getFreq() > storage[curIndex]->getFreq()){
            temp = storage[parentIndex];
            storage[parentIndex] = storage[curIndex];
            storage[curIndex] = temp;
            percUp(parentIndex);
        }
    }
}

int BinaryHeap::numChildren(int index){
    int children = 0, left = 2*index+1, right = 2*index+2;
    if(left >= heapSize) return 0;
    if(storage[left] != NULL) children++;
    if (storage[right] != NULL) children++;
    return children;
}

void BinaryHeap::percDown(int curIndex){
    int children = 0;
    if(children = numChildren(curIndex)){ //are we at the "bottom"?
        HuffNode* temp;
        int left = 2*curIndex+1, right = 2*curIndex+2;
        switch(children){ //1 child or 2 children
            case 1:
                //if the child is smaller, perk the current node down
                if(storage[curIndex]->getFreq() > storage[left]->getFreq()){
                    temp = storage[curIndex];
                    storage[curIndex] = storage[left];
                    storage[left] = temp;
                    percDown(left);
                }
                break;
            case 2:
                //2 children, determine which is smaller, perk down that direction
                if((storage[curIndex]->getFreq() > storage[left]->getFreq()) ||
                            (storage[curIndex]->getFreq() > storage[right]->getFreq())){
                    //left child is smaller
                    if((storage[left]->getFreq() < storage[right]->getFreq())){
                        temp = storage[curIndex];
                        storage[curIndex] = storage[left];
                        storage[left] = temp;
                        percDown(left);
                    }
                    else{ //right child is smaller
                        temp = storage[curIndex];
                        storage[curIndex] = storage[right];
                        storage[right] = temp;
                        percDown(right);
                    }
                }
                break;
            default:
                cout << " *** This shouldn't happen" << endl;
                break;
        }
    }
    return;
}


HuffNode* BinaryHeap::removeMin(){
    HuffNode* value = new HuffNode();
    *value = *storage[0];
    //replace min with last filled node slot (heapSize-1)
    //perc down
    HuffNode* temp = storage[0];
    storage[0] = storage[heapSize-1];
    storage[heapSize-1] = temp;
    delete storage[heapSize-1]; //free
    storage[heapSize-1] = NULL; //avoid dangling pointers
    heapSize--;
    percDown(0);
    return value;
}

HuffNode BinaryHeap::peekMin(){
    return *storage[0];
}

bool BinaryHeap::isEmpty(){
    return (heapSize == 0);
}

void BinaryHeap::inOrderTraversal(){
    if(isEmpty()){
        cout << "Heap is empty!" << endl;
        return;
    }
    inOrder(0);
    cout << endl;
}

void BinaryHeap::inOrder(int curIndex){
    //left
    //cur
    //right
    if(((2*curIndex+1) < capacity) && (storage[2*curIndex+1] != NULL)) inOrder(2*curIndex+1);
    cout << *storage[curIndex] << " ";
    if(((2*curIndex+2) < capacity) && (storage[2*curIndex+2] != NULL)) inOrder(2*curIndex+2);
}

void BinaryHeap::postOrderTraversal(){
    if(isEmpty()){
        cout << "Heap is empty!" << endl;
        return;
    }
    postOrder(0);
    cout << endl;
}

void BinaryHeap::postOrder(int curIndex){
    //left
    //right
    //cur
    if(((2*curIndex+1) < capacity) && (storage[2*curIndex+1] != NULL)) inOrder(2*curIndex+1);
    if(((2*curIndex+2) < capacity) && (storage[2*curIndex+2] != NULL)) inOrder(2*curIndex+2);
    cout << *storage[curIndex] << " ";
}


void BinaryHeap::preOrderTraversal(){
    if(isEmpty()){
        cout << "Heap is empty!" << endl;
        return;
    }
    preOrder(0);
    cout << endl;
}

void BinaryHeap::preOrder(int curIndex){
    //cur
    //left
    //right
    cout << *storage[curIndex] << " ";
    if(((2*curIndex+1) < capacity) && (storage[2*curIndex+1] != NULL)) inOrder(2*curIndex+1);
    if(((2*curIndex+2) < capacity) && (storage[2*curIndex+2] != NULL)) inOrder(2*curIndex+2);
}


void BinaryHeap::linearDisplay(){
    for(int i = 0; i < heapSize; i++){
        cout << *storage[i] << " ";
    }
    cout << endl;
}

void BinaryHeap::emptyHeap(){
    while(!isEmpty()){
        HuffNode* temp = removeMin();
        cout << *temp << endl;
    }
}