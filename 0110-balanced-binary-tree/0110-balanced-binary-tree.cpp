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
    map<TreeNode*, int> heights;
    
public:
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        
        if(heights.count(root))
            return heights[root];
        
        else
            return heights[root] = 1 + max(height(root->left), height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        return abs(height(root->left) - height(root->right)) < 2 and 
            isBalanced(root->left) and isBalanced(root->right);
    }
};