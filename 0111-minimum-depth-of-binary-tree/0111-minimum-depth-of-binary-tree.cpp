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
private:
    int findMinDepth(TreeNode *root)
    {
        if(!root->left and !root->right)
            return 1;
        
        if(root->left and !root->right)
            return 1 + findMinDepth(root->left);
        
        else if(root->right and !root->left)
            return 1 + findMinDepth(root->right);
        
        else
            return 1 + min(findMinDepth(root->left), findMinDepth(root->right));
    }
    
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return findMinDepth(root);
    }
};