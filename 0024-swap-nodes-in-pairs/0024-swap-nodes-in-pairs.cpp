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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        int temp;
        ListNode *even = head, *odd = head->next;
        while(odd != NULL)
        {
            temp = odd->val;
            odd->val = even->val;
            even->val = temp;
            
            even = odd->next;
            if(odd->next == NULL)
                break;
            odd = even->next;
        }
        
        return head;
    }
};