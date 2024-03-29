/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

/*
Keep rolling back p and q to their parents. Then one of them visits a node that has already
been visited, that must be the LCA so we return that.
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        unordered_set<Node*> visited;
        
        while(p or q)
        {
            if(p == q)
                return p;
            
            if(visited.find(p) != visited.end())
                return p;
            
            if(visited.find(q) != visited.end())
                return q;
            
            if(p)
            {
                visited.insert(p);
                p = p->parent;
            }
            
            if(q)
            {
                visited.insert(q);
                q = q->parent;
            }
        }
        
        return NULL;
    }
};