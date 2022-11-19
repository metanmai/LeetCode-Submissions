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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        map<int, map<int, multiset<int>>> vert; // {column : {level : nodes}}. {level : nodes} is used because we want to sort node values only for that particular level.
        
        queue<pair<TreeNode *, int>> q; // {node, column}
        q.push({root, 0});
        int level = 0;
        
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {
                auto cell = q.front();
                q.pop();

                TreeNode *curr = cell.first;
                int col = cell.second;
                
                vert[col][level].insert(curr->val);
                
                if(curr->left)
                    q.push({curr->left, col - 1});

                if(curr->right)
                    q.push({curr->right, col + 1});
            }
            
            level++;
        }
        
        for(auto column : vert)
        {
            vector<int> v;
            for(auto level : column.second)
                v.insert(v.end(), level.second.begin(), level.second.end());
            
            answer.push_back(v);
        }
        
        return answer;
    }
};