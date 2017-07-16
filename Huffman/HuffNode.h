/* 
 * File:   HuffNode.h
 * Author: mark adapted from:
 * credit: Knowles Atchison, Jr.
 * http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
 */

#ifndef HUFFNODE_H
#define HUFFNODE_H
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class HuffNode {
private:
    int freq;
    char character;                 //character to be encoded
    string encStr;                  //encoded string
    HuffNode* left, *right;         //pointers to the children

public:
    HuffNode();                     //no param constructor
    HuffNode(char, int);            //encode constructor
    HuffNode(HuffNode*, HuffNode*); //node constructor
    HuffNode(const HuffNode&);      //node reference constructor
    ~HuffNode();                    //node de-constructor
    
    //getters
    int getFreq()           {return freq;};
    char getCharacter()     {return character;};
    string getCode()        {return encStr;}; 
    HuffNode* getLeft()     {return left;};
    HuffNode* getRight()    {return right;};
    
    //setters
    void setHuffCode(std::string s) {encStr = s;};
    
    // overridden operators
    friend ostream& operator<<(ostream&, const HuffNode&);
    
    HuffNode& operator=(const HuffNode&);
    
};

#endif /* HUFFNODE_H */