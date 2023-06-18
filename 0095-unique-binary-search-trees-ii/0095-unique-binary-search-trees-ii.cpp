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
    vector<TreeNode *> allUniqueBSTs(int start, int end)
    {
        if(start > end)
            return {NULL};
        
        vector<TreeNode *> roots;
        
        for(int i = start; i <= end; i++)
        {
            auto leftTrees = allUniqueBSTs(start, i - 1);
            auto rightTrees = allUniqueBSTs(i + 1, end);
            
            for(auto left : leftTrees)
                for(auto right : rightTrees)
                    roots.push_back(new TreeNode(i, left, right));
        }
        
        return roots;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return allUniqueBSTs(1, n);
    }
};