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
 Vrishank's code
 */
class Solution {
public:
    vector<int> king(TreeNode *root, vector<int> &b)
    {
        if(root)
        {
            king(root->left , b);
            b.push_back(root->val);
            king(root->right , b);
        }
        return b;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return king(root, ans);
    }
};