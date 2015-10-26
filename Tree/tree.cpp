//
//  tree.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "tree.h"

void CreateBiTree(TreeNode* &T){  //创建树
    int ch;
    cin>>ch;
    if(ch == 0)
        T = NULL;
    else{
        T = new TreeNode(ch);
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}

void PreOrderTraverse(TreeNode *T){   //前序遍历
    if (T == NULL)
        return;
    
    cout<<T->val<<", ";
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}

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
//Recurisive
bool helper(TreeNode *p, TreeNode *q){
    if (!p&&!q)
        return true;
    else if(!p||!q)
        return false;
    
    if (p->val!=q->val)
        return false;
    return helper(p->left, q->right)&&helper(p->right, q->left);
}

bool isSymmetric_R(TreeNode *root) {
    if (!root)
        return true;
    return helper(root->left, root->right);
}

//Iterative
bool isSymmetric_I(TreeNode *root) {
    if((!root)||(!root->left&&!root->right)){
        return true;
    }else if(root->right&&root->left){
        stack<TreeNode*> nodeStack1;
        stack<TreeNode*> nodeStack2;
        nodeStack1.push(root->left);
        nodeStack2.push(root->right);
        TreeNode *root1 = nullptr;
        TreeNode *root2 = nullptr;
        while (!nodeStack1.empty()&&!nodeStack2.empty()) {
            root1 = nodeStack1.top();
            root2 = nodeStack2.top();
            nodeStack1.pop();
            nodeStack2.pop();
            if (root1->val != root2->val)
                return false;
            
            if(root1->right&&root2->left){
                nodeStack1.push(root1->right);
                nodeStack2.push(root2->left);
            }else if((root1->right&&!root2->left)||(!root1->right&&root2->left)){
                return false;
            }
            
            if (root1->left&&root2->right){
                nodeStack1.push(root1->left);
                nodeStack2.push(root2->right);
            }else if((root1->left&&!root2->right)||(!root1->left&&root2->right)){
                return false;
            }
        }
        return true;
    }
    return false;
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

//111.Minimum Depth of Binary Tree
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left)
        return minDepth(root->right)+1;
    
    if (!root->right)
        return minDepth(root->left)+1;
    
    return std::min(minDepth(root->left), minDepth(root->right))+1;
}

//112.Path Sumtab

bool hasPathSum(TreeNode *root, int sum) {
    if (!root)
        return false;
    if (root->val == sum && !root->left&&!root->right)
        return true;
    return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
}

//113.Path Sum II
void helperPathSum(vector<vector<int>> &pathes, vector<int> path, TreeNode *root, int sum){
    if(!root)
        return;
    
    path.push_back(root->val);
    
    if (!root->left&&!root->right&&(root->val == sum)){
        pathes.push_back(path);
        return;
    }
    helperPathSum(pathes, path, root->left, sum-root->val);
    helperPathSum(pathes, path, root->right, sum-root->val);
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> pathes;
    vector<int> path;
    helperPathSum(pathes, path,root, sum);
    return pathes;
}


