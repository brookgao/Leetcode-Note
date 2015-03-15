//
//  list.h
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "../Header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//19.Remove Nth Node From End of List
ListNode *removeNthFromEnd(ListNode *head, int n);

//21.Merge Two Sorted Lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

//24.Swap Nodes in Pairs
ListNode *swapPairs(ListNode *head);

//25.Reverse Nodes in k-Group
ListNode *reverseKGroup(ListNode *head, int k);

//61.Rotate List
ListNode *rotateRight(ListNode *head, int k);

//82.Remove Duplicates from Sorted List II
ListNode *deleteDuplicates2(ListNode *head);

//83.Remove Duplicates from Sorted List
ListNode *deleteDuplicates(ListNode *head);

//86.Partition List
ListNode *partition(ListNode *head, int x);

//.92Reverse Linked List II
ListNode *reverseBetween(ListNode *head, int m, int n);

//141.Linked List Cycle
bool hasCycle(ListNode *head);

//142.Linked List Cycle II
ListNode *detectCycle(ListNode *head);

//160.Intersection of Two Linked Lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);