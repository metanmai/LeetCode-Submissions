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
    bool isUniVal(TreeNode *root, int parentVal, int &count)
    {
        if(!root)
            return true;
        
        bool leftTree = isUniVal(root->left, root->val, count);
        bool rightTree = isUniVal(root->right, root->val, count);
        
        bool leftChild = root->left ? root->val == root->left->val : true;
        bool rightChild = root->right ? root->val == root->right->val : true;
        
        if(leftChild and rightChild and leftTree and rightTree)
        {
            count++;
            return true;
        }
        
        return false;
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        
        isUniVal(root, -1, count);
        return count;
    }
};