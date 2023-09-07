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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode *> s;
        left--, right--;
        ListNode *prev, *next, *temp = head;
        int i = 0;
        
        while(temp != NULL)
        {
            if(i == left - 1)
                prev = temp;
            
            if(i == right)
                next = temp->next;
            
            if(i >= left and i <= right)
                s.push(temp);
            
            i++;
            temp = temp->next;
        }
        
        if(prev == NULL)
        {
            head = s.top();
            s.pop();
            prev = head;
        }
        
        while(s.size() > 0)
        {
            prev->next = s.top();
            s.pop();
            prev = prev->next;
        }
        prev->next = next;
        
        return head;
    }
};