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
    priority_queue<int> pq;
    
    void findKthSmallest(TreeNode *root, int k)
    {
        if(!root)
            return;
        
        pq.push(root->val);
        
        if(pq.size() > k)
            pq.pop();
        
        findKthSmallest(root->left, k);
        findKthSmallest(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        findKthSmallest(root, k);
        
        return pq.top();
    }
};