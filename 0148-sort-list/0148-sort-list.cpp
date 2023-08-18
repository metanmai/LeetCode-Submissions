/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head)
            return NULL;
        
        ListNode *curr = head, *newHead;
        priority_queue<int, vector<int>, greater<>> pq;
        
        while(curr)
        {
            pq.push(curr->val);
            curr = curr->next;
        }
        
        curr = new ListNode(pq.top()), newHead = curr;
        pq.pop();
        
        while(!pq.empty())
        {
            curr->next = new ListNode(pq.top()), pq.pop();
            curr = curr->next;
        }
        
        ListNode *temp = newHead;
        
        return newHead;
    }
};