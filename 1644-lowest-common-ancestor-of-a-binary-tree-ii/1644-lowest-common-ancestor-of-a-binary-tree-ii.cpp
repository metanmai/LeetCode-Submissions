/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
If the returned node is either p or q, perform a second pass and check if the other node is 
present as a subtree.
*/

class Solution {
private:
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root or root == p or root == q)
            return root;
        
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        
        if (left and right)
            return root;
        
        return left ? left : right;
    }

    bool search(TreeNode* node, TreeNode* target) {
        if (node == target)
            return true;
        
        if (!node)
            return false;
        
        return (
            search(node->left, target) or 
            search(node->right, target)
        );
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = findLCA(root, p, q);
        if(ans == p) // check if q is in the subtree of p
            return search(p, q) ? p : NULL;
        
        if(ans == q) // check if p is in the subtree of q
            return search(q, p) ? q : NULL;
        
        return ans;
    }
};