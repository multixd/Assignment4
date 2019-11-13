//
//  MyTree.cpp
//  Assignment4
//
//  Created by Vincent Liang on 11/2/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include "MyTree.hpp"
#include <algorithm>
#include <iostream>


MyTree::MyTree() {}

MyTree::~MyTree() {
    if(root == nullptr) {
        return;
    }
    
    for(unsigned long i =0; i<v.size()-1; ++i) {
        delete v.at(i);
        v.at(i) = nullptr;
    }
    v.clear();
}

void MyTree::insert (int x ,string s) {
    BinaryNode* curr = new BinaryNode(s,x);
    
    if(root == nullptr) {
        
        root = curr;
        v.push_back(curr);
        return;
    }
    
    v.push_back(curr);
    curr->parent = v.at((v.size()-2)/2);
    
    if(curr->parent-> lchild == nullptr) {
        curr->parent->lchild = curr;
    }
    else {
        curr->parent->rchild = curr;
    }
    
    
    /*if(root == nullptr) {
        root = curr;
        nextNode = curr;
        return;
    }
    else if(nextNode->lchild == nullptr) {
        nextNode->lchild = curr;
        curr->parent = nextNode;
        return;
    }
    else if(nextNode->rchild == nullptr) {
        nextNode->rchild = curr;
        curr->parent = nextNode;
        return;
    }
    else if(root == nextNode) {
        nextNode = nextNode -> lchild;
        curr->parent = nextNode;
        nextNode->lchild = curr;
        return;
    }
    else if(nextNode->parent->lchild == nextNode) {
        nextNode = nextNode->parent ->rchild;
        nextNode->lchild = curr;
        curr->parent = nextNode;
        return;
    }
    else {
        nextNode = nextNode->parent->lchild->lchild;
        nextNode -> lchild = curr;
        curr ->parent = nextNode;
        return;
    }
    else {
        nextNode = nextNode->lchild;
        curr->parent = nextNode;
        nextNode ->lchild = curr;
        return;
    }*/
}

void MyTree::preorder() const {
    preorderRecursive(root);
}


void MyTree::preorderRecursive(BinaryNode* curr) const {
    if(curr == nullptr) {
        return;
    }
    std::cout << curr->getString() << " ";
    preorderRecursive(curr->lchild);
    preorderRecursive(curr->rchild);
}

void MyTree::inorderRecursive(BinaryNode* curr) const {
    if(curr == nullptr) {
        return;
    }
    inorderRecursive(curr->lchild);
    std::cout << curr->getInt() << " ";
    inorderRecursive(curr->rchild);
}

void MyTree::inorder() const {
    inorderRecursive(root);
}

BinaryNode* MyTree::findMax() const {
    if(root == nullptr) {
        return nullptr;
    }
    BinaryNode* max = root;
    for(unsigned i=1; i < v.size()-1; ++i) {
        if(v.at(i)->getInt() > max->getInt()) {
            max = v.at(i);
        }
    } 
    return max;
}

/*
 BinaryNode* MyTree::findMaxRecursive(BinaryNode* curr) const {
    if(curr == nullptr){
        return nullptr;
    }
    
    int val = curr->getInt();
    int lval = -1;
    int rval = -1;
    
    if(findMaxRecursive(curr->lchild) != nullptr) {
        lval =findMaxRecursive(curr->lchild)->getInt();
    }
    if(findMaxRecursive(curr->rchild) != nullptr) {
        rval =findMaxRecursive(curr->rchild)->getInt();
    }
    
    if(lval > val && lval > rval) {
        return curr->lchild;
    }
    else if(rval > val && rval > lval) {
        return curr -> rchild;
    }
    return curr;
}
 */


void MyTree::makeBST() {
    if(root == nullptr || v.size() ==1 ) {
        return;
    }
    
    Node* node = new Node[v.size()];

    int i = 0;
    storeInorder(node,root, &i);
    //std::cout << std::endl;
    /*for(int i = 0; i < v.size(); ++i) {
        
        std::cout << node[i].value << " ";
    }*/
    //std::cout << std::endl << std::endl;
    
    /*for(int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i)->getInt() << " ";
    }*/
    
    std::sort(node, node+v.size());
    i = 0;
    makeBSTRecursive(node, root, &i);

}

void MyTree::storeInorder(Node* node, BinaryNode* curr,int *i) {
    if(curr ==nullptr) {
        return;
    }
    
    storeInorder( node,curr->lchild, i);
    //Node temp(curr->getInt(),curr->getString());
    //node[i] = temp;
    node[*i].value= curr->getInt();
    node[*i].aString= curr->getString();
    ++(*i);
    storeInorder(node,curr->rchild,i);
}

void MyTree::makeBSTRecursive(Node* node, BinaryNode* curr, int *i) {
    if(curr == nullptr)
        return;
    

    makeBSTRecursive(node, curr->lchild, i);
    curr->myInt = node[*i].value;
    curr->myString = node[*i].aString;
    ++(*i);
    makeBSTRecursive(node, curr->rchild, i);
}
