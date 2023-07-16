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
    ListNode* removeNodes(ListNode* head) {
        ListNode *curr = head;
        vector<ListNode *> st;
        
        while(curr)
        {
            while(st.size() > 0 and st.back()->val < curr->val)
                st.pop_back();
            
            st.push_back(curr);
            curr = curr->next;
        }
        
        st.push_back(NULL);
        
        for(int i = 0; i < st.size() - 1; i++)
            st[i]->next = st[i + 1];
        
        return st[0];
    }
};