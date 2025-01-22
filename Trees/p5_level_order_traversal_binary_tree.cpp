#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root)return {};
    vector<vector<int>> res;
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()){
        int sz = q.size();
        vector<int>tmp;
        while(sz--){
            auto tp = q.front();
            q.pop();
            tmp.push_back(tp->val);
            if(tp->left){
                q.push(tp->left);
            }
            if(tp->right){
                q.push(tp->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}

int main() {
    

    return 0;
}