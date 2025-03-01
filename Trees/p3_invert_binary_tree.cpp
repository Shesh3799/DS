#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Link: https://leetcode.com/problems/invert-binary-tree/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void invertHelper(TreeNode* root){
    if(root==NULL) return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertHelper(root->left);
    invertHelper(root->right);
}
TreeNode* invertTree(TreeNode* root) {
    if(root==NULL) return NULL;
    invertHelper(root);
    return root;
    
}
int main() {
    

    return 0;
}