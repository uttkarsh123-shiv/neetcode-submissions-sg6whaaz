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
    int solve(TreeNode* root, long long &globalMax){
        if(!root) return 0;

        int leftgain = max(0, solve(root->left, globalMax));
        int rightgain = max(0,solve(root->right, globalMax));

        int niche_hi_answer_hai = root->val+leftgain+rightgain;

        globalMax = max(globalMax, (long long)(niche_hi_answer_hai));

        return max(leftgain, rightgain)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        long long globalMax=LLONG_MIN;

        solve(root, globalMax);

        return globalMax;
    }
};
