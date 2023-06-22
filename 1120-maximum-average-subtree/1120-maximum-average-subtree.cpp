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
    double maxAvg;
    
    pair<long long, int> maxTreeAvg(TreeNode *root, double &maxAvg)
    {
        if(!root)
            return {0, 0};
        
        long long currTotalSum, currNumberOfNodes;
        double currAvg;
        
        auto [leftTotalSum, numberOfLeftNodes] = maxTreeAvg(root->left, maxAvg);
        auto [rightTotalSum, numberOfRightNodes] = maxTreeAvg(root->right, maxAvg);
        
        currTotalSum = root->val + leftTotalSum + rightTotalSum;
        currNumberOfNodes = numberOfLeftNodes + numberOfRightNodes + 1;
        currAvg = (double) currTotalSum / currNumberOfNodes;
        
        maxAvg = max(maxAvg, currAvg);
        
        return {currTotalSum, currNumberOfNodes};
    }
    
public:
    double maximumAverageSubtree(TreeNode* root) {
        maxTreeAvg(root, maxAvg);
        
        return maxAvg;
    }
};