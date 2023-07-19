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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer;
        stack<pair<int, int>> st;
        ListNode *curr = head;
        int i = 0, n = 0;
        
        while(curr)
        {
            curr = curr->next;
            n++;
        }
        
        answer.resize(n);
        curr = head;
        
        while(curr)
        {
            while(!st.empty() and st.top().first < curr->val)
            {
                answer[st.top().second] = curr->val;
                st.pop();
            }
            
            st.push({curr->val, i});
            i++;
            curr = curr->next;
        }
        
        return answer;
    }
};