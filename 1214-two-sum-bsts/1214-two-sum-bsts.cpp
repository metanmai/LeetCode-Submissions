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
    bool searchForValue(TreeNode *root, int target)
    {
        if(!root)
            return false;
        
        if(root->val == target)
            return true;
        
        else if(root->val > target)
            return searchForValue(root->left, target);
        
        else
            return searchForValue(root->right, target);
    }
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1)
            return false;
        
        if(searchForValue(root2, target - root1->val))
            return true;
        
        return (twoSumBSTs(root1->left, root2, target) or
                twoSumBSTs(root1->right, root2, target));
    }
};