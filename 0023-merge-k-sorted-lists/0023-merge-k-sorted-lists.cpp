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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *head = new ListNode(), *temp = head;
        bool complete = false;
        
        while(!complete)
        {
            complete = true;
            int minVal = INT_MAX;
            int minNode = -1;
            
            for(int i = 0; i < k; i++)
            {
                if(lists[i] and lists[i]->val < minVal)
                {
                    complete = false;
                    minVal = min(minVal, lists[i]->val);
                    minNode = i;
                }
            }

            if(minNode != -1)
            {
                temp->next = new ListNode(minVal);
                temp = temp->next;
                lists[minNode] = lists[minNode]->next;
            }
        }
        
        return head->next;
    }
};