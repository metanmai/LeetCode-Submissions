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
    int maxLevelSum(TreeNode* root) {
        int currLvl = 1, maxSum = INT_MIN, maxSumLvl = 1;
        queue<TreeNode *> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            int currSum = 0;
            
            while(len--)
            {
                auto curr = q.front(); q.pop();
                
                currSum += curr->val;
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
            
            if(currSum > maxSum)
                maxSum = currSum, maxSumLvl = currLvl;
            
            currLvl++;
        }
        
        return maxSumLvl;
    }
};