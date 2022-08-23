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
    bool isPalindrome(ListNode* head) {
        struct ListNode *curr = head, *next = curr->next, *prev = NULL, *head2;
    
        vector<int> a;
        vector<int> b;
        int k = 0;

        while(curr != NULL)
        {
            a.push_back(curr->val);
            b.push_back(curr->val);
            curr = curr->next;
        }
        
        std::reverse(a.begin(), a.end());

        for(int i = 0; i < a.size() - 1; i++)
            if(a[i] != b[i])
                return false;

        return true;
    }
};