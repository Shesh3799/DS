#include <bits/stdc++.h>
using namespace std;

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    
    //LCA lies on left sub tree
    if(root->val>p->val && root->val>q->val){
        return lowestCommonAncestor(root->left, p, q);
    //LCA lies on right sub tree
    } else if(root->val<p->val && root->val<q->val){
        return lowestCommonAncestor(root->right, p, q);
    } 
    //If my root is greater than left but less than right than I'm LCA
    return root;
    
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout<<lowestCommonAncestor(root, root->left, root->right)->val<<endl;
    return 0;
}