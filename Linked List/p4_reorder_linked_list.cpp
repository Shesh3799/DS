#include <bits/stdc++.h>
using namespace std;

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Link: https://leetcode.com/problems/reorder-list/description/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach 1, Time O(N) and Space O(N)
void reorderList(ListNode* head) {
    vector<ListNode*> list;
    while(head){
        list.push_back(head);
        head=head->next;
    }
    if(list.size()==1) return;
    int low = 0;
    int high = list.size()-1;
    ListNode* prev=NULL;
    while(low<high){
        list[low]->next = list[high];
        if(prev!=NULL){
            prev->next=list[low];
        }
        prev=list[high];
        low++;
        high--;
    }
    if(list.size()%2==0)
        prev->next=nullptr;
    else{
        prev->next = list[low];
        prev->next->next = nullptr;
    }
    head=list[0];
}

//Approach 2, Time O(N) and Space O(1)
/*

Two pointer Approach Algorithm:

1. First let's take two pointers name it as half and temp . temp is faster than half by 1.
2. When temp reaches the end of linkedlsit half reaches the middle element .So this is how the linkedlist will get divided in two halfes 
as the center will become a dividing node .
3. Now reverse the second half .
4. After reversing the second half, merge the first half and second half.
*/

void reorderList_2(ListNode* head) {
    // base case : linkedlist is empty
    if (!head) return;
    
    // finding the middle with the help of two pointer approach
    ListNode *tmp = head, *half = head, *prev = NULL;
    while (tmp->next && tmp->next->next) {
        tmp = tmp->next->next;
        half = half->next;
    }
    
    // adding one bit in case of lists with even length
    if (tmp->next) half = half->next;
    
    // Now reverse the second half
    while (half) {
        tmp = half->next;
        half->next = prev;
        prev = half;
        half = tmp;
    }
    half = prev;
    
    // After reversing the second half, let's merge both the halfes
    while (head && half) {
        tmp = head->next;
        prev = half->next;
        head->next = half;
        half->next = tmp;
        head = tmp;
        half = prev;
    }
    
    // Base case : closing when we had even length arrays
    if (head && head->next) head->next->next = NULL;
}

int main() {
    

    return 0;
}