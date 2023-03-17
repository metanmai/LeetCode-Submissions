/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node *copyList(Node *head, map<Node *, Node *> &visited)
    {
        if(!head)
            return NULL;
        
        if(visited.find(head) != visited.end())
            return visited[head];
        
        visited[head] = new Node(head->val);
        
        visited[head]->next = copyList(head->next, visited);
        visited[head]->random = copyList(head->random, visited);
        
        return visited[head];
    }

public:
    Node* copyRandomList(Node* head) {
        map<Node *, Node *> visited;
        
        return copyList(head, visited);
    }
};