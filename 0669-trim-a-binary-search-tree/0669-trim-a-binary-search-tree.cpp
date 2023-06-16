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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return NULL;
        
        auto left = trimBST(root->left, low, high);
        auto right = trimBST(root->right, low, high);
        
        if(root->val < low)
            return right;
        
        if(root->val > high)
            return left;
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};