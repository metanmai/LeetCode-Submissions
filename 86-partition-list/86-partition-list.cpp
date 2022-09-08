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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(), *h2 = new ListNode(), *temp = head;
        ListNode *t1 = h1, *t2 = h2;
        while(temp)
        {
            ListNode *node = new ListNode(temp->val);
            if(temp->val < x)
            {
                t1->next = node;
                t1 = t1->next;
            }
            else
            {
                t2->next = node;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        t1->next = h2->next;
        return h1->next;
    }
};