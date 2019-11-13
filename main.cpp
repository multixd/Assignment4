//
//  test.cpp
//  Assignment4
//
//  Created by Vincent Liang on 11/2/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include "MyTree.hpp"


using namespace std;
//Testing (you must implement yours for the perfomance studies)
int main() {

    MyTree t;
    int k = 0;
    
    cout << "Insert size of randomly generated list: ";
    cin >> k;
    cout << endl << endl;
    
    srand((unsigned)time(0));
    auto start = std::chrono::high_resolution_clock::now();
    
    for(int i=0; i<k; ++i){
        int j = rand()%100000;
        t.insert((j),std::to_string(j));
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    cout << "The average runtime to build tree on size of " << k << " is: " << duration.count();

    cout << endl << endl;

    start = std::chrono::high_resolution_clock::now();
    t.preorder();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
      cout << endl << endl;
    cout << "The average runtime to preorder tree on size of " << k << " is: " << duration.count();
    
    cout << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    cout << t.findMax()->getInt() << endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "The average runtime to find max on size of " << k << " is: " << duration.count();
    
    cout << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    t.makeBST();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "The average runtime to make BST on size of " << k << " is: " << duration.count();
    
    cout << endl;
    
     
    //t.preorder();
    return 0;
    
}
