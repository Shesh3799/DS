#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Intuition: In order travesal will give sorted elements

Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrderTraversal(TreeNode* root, vector<int>& result){
    if(root==NULL) return;
    inOrderTraversal(root->left, result);
    result.push_back(root->val);
    inOrderTraversal(root->right, result);
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> result;
    inOrderTraversal(root, result);
    return result[k-1];
    
}

int main() {
    

    return 0;
}