//
//  main.cpp
//  comp
//
//  Created by gumus on 28.02.2019.
//  Copyright © 2019 mac. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string line;
    char file_name[]= "a_example.txt";
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            cout<<line+ "\n";
            
        }
    }else
        cout<<"not open ";
    
    int line_num=0;
  
    return 0;
}
