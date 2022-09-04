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
    map<int, vector<pair<int, int>>> vertical; // {column : vector<row, node_val>}
    
    void bfs(TreeNode *root)
    {
        queue<pair<pair<int, int>, TreeNode *>> q;
        q.push({{0, 0}, root});
        vertical[0].push_back({0, root->val});
        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                auto front = q.front();
                q.pop();
                int row = front.first.first + 1, col1 = front.first.second - 1, col2 = front.first.second + 1;
                TreeNode *leftNode = front.second->left, *rightNode = front.second->right;
                
                if(leftNode)
                {
                    q.push({{row, col1}, leftNode});
                    vertical[col1].push_back({row, leftNode->val});
                }
                if(rightNode)
                {
                    q.push({{row, col2}, rightNode});
                    vertical[col2].push_back({row, rightNode->val});
                }
            }
        }
    }
    
    vector<int> sortedRow(vector<pair<int, int>> column)
    {
        vector<int> temp;
        sort(column.begin(), column.end());
        for(int i = 0; i < column.size(); i++)
            temp.push_back(column[i].second);
        
        return temp;
            
    }
                       
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        bfs(root);
        for(auto i = vertical.begin(); i != vertical.end(); i++)
            answer.push_back(sortedRow(i->second));
        return answer;
    }
};