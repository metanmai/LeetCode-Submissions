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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;

        function<vector<int> (TreeNode *)> findMinDiff = [&] (TreeNode *root) -> vector<int>
        {
            if(!root->left and !root->right)
                return {root->val, root->val};

            vector<int> leftVals, rightVals;
            leftVals = rightVals = {root->val, root->val};

            if(root->left)
            {
                leftVals = findMinDiff(root->left);
                minDiff = min(minDiff, abs(leftVals[1] - root->val));
            }
            
            if(root->right)
            {
                rightVals = findMinDiff(root->right);
                minDiff = min(minDiff, abs(rightVals[0] - root->val));
            }

            return {leftVals[0], rightVals[1]};
        };

        findMinDiff(root);
        return minDiff;
    }
};