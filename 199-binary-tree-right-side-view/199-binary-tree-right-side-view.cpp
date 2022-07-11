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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> answer;
        while(!q.empty())
        {
            int l = q.size();
            vector<int> level;
            while(l--)
            {
                auto front = q.front();
                q.pop();
                if(front != NULL)
                {
                    level.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            
            if(level.size() > 0)
                answer.push_back(level.back());
        }
        return answer;
    }
};