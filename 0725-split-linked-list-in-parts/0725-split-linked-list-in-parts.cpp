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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0, split, rem, count = 0;
        vector<ListNode*> parts;
        ListNode *curr = head, *part, *start = NULL, *prev;
        
        while(curr)
            n++, curr = curr->next;
        
        split = ceil((float) n / k);
        curr = head;
        
        while(curr or start)
        {
            if(count < split)
            {
                if(count == 0)
                    start = part = curr;
                
                else
                    part->next = curr, part = part->next;
                
                count++, n--;
                prev = curr;
                curr = curr->next;
            }
            
            else
            {
                parts.push_back(start);
                prev->next = NULL, start = NULL;
                count = 0, k--;
                
                if(k > 0)
                    split = ceil((float) n / k);
            }
        }
        
        while(k)
            parts.push_back(NULL), k--;
        
        return parts;
    }
};