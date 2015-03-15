//
//  list.cpp
//  Leetcode
//
//  Created by GaoBrook on 15/3/15.
//  Copyright (c) 2015年 gao. All rights reserved.
//

#include "list.h"

//19.Remove Nth Node From End of List
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head;
    ListNode *slow = head;
    int count = 0;
    
    while (fast->next) {
        fast = fast->next;
        count++;
        if(count>n){
            slow = slow->next;
        }
    }
    
    if((slow == head)&&(n-count)){
        head = slow->next;
    }else{
        slow->next = slow->next->next;
    }
    
    return head;
}

//21.Merge Two Sorted Lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *main = new ListNode(0);
    ListNode *head = main;
    
    while (true) {
        if(!l2){
            main->next = l1;
            break;
        }
        if(!l1){
            main->next = l2;
            break;
        }
        if(l1->val < l2->val) {
            main->next = l1;
            main = l1;
            l1 = l1->next;
        }else{
            main->next = l2;
            main = l2;
            l2 = l2->next;;
        }
    }
    return head->next;
}


//24.Swap Nodes in Pairs
ListNode *swapPairs(ListNode *head) {
    if(!head)
        return head;
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *tmp = new ListNode(0);
    ListNode *newHead = (p2)?p2:p1;
    
    while (p1&&p2) {
        p1->next = p2->next;
        p2->next = p1;
        tmp->next = p2;
        tmp = p1;
        p1 = p1->next;
        if(!p1)
            break;
        p2 = p1->next;
    }
    
    return newHead;
}

//25.Reverse Nodes in k-Group
ListNode *reverseKGroup(ListNode *head, int k) {
    if(!head||k==1)
        return head;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *p1 = newHead;
    ListNode *p2;
    
    for (int i = k; i>0; i--) {
        p2 = p1;
        for (int j=0; j<i-1; j++){
            p2 = p2->next;
            if(!p2||!(p2->next))
                return newHead->next;
        }
        if (p1 != p2) {
            ListNode *change1 = p1->next;
            ListNode *change2 = p2->next;
            p1->next = change2;
            p2->next = change2->next;
            change2->next = change1;
        }else{
            i = k+1;
        }
        p1 = p1->next;
    }
    return newHead->next;
}

//61.Rotate List
ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
        return head;
    ListNode *newHead = new ListNode(0);
    ListNode *p1 = head;
    ListNode *p2 = head;
    int total = 0;
    while(p2->next){
        p2 = p2->next;
        total++;
    }
    k = k%(total+1);
    if(k==0)
        return head;
    
    for (int i =0; i<total-k; i++)
        p1 = p1->next;
    
    newHead->next = p1->next;
    p2->next = head;
    p1->next = NULL;
    
    return newHead->next;
}

//82.Remove Duplicates from Sorted List II
ListNode *deleteDuplicates2(ListNode *head) {
    ListNode *newHead = new ListNode(0);
    newHead->next = NULL;
    ListNode *p1 = newHead;
    ListNode *p2 = head;
    ListNode *prev = newHead;
    
    while(p2){
        if(p2==head||(p2->val != prev->val)){
            if (!p2->next||(p2->val != p2->next->val)) {
                p1->next = p2;
                p1 = p2;
            }
        }
        prev = p2;
        p2 = p2->next;
    }
    p1->next = p2;
    return newHead->next;
}

//83.Remove Duplicates from Sorted List
ListNode *deleteDuplicates(ListNode *head) {
    if (!head)
        return head;
    ListNode *p = head;
    ListNode *q = p->next;
    
    while (q&&p) {
        ListNode *copy = q;
        q = q->next;
        if( p->val == copy->val ){
            p->next = q;
            delete copy;
        }else{
            p = p->next;
        }
        
    }
    return head;
}


//86.Partition List
ListNode *partition(ListNode *head, int x) {
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *p1 = newHead;
    while (p1->next) {
        if((p1->next->val)<x)
            p1 = p1->next;  //find the beginning
        else
            break;
    }
    ListNode *p2 = p1;
    
    ListNode *nextOne;
    while (p2->next) {
        nextOne = p2->next;
        if (nextOne->val<x){
            p2->next = nextOne->next;
            nextOne->next = p1->next;
            p1->next = nextOne;
            p1 = p1->next;
        }else{
            p2 = p2->next;
        }
    }
    return newHead->next;
}


//.92Reverse Linked List II
ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *p1 = newHead;
    ListNode *p2;
    for (int i=0; i<m-1; i++) {
        p1 = p1->next;
    }
    
    for (int i = n-m; i>0; i--) {
        p2  = p1;
        for (int j = 0; j<i; j++)
            p2 = p2->next;
        ListNode *change1 = p1->next;
        ListNode *change2 = p2->next;
        p1->next = change2;
        p2->next = change2->next;
        change2->next = change1;
        
        p1=p1->next;
    }
    
    return newHead->next;
}

//141.Linked List Cycle
bool hasCycle(ListNode *head) {
    ListNode *end1 = head;
    ListNode *end2 = head;
    while (end1&&end2&&end2->next) {
        end1 = end1->next;
        end2 = end2->next->next;
        if (end1 == end2) {
            return true;
        }
    }
    return false;
}


//142.Linked List Cycle II
ListNode *detectCycle(ListNode *head) {
    if(!head||(!head->next))
        return NULL;
    
    ListNode *p1 = head;
    ListNode *p2 = head;
    
    while (p1&&p2&&p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
            break;
    }
    if (p1 != p2)
        return NULL;
    
    while (p1 != head) {
        p1 = p1->next;
        head = head->next;
    }
    return head;
}


//160.Intersection of Two Linked Lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    int countA = 0,countB = 0;
    
    while (pa) {
        pa = pa->next;
        countA++;
    }
    
    while (pb) {
        pb = pb->next;
        countB++;
    }
    
    pa = headA; pb = headB;
    
    if(countA<countB) {
        for(int i =0;i<countB-countA;i++)
            pb = pb->next;
    }else if(countA>countB){
        for(int i =0;i<countA-countB;i++)
            pa = pa->next;
    }
    
    while(pa&&pb){
        if (pa == pb)
            return pb;
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}
