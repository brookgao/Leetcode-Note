//
//  tree.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "tree.h"

//100.Same Tree
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p&&q){
        if(p->val == q->val)
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        else
            return false;
    }else if(!p&&!q){
        return true;
    }
    return false;
}

//101.Symmetric Tree
bool helper(TreeNode *p, TreeNode *q){
    if (!p&&!q)
        return true;
    else if(!p||!q)
        return false;
    
    if (p->val!=q->val)
        return false;
    
    return helper(p->left, q->right)&&helper(p->right, q->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root)
        return true;
    return helper(root->left, root->right);
}


//104.Maximum Depth of Binary Tree
int maxDepth(TreeNode *root) {
    int depth = 0;
    if(root){
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        depth = l_depth>=r_depth?l_depth+1:r_depth+1;
    }
    return depth;
}

//110.Balanced Binary Tree
int getDepth(TreeNode *T){
    int depth = 0;
    if (T){
        int lDepth = getDepth(T->left);
        int rDepth = getDepth(T->right);
        if(abs(lDepth-rDepth)>1||lDepth == -1||rDepth == -1)
            return -1;
        depth = lDepth >=rDepth?lDepth+1:rDepth+1;
    }
    return depth;
}

bool isBalanced(TreeNode *root) {
    int depth = 0;
    bool balance = true;
    depth = getDepth(root);
    if(depth == -1)
        balance = false;
    return balance;
}

//



