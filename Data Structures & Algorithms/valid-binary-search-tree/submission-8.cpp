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
    bool check(TreeNode* root, long long min, long long max) {
      if(!root) return true;
    
    return (min<root->val && root->val<max) && check(root->left, min, root->val)
            && check(root->right, root->val,max);

    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long min = LLONG_MIN;
        long long max = LLONG_MAX;
        return check(root, min, max);
    }
};
