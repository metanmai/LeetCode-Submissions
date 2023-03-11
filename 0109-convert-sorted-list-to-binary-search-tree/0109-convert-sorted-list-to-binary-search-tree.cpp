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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *makeBST(ListNode *head, int low, int high)
    {
        if(low > high or !head)
            return NULL;
        
        int pos = low, mid = (high + low) / 2;
        ListNode *temp = head;
        
        while(pos < mid and temp)
        {
            temp = temp->next;
            pos++;
        }
        
        TreeNode *root = new TreeNode(temp->val);
        root->left = makeBST(head, low, mid - 1);
        root->right = makeBST(temp->next, mid + 1, high);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *temp = head;
        
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        
        return makeBST(head, 0, len - 1);
    }
};