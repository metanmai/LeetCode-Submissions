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
    void findVal(TreeNode *root, int currVal, int &sum)
    {
        int temp = currVal * 10 + root->val;
        
        if(root->left) findVal(root->left, temp, sum);
        if(root->right) findVal(root->right, temp, sum);

        if(!root->left and !root->right) sum += temp;
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        findVal(root, 0, sum);
        return sum;
    }
};