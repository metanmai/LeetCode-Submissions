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
    bool hasCycle(ListNode *head) {
        ListNode *curr1 = head;
        if(curr1 == NULL)
            return false;
        
        ListNode *curr2 = curr1->next;
        
        while(curr2 != NULL && curr2->next != NULL)
        {
            if(curr1 == curr2)
                return true;
            
            curr2 = curr2->next->next;
            curr1 = curr1->next;
        }
        return false;
    }
};