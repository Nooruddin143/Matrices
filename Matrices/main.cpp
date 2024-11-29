//
//  main.cpp
//  Matrices
//
//  Created by Nooruddin Mohammadi on 9/20/24.
//

#include <iostream>
#include "Matrices.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Matrices::Matrix a(2, 2);
    Matrices::Matrix b(2, 4);
    Matrices::Matrix c(2, 4);
    a(0,0) = 0;
    a(0,1) = -1;
    a(1,0) = 1;
    a(1,1) = 0;
    
    b(0,0) = 1;
    b(0,1) = 0.866025;
    b(0,2) = 1;
    b(0,3) = 0.5;
    b(1,0) = 0;
    b(1,1) = 0.5;
    b(1,2) = 1;
    b(1,3) = 0.866025;
    
    c = a + b;
    
    
    cout << "a:" << endl;
    cout << a << endl;
    cout << "b:" << endl;
    cout << b << endl;
    
    cout << "c = b + b:" << endl;
    cout << b + b << endl;
    cout << "c = a * b:" << endl;
    cout << a * b << endl;
    
    
    
    return 0;
}
