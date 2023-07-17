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
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *next = NULL;
        
        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = reverseList(l1), *head2 = reverseList(l2), *answer = new ListNode;
        ListNode *curr1 = head1, *curr2 = head2, *curr3 = answer;
        int carry = 0;
        
        while(curr1 or curr2 or carry)
        {
            int val1 = curr1 ? curr1->val : 0, val2 = curr2 ? curr2->val : 0;
            int nextVal = val1 + val2 + carry;
            carry = nextVal / 10;
            
            curr3->next = new ListNode(nextVal % 10);
            
            if(curr1)
                curr1 = curr1->next;
            
            if(curr2)
                curr2 = curr2->next;
            
            curr3 = curr3->next;
        }
        
        return reverseList(answer->next);
    }
};