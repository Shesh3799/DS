#include <bits/stdc++.h>
using namespace std;

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as 
the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

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
    if(root==p || root==q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //If my left and right returns p/q then I'm LCA
    if(left && right){
        return root;
    }

    return left?left:right;
}

int main() {    
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout<<lowestCommonAncestor(root, root->left, root->right)->val<<endl;

    return 0;
}