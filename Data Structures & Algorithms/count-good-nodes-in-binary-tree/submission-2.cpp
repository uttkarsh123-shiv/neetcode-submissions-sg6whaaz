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
  int dfs(TreeNode* root, int maxVal){
    if(!root) return 0;
    int count=0;
    if(root->val >= maxVal)
    count++; 
    maxVal = max(maxVal, root->val);

    int leftcount = dfs(root->left, maxVal);
    int rightcount = dfs(root->right, maxVal);
    return count+leftcount+rightcount;
  }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxVal = root->val;
        return dfs(root, maxVal);

        // return count;
    }
};
