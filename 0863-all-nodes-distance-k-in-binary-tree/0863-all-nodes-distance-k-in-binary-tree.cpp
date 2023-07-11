/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void traverse(map<TreeNode *, vector<TreeNode *>> &mp, 
                  TreeNode *root, TreeNode *prev)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            mp[root].push_back(root->left);
            traverse(mp, root->left, root);
        }
        
        if(root->right)
        {
            mp[root].push_back(root->right);
            traverse(mp, root->right, root);
        }
        
        if(prev)
            mp[root].push_back(prev);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        map<TreeNode *, vector<TreeNode *>> mp;
        
        traverse(mp, root, NULL);
        
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({target, NULL});
        int level = 0;
        
        while(!q.empty() and level <= k)
        {
            int len = q.size();
            
            while(len--)
            {
                auto [curr, prev] = q.front(); q.pop();
                
                if(level == k)
                {
                    answer.push_back(curr->val);
                    continue;
                }
                
                for(auto ele : mp[curr])
                    if(ele != prev)
                        q.push({ele, curr});
            }
            
            level++;
        }
        
        return answer;
    }
};