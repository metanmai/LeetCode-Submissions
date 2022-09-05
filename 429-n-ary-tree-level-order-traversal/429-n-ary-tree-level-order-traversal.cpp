/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        if(!root)
            return levels;
        
        queue<Node *> q;
        q.push(root);
        levels.push_back({root->val});
        while(!q.empty())
        {
            int l = q.size();
            vector<int> level;
            while(l--)
            {
                auto front = q.front();
                q.pop();
                for(int i = 0; i < front->children.size(); i++)
                    if(front->children[i])
                    {
                        q.push(front->children[i]);
                        level.push_back(front->children[i]->val);
                    }
            }
            
            if(level.size())
                levels.push_back(level);
        }
        
        return levels;
    }
};