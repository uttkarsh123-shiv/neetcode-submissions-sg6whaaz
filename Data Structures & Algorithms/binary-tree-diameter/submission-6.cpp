/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:// int maxDiameter =0;
    pair<int,int> solve(TreeNode* &root) {
        if(!root) return {0,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int height = 1+max(left.first, right.first);

        int diamterThroughRoot = left.first+right.first;

        int diameter = max({diamterThroughRoot, left.second, right.second});
    
        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
     return  solve(root).second;
    }
};
