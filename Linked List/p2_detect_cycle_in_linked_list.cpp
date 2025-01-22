#include <bits/stdc++.h>
using namespace std;

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Link: https://leetcode.com/problems/linked-list-cycle/

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(fast==NULL || fast->next == NULL) return false;
        return true;
        
    }

int main() {
    ListNode* head = new ListNode(1);
    vector<int> arr = {1,2,3,4,5};
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++){
        temp -> next = new ListNode(arr[i]);
        temp=temp->next;
    }
    

    cout<< "Does cycle exists : "<<hasCycle(head)<<endl;

    temp->next = head;

    cout<< "Does cycle exists : "<<hasCycle(head)<<endl;

    return 0;
}