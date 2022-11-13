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
    int getDecimalValue(ListNode* head) {
        int val = 0, len = 0;
        ListNode *temp = head;
        while(head)
        {
            len++;
            head = head->next;
        }
        
        while(temp)
        {
            val += temp->val * pow(2, --len);
            temp = temp->next;
        }
        
        return val;
    }
};