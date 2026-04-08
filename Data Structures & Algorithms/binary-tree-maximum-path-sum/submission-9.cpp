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
public:
    pair<int,int> solve(TreeNode* root){
      if(!root) return {0,INT_MIN};

      auto left = solve(root->left);
      auto right = solve(root->right);

      int leftgain = max(0, left.first);
      int rightgain = max(0, right.first);

      int sum = leftgain+rightgain+root->val;

        int gainup = root->val + max(leftgain, rightgain);

    int best = max({sum, left.second, right.second});
    // int maxsum = max({maxsum, sum, leftgain, rightgain});
    return {gainup, best};

    }

    int maxPathSum(TreeNode* root) {
        return solve(root).second;
    }
};
