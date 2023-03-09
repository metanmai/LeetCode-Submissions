/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode *slow = head, *fast = head->next;
        bool hasCycle = false;
        while(fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle)
            return NULL;
        ListNode *curr = head;
        
        slow = slow->next;
        while(curr != slow)
        {
            while(slow != fast)
            {
                slow = slow->next;
                if(slow == curr)
                    return curr;
            }
            slow = slow->next;
            curr = curr->next;
        }
        
        return curr;
    }
};