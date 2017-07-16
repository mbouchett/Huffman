/* 
 * File:   HuffNode.cpp
 * Author: mark adapted from:
 * credit: Knowles Atchison, Jr.
 * http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
 */
#include "HuffNode.h"

HuffNode::HuffNode() {
    character = ' ';
    freq = 0;
    left = NULL;
    right = NULL;
}

HuffNode::HuffNode(char c, int f) {
    character = c;
    freq = f;
    left = NULL;
    right = NULL;
}

HuffNode::HuffNode(HuffNode* left, HuffNode* right){
    this->left = left;
    this->right = right;
    freq = left->getFreq() + right->getFreq();
    character = ' ';
}

HuffNode::~HuffNode() {
    if(left != NULL) delete left;
    if(right != NULL) delete left;
}

HuffNode::HuffNode(const HuffNode& rhs){
    if(rhs.left != NULL){
        left = new HuffNode();
        *left = *(rhs.right);
    }
    encStr = rhs.encStr;
    character = rhs.character;
    freq = rhs.freq;
}

ostream& operator<<(ostream& os, const HuffNode& rhs){
    os << "\'" << rhs.character << " " << rhs.freq << "\'";
}

HuffNode& HuffNode::operator=(const HuffNode& rhs){
    if(!(this == &rhs)){
        //copy
        encStr = rhs.encStr;
        character = rhs.character;
        freq = rhs.freq;
        if(!(left == NULL)) delete left;
        if(!(right == NULL)) delete right;
        if(rhs.left != NULL){
            left = new HuffNode();
            *left = *(rhs.left);
            if(rhs.right != NULL){
                right = new HuffNode();
                *right = *(rhs.right);
            }
        }
        else left = right = NULL;
    }
    return *this;
}