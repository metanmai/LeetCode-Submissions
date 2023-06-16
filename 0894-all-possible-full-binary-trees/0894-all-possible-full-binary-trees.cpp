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
    vector<TreeNode *> allFullTrees(unordered_map<int, vector<TreeNode *>> &fullTrees, int n)
    {
        if(fullTrees.find(n) != fullTrees.end())
            return fullTrees[n];
        
        for(int i = 1; i <= n - 1; i += 2)
        {
            auto leftTrees = allFullTrees(fullTrees, i);
            auto rightTrees = allFullTrees(fullTrees, n - 1 - i);
            
            for(auto left : leftTrees)
                for(auto right : rightTrees)
                    fullTrees[n].push_back(new TreeNode(0, left, right)); // You MUST push_back a new TreeNode, because this must be a deep copy.
        }
        
        return fullTrees[n];
    }
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0)
            return {};
        
        unordered_map<int, vector<TreeNode *>> fullTrees;
        fullTrees[1] = {new TreeNode};
        
        return allFullTrees(fullTrees, n);
    }
};