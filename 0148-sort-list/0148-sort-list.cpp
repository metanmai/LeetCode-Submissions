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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        
        while(curr)
        {
            pq.push({curr->val, curr});
            curr = curr->next;
        }
        
        curr = pq.top().second, newHead = curr;
        pq.pop();
        
        while(!pq.empty())
        {
            curr->next = pq.top().second, pq.pop();
            curr = curr->next;
        }
        
        curr->next = NULL;
        
        return newHead;
    }
};