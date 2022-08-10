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
public:
    TreeNode* createBST(vector<int> nums, int l, int r)
    {
        // This is important to stop the recursive calls.
        if(l > r)
            return NULL;
        int mid = (l + r) / 2;
        if(mid < 0 or mid >= nums.size())
            return NULL;
        
        return new TreeNode(nums[mid],createBST(nums, l, mid - 1),createBST(nums, mid + 1, r));
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
};