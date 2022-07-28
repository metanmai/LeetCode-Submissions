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
    vector<int> v;
    
    void preorder(TreeNode *root)
    {
        if(root)
        {
            v.push_back(root->val);
            flatten(root->left);
            preorder(root->right);
        }
    }
    
    void flatten(TreeNode* root) {
        if(root)
        {
            preorder(root);
            root->left = NULL;
            root->right = NULL;
            TreeNode*temp = root;
            for(int i = 1; i < v.size(); i++)
            {
                temp->right = new TreeNode();
                temp->right->val = v[i];
                temp = temp->right;
            }
        }
    }
};