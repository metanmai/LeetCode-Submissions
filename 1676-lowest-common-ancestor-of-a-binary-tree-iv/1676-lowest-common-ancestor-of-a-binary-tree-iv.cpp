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
    pair<TreeNode*, int> findLCA(TreeNode *root, set<TreeNode*> &findNodes)
    {
        if(!root)
            return {NULL, 0};
        
        auto [leftTree, leftCount] = findLCA(root->left, findNodes);
        auto [rightTree, rightCount] = findLCA(root->right, findNodes);
        
        if(leftCount == findNodes.size())
            return {leftTree, leftCount};
        
        if(rightCount == findNodes.size())
            return {rightTree, rightCount};
        
        if(leftCount + rightCount == findNodes.size())
            return {root, findNodes.size()};
        
        if(findNodes.find(root) != findNodes.end())
            return {root, leftCount + rightCount + 1};
        
        return {NULL, leftCount + rightCount};
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*> findNodes(nodes.begin(), nodes.end());
        
        return findLCA(root, findNodes).first;
    }
};