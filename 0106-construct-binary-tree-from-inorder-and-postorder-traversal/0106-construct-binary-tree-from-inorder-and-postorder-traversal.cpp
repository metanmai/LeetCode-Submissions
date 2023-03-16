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
    TreeNode *createBST(vector<int> &inorder, vector<int> &postorder, 
                        int ileft, int iright, int pleft, int pright)
    {
        if(pleft > pright)
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[pright]);
        
        int idx = -1;
        for(int k = ileft; k <= iright; k++)
            if(inorder[k] == root->val)
                idx = k;
        
        int leftLen = idx - ileft, rightLen = iright - idx;
        
        root->left = createBST(inorder, postorder, 
                               ileft, idx - 1, pleft, pleft + leftLen - 1);
        root->right = createBST(inorder, postorder, 
                                idx + 1, iright, pright - rightLen, pright - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return createBST(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};