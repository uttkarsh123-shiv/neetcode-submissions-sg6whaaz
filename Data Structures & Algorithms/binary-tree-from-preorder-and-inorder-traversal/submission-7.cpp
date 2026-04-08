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

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &i, int start, int end
, unordered_map<int,int> &mp){
    if(start>end){
        return nullptr;
    }

    int rootVal = preorder[i++];

    TreeNode* root = new TreeNode(rootVal);

    int index=mp[rootVal];

    root->left = build(preorder, inorder, i, start, index-1, mp);
    root->right = build(preorder, inorder, i, index+1, end, mp);

    return root;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        int i = 0;

        return build(preorder, inorder, i, 0, inorder.size()-1, mp);
    }
};
