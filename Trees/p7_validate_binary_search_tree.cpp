#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

* The left subtree  of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

Link: https://leetcode.com/problems/validate-binary-search-tree/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBSTVerifier(TreeNode* root, long long min, long long max){
    if(root==NULL) return true;
    if(!(root->val>min && root->val<max)){
        return false;
    }
    return isValidBSTVerifier(root->left, min, root->val) 
    && isValidBSTVerifier(root->right, root->val, max);
}
bool isValidBST(TreeNode* root) {
    
    return isValidBSTVerifier(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout<<isValidBST(root)<<endl;
    return 0;
}