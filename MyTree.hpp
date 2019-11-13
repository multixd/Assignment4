//
//  MyTree.hpp
//  Assignment4
//
//  Created by Vincent Liang on 11/2/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#ifndef MyTree_hpp
#define MyTree_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class MyTree;

class BinaryNode {
public:
    BinaryNode(string s, int m):myString(s),myInt(m){};
    ~BinaryNode() {};
    int getInt() const {return myInt;};
    string getString() const {return myString;};
private:
    string myString;
    int    myInt;
    BinaryNode *lchild = nullptr;
    BinaryNode *rchild = nullptr;
    BinaryNode* parent = nullptr;
    friend class MyTree;
    };

struct Node{
    Node(int x, string y):value(x),aString(y){};
    Node():value(-1),aString("-1"){};
    int value;
    string aString;
    bool operator < (const Node& rhs) const
    {
        return (value < rhs.value);
    }
    
    //void replace(int x, string y) {value = x; aString = y;}
};

class MyTree {
public:
    MyTree();
    ~MyTree();

    // Insert new node into first available position (to keep the tree almost complete).
    void insert (int x ,string s);

    //Output all strings in pre-order
    //all the strings will be print in one line separated by spaces
    void preorder() const;

    //Returns a pointer to the node with maximum myInt
    BinaryNode *findMax() const;

    // Converts the binary tree into a binary search tree (BST) with respect to myInt.
    // That is, move around node values (myString and myInt) to satisfy the BST property.
    void makeBST();
    void inorder() const;
    


private:
    void preorderRecursive(BinaryNode*) const;
    void inorderRecursive(BinaryNode*) const;
    //BinaryNode *findMaxRecursive(BinaryNode*) const;
    BinaryNode *root = nullptr;
    vector<BinaryNode*> v;
    void storeInorder(Node*, BinaryNode*, int*);
    void makeBSTRecursive(Node*, BinaryNode*, int*);

};



#endif /* MyTree_hpp */

