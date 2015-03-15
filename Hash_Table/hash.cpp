//
//  hash.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "hash.h"

//136.Single Number
int singleNumber(int A[], int n) {
    int a=0;
    for(int i=0;i<n;i++) {
        a ^= A[i];
    }
    return a;
}

