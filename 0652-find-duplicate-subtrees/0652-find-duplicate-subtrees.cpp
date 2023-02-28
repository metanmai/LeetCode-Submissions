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
    string preorderTraversal(TreeNode *root, map<string, vector<TreeNode *>> &trees)
    {
        if(root)
        {
            string str = (to_string(root->val) + "," + 
                          preorderTraversal(root->left, trees) + "," +
                          preorderTraversal(root->right, trees));
            
            trees[str].push_back(root);
            
            return str;
        }
        
        return "N";
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> answer;
        map<string, vector<TreeNode *>> trees;
        
        preorderTraversal(root, trees);
        
        for(auto [_, ele] : trees)
            if(ele.size() > 1)
                answer.push_back(ele[0]);
        
        return answer;
    }
};