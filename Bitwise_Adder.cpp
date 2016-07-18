//
//  main.cpp
//  bitwise_adder
//
//  Created by Henry Zhou on 2016-07-18.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;



int adder(int a, int b){
    
    //Digits used for calculation
    int lastbit_a, lastbit_b;
    int carry = 0;
    //Result and keep track of the loops
    int result = 0;
    int loop = 0;
    
    if (a % 2 == 0) lastbit_a = 0;
    else            lastbit_a = 1;
    if (b % 2 == 0) lastbit_b = 0;
    else            lastbit_b = 1;
    
    while (a != 0 || b != 0 || carry != 0){
        
        //Find out the sum bit and the carry bit
        int digit = lastbit_a ^ lastbit_b ^ carry;
        carry = (lastbit_a & lastbit_b) | (carry & (lastbit_a ^ lastbit_b));
        
        //Accumulate on the result
        result += digit * (int) (pow(2.0, loop));
        
        //Update on the bits
        a = a >> 1;
        b = b >> 1;
        if (a % 2 == 0) lastbit_a = 0;
        else            lastbit_a = 1;
        if (b % 2 == 0) lastbit_b = 0;
        else            lastbit_b = 1;
        
        loop = loop + 1;
        
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < 100; i++){
        int a = rand() % 100;
        int b = rand() % 100;
        if (a + b != adder(a, b)){
            cout << "oops! " << a << " " << b << endl;
        }
        else cout << "Pass" << endl;
    }
        
    return 0;
}
