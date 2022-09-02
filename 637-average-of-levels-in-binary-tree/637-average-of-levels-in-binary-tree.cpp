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
    vector<double> averages; 
    
    void average(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int l = q.size();
            double sum = 0;
            for(int i = 0; i < l; i++)
            {
                auto front = q.front();
                q.pop();
                sum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            averages.push_back(sum / l);
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        average(root);
        return averages;
    }
};