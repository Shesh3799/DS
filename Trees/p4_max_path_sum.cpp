#include <bits/stdc++.h>
using namespace std;

/*

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum = INT_MIN;
int maxPathSum(TreeNode* root) {
    if(root == NULL) return 0;

    max_path_sum_utility(root);
    return sum;

}

int max_path_sum_utility(TreeNode* root){
    if( root == NULL) return 0;
    int left = max_path_sum_utility(root->left);
    int right = max_path_sum_utility(root->right);
    sum = max(sum, root->val+left+right);
    sum = max(sum, root->val+ max(left,right));
    sum = max(sum, root->val);
    return max(root->val, root->val + max(left,right));
}

int main() {
    return 0;
}