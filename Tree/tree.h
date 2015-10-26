//
//  tree.h
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "../Header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void CreateBiTree(TreeNode* &T);
void PreOrderTraverse(TreeNode *T);

//100.Same Tree
bool isSameTree(TreeNode *p, TreeNode *q);

//101.Symmetric Tree
bool isSymmetric_R(TreeNode *root);
bool isSymmetric_I(TreeNode *root);

//104.Maximum Depth of Binary Tree
int maxDepth(TreeNode *root);

//110.Balanced Binary Tree
bool isBalanced(TreeNode *root);

//111.Minimum Depth of Binary Tree
int minDepth(TreeNode* root);

//112.Path Sum
bool hasPathSum(TreeNode *root, int sum);

//113.Path Sum II
vector<vector<int> > pathSum(TreeNode *root, int sum);