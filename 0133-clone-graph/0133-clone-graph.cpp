/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node *clone(Node *node, map<int, Node*> &mp)
    {
        if(!node)
            return NULL;
        
        if(mp.find(node->val) != mp.end())
            return mp[node->val];
        
        mp[node->val] = new Node(node->val);
        
        for(auto ele : node->neighbors)
            mp[node->val]->neighbors.push_back(clone(ele, mp));
        
        return mp[node->val];
    }
    
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> mp;
        return clone(node, mp);
    }
};