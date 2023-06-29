/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node *flattenedList(Node *head)
    {
        if(!head)
            return NULL;
        
        Node *temp = head, *lastNext = head->next;
        int val = head->val;
        
        if(head->child)
        {
            auto actualNext = flattenedList(head->child);
            head->next = actualNext;
            head->next->prev = head;
            head->child = NULL;
            
            while(temp->next)
                temp = temp->next;
        }
        
        temp->next = flattenedList(lastNext);
        
        return head;
    }
    
public:
    Node* flatten(Node* head) {
        Node *ans = flattenedList(head), *temp = ans, *prev = NULL;
        
        while(temp)
        {
            temp->child = NULL;
            temp->prev = prev;
            prev = temp;
            temp = temp->next;
        }
        
        return ans;
    }
};