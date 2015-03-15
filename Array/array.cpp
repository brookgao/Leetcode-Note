//
//  array.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "array.h"


//1. Two Sum
vector<int> FindIndex(vector<int> &num_copy, int num_i, int num_j){
    vector<int> result;
    vector<int>::size_type count = num_copy.size();
    int index1 = 0, index2 = 0;
    int flag1 = 0,flag2=0;
    
    for(int i =0; i<count;i++){
        if(index1 == 0){
            if(num_copy[i] == num_i){
                index1 = 1;
            } else{
                flag1++;
            }
        }
        if(index2 == 0) {
            if ((num_copy[i] == num_j)&& flag1!= flag2){
                index2 = 1;
            } else {
                flag2++;
            }
        }
        if((index1 && index2)== 1){
            break;
        }
    }
    int temp;
    if(flag1 > flag2){
        temp = flag2;
        flag2 = flag1;
        flag1 = temp;
    }
    result.push_back(flag1+1);
    result.push_back(flag2+1);
    return result;
}

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    vector<int> num_copy(numbers);
    vector<int>::size_type count = numbers.size();
    sort(numbers.begin(),numbers.end());
    
    for(int i=0, j=int(count-1); i<j;){
        auto sum = numbers[i]+numbers[j];
        if(sum == target){
            result = FindIndex(num_copy, numbers[i], numbers[j]);
            return result;
        }else if(sum > target)
            j--;
        else
            i++;
    }
    return result;
}


//11.Container With Most Water
int maxArea(vector<int> &height) {
    int left = 0, right = int(height.size())-1;
    int max_A = (right-left)*min(height[left],height[right]);
    
    while(left < right){
        if(height[left]<height[right]){
            left++;
            if(height[left]>height[left-1])
                max_A = max(max_A,(right-left)*min(height[left],height[right]));
        }else{
            right--;
            if(height[right]>height[right+1])
                max_A = max(max_A,(right-left)*min(height[left],height[right]));
        }
        
    }
    return max_A;
}

//26.Remove Duplicates from Sorted Array
int removeDuplicates(int A[], int n) {
    int p =0;
    
    if (n==0)
        return 0;

    for(int i=1;i<n;i++){
        if(A[p] != A[i]){
            p++;
            A[p] = A[i];
        }
    }
    return p+1;
}

//27.Remove Element
int removeElement(int A[], int n, int elem) {
    int j = 0;
    
    for(int i =0;i<n;i++){
        while(A[i] == elem && i<n)
            i++;
        if(i<n)
            A[j++] = A[i];
    }
    return j;
}

//35.Search Insert Position
int searchInsert(int A[], int n, int target) {
    int mid;
    int index = 0;
    bool find = false;
    int i = 0, j = n-1;
    
    while(i <= j) {
        mid = (i + j) / 2;
        if (target > A[mid]) {
            i = mid + 1;
        } else if (target < A[mid]) {
            j = mid - 1;
        } else if (target == A[mid]) {
            index = mid;
            find = true;
            break;
        }
    }
    
    if(find == false)
        index = i;
    
    return index;
}

//66.Plus One
vector<int> plusOne(vector<int> &digits) {
    auto end = digits.end()-1;
    bool flag = false;
    
    while(end != digits.begin()-1) {
        
        if (*end == 9) {
            *end = 0;
            if(end == digits.begin()){
                *end = 1;
                digits.push_back(0);
                break;
            }
            end--;
        } else {
            *end += 1;
            flag = true;
            break;
        }
    }
    
    return digits;
}

//80.Remove Duplicates from Sorted Array II
int removeDuplicates2(int A[], int n) {
    int dup = 0;
    int p =0;
    
    if(n==0)
        return 0;
    
    for(int i=1;i<n;i++){
        if(A[i] != A[p]){
            p++;
            A[p] = A[i];
            dup = 0;
        }else{
            dup++;
            if(dup == 1){
                p++;
                A[p] = A[i];
            }
        }
    }
    return p+1;
}

//88.Merge Sorted Array
void merge(int A[], int m, int B[], int n) {
    for(int j=0;j<n;j++) {
        for (int i = 0; i < m; i++) {
            if (A[i] >= B[j]) {
                int tmp;
                tmp = A[i];
                A[i] = B[j];
                B[j] = tmp;
            }
        }
        A[m++] = B[j];
    }
}

//118.Pascal's Triangle
vector<vector<int> > generate(int numRows) {
    vector<int> last = {1};
    vector<vector<int>> triangle;
    if(numRows < 1){
        return triangle;
    }else{
        triangle.push_back(last);
    }
    
    for(int i = 1;i<numRows;i++){
        vector<int> tmp;
        for(auto iter = last.begin();iter <= last.end();iter++){
            if(iter == last.begin()){
                tmp.push_back(1);
            }else if(iter == last.end()){
                tmp.push_back(1);
            }else{
                tmp.push_back(*iter+*(iter-1));
            }
        }
        last = tmp;
        triangle.push_back(tmp);
    }
    return triangle;
}

//119.Pascal's Triangle II
vector<int> getRow(int rowIndex) {
    vector<int> last={1};
    if(rowIndex < 1){
        return last;
    }
    
    for(int i = 1;i<rowIndex+1;i++){
        vector<int> tmp;
        for(auto iter = last.begin();iter <= last.end();iter++){
            if(iter == last.begin()){
                tmp.push_back(1);
            }else if(iter == last.end()){
                tmp.push_back(1);
            }else{
                tmp.push_back(*iter+*(iter-1));
            }
        }
        last = tmp;
    }
    
    return last;
}

//121.Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices) {
    int maxprofit=0;
    int minprice = INT32_MAX;
    auto count = prices.size();
    
    for(int i=0;i<count;i++){
        minprice = prices[i]<minprice?prices[i]:minprice;
        maxprofit = (prices[i]-minprice)>maxprofit?prices[i]-minprice:maxprofit;
    }
    return maxprofit;
}

