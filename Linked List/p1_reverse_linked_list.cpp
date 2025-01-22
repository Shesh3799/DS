#include <bits/stdc++.h>
using namespace std;

/*

Given the head of a singly linked list, reverse the list, and return the reversed list.

Link: https://leetcode.com/problems/reverse-linked-list/description/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    if(head==NULL)
    return NULL;
    if(head->next == NULL){
        
        return head;;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = head->next;

    while (curr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next)
        next = next->next;
    }
    return prev;
}

void displayLL(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++){
        temp -> next = new ListNode(arr[i]);
        temp=temp->next;
    }
    cout<<"Before Reverse LL is : ";
    displayLL(head);
    head = reverseList(head);
    cout<<"After reverse LL is : ";
    displayLL(head);
    return 0;
}