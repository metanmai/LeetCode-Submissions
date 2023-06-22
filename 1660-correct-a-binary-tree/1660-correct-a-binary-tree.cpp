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
    void fixTree(TreeNode *root, TreeNode *parent, char dir, set<TreeNode *> &visited)
    {
        if(!root)
            return;
        
        visited.insert(root);
        
        if(root->right and visited.find(root->right) != visited.end())
        {
            if(dir == 'l')
                parent->left = NULL;
            
            else
                parent->right = NULL;
            
            return;
        }
            
        fixTree(root->right, root, 'r', visited);
        fixTree(root->left, root, 'l', visited);
    }
    
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        set<TreeNode *> visited;
        
        fixTree(root, NULL, ' ', visited);
        return root;
    }
};