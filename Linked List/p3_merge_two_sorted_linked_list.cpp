#include <bits/stdc++.h>
using namespace std;

/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    if(list1 == NULL || list2==NULL)
        return list1==NULL?list2:list1;
    
    ListNode* head = NULL;

    if(list1->val<list2->val){
        head=list1;
        list1=list1->next;
    }else{
        head=list2;
        list2=list2->next;
    }

    ListNode* temp=head;
    
    while(list1 && list2){
        if(list1->val<list2->val){
            head->next=list1;
            list1=list1->next;
        }else{
            head->next=list2;
            list2=list2->next;
        }
        head=head->next;
    }

    while(list1){
        head->next=list1;
        head=list1;
        list1=list1->next;
    }
    while(list2){
        head->next=list2;
        head=list2;
        list2=list2->next;
    }


    return temp;
}

void displayLL(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    vector<int> list1 = {1,2,4}, list2 = {1,3,4};
    
    //List 1
    ListNode* head1 = new ListNode(list1[0]);
    ListNode* temp = head1;
    for(int i=1;i<list1.size();i++){
        temp -> next = new ListNode(list1[i]);
        temp=temp->next;
    }

    //List 2
    ListNode* head2 = new ListNode(list2[0]);
    temp = head2;
    for(int i=1;i<list2.size();i++){
        temp -> next = new ListNode(list2[i]);
        temp=temp->next;
    }

    ListNode* sortedHead = mergeTwoLists(head1, head2);
    cout<<"After merging LL is : ";
    displayLL(sortedHead);
    return 0;
}