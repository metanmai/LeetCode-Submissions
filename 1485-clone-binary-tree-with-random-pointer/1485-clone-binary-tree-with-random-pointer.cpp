/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
private:
    NodeCopy *createCopyTree(Node *root, map<Node *, NodeCopy *> &visited)
    {
        if(!root)
            return NULL;
        
        if(visited.find(root) != visited.end())
            return visited[root];
        
        /* If you try to do visited[root] = new NodeCopy(val, cop(root->left), cop(root->right)),
           Then root is never marked as visited. So, we have to make*/
        visited[root] = new NodeCopy(root->val); 
        
        visited[root]->left = createCopyTree(root->left, visited);
        visited[root]->right = createCopyTree(root->right, visited);
        visited[root]->random = createCopyTree(root->random, visited);
        
        
        return visited[root];
    }
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {   
        map<Node *, NodeCopy *> visited;
        return createCopyTree(root, visited);
    }
};