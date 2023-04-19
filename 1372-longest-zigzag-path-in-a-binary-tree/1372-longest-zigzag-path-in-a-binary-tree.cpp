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
    void findLongestZigZag(TreeNode *root, char prev, int currLen, int &maxLen)
    {
        if(!root)
            return;
        
        if(prev == 'R')
        {
            findLongestZigZag(root->left, 'L', currLen + 1, maxLen);
            findLongestZigZag(root->right, 'R', 1, maxLen);
        }
        
        else
        {
            findLongestZigZag(root->right, 'R', currLen + 1, maxLen);
            findLongestZigZag(root->left, 'L', 1, maxLen);
        }
        
        maxLen = max(maxLen, currLen);
    }
    
public:
    int longestZigZag(TreeNode* root) {
        int maxLen = 0;
        
        findLongestZigZag(root->left, 'L', 1, maxLen);
        findLongestZigZag(root->right, 'R', 1, maxLen);
        
        return maxLen;
    }
};