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
    TreeNode *createBST(vector<int> &inorder, vector<int> &preorder, 
                        map<int, int> &indices,
                        int ileft, int iright, int pleft, int pright)
    {
        if(pleft > pright)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[pleft]);
        
        int idx = indices[root->val];
        int leftLen = idx - ileft, rightLen = iright - idx;
        
        root->left = createBST(inorder, preorder, indices,
                               ileft, idx - 1, pleft + 1, pleft + leftLen);
        root->right = createBST(inorder, preorder, indices,
                                idx + 1, iright, pright - rightLen + 1, pright);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int, int> indices; //{ele, index}.
        
        for(int i = 0; i < n; i++)
            indices[inorder[i]] = i;
        
        return createBST(inorder, preorder, indices, 0, n - 1, 0, n - 1);
    }
};