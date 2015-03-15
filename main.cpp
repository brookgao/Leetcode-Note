//
//  main.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "Header.h"
#include "Tree/tree.h"


int main(int argc, const char * argv[]) {
    TreeNode *BiTree;
    CreateBiTree(BiTree);
    PreOrderTraverse(BiTree);
    cout<<std::endl;
    return 0;
}
