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
    TreeNode *MBT(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int maxIndex = l;
        
        for(int i = l; i <= r; i++)
        {
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = MBT(nums, l, maxIndex - 1);
        root->right = MBT(nums, maxIndex + 1, r);
        
        return root;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return MBT(nums, 0, nums.size() - 1);
    }
};