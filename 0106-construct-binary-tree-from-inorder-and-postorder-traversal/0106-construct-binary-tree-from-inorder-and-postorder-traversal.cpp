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
                        map<int, int> &indices,
                        int ileft, int iright, int pleft, int pright)
    {
        if(pleft > pright)
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[pright]);
        
        int idx = indices[root->val];
        int leftLen = idx - ileft, rightLen = iright - idx;
        
        root->left = createBST(inorder, postorder, indices,
                               ileft, idx - 1, pleft, pleft + leftLen - 1);
        root->right = createBST(inorder, postorder, indices,
                                idx + 1, iright, pright - rightLen, pright - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> indices; //{ele, index}.
        
        for(int i = 0; i < n; i++)
            indices[inorder[i]] = i;
        
        return createBST(inorder, postorder, indices, 0, n - 1, 0, n - 1);
    }
};