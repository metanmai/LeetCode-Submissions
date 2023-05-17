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
    int pairSum(ListNode* head) {
        int maxVal = 0;
        ListNode *temp = head;
        stack<int> st;
        
        int len = 0;
        
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        
        temp = head;
        for(int i = 1; i <= len / 2; i++)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        
        while(temp)
        {
            int curr = st.top(); st.pop();
            
            maxVal = max(maxVal, temp->val + curr);
            temp = temp->next;
        }
        
        return maxVal;
    }
};