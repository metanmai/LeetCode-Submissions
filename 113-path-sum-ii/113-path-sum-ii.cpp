class Solution {
public:
    vector<vector<int>> paths;
    void hasPathSum(TreeNode* root, int targetSum,vector<int> res) {
        if(not root)
            return;
        TreeNode *curr = root;
        if(curr)
        {
            res.push_back(root->val);
            if(curr->val == targetSum and not curr->left and not curr->right)
                paths.push_back(res);
            
            else
            {
                hasPathSum(curr->left, targetSum - curr->val,res);
                hasPathSum(curr->right, targetSum - curr->val,res);
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        hasPathSum(root,targetSum,res);
        return paths;
    }
};