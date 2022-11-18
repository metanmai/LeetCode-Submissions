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
    int maxPath = INT_MIN;
    
    int pathSum(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int leftPathSum = pathSum(root->left);
        int rightPathSum = pathSum(root->right);
        
        leftPathSum = leftPathSum > 0 ? leftPathSum : 0;
        rightPathSum = rightPathSum > 0 ? rightPathSum : 0;
        
        int pathSum = root->val + leftPathSum + rightPathSum;
        
        maxPath = max(maxPath, pathSum);
        
        return max(pathSum - leftPathSum, pathSum - rightPathSum);
    }

public:
    // For every node, find max path sum to the left and max path sum to the right.
    
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxPath;
    }
};