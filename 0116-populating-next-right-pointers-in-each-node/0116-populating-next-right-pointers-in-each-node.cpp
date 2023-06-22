/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            Node *nextNode = NULL;
            
            while(len--)
            {
                auto curr = q.front(); q.pop();
                
                curr->next = nextNode;
                nextNode = curr;
                
                if(curr->left)
                {
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }
        
        return root;
    }
};