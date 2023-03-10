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
    ListNode *head;
    int n;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        n = 0;
        ListNode *temp = head;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
    }
    
    int getRandom() {
        int num = rand() % n;
        int curr = 0;
        ListNode *temp = head;
        
        while(temp and curr != num)
        {
            temp = temp->next;
            curr++;
        }
        
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */