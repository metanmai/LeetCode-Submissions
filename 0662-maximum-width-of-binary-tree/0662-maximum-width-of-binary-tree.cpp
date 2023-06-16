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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int maxWidth = 1;
        
        while(!q.empty())
        {
            int len = q.size(), lenn = len;
            int firstVal = q.front().second;
            int leftPos = -1, rightPos = -1;
            
            while(len--)
            {
                auto [currNode, currPos] = q.front(); q.pop();
                currPos -= firstVal + 1; // Without this step, there will be an integer overflow.
                
                if(len == lenn - 1)
                    leftPos = currPos;
                
                rightPos = currPos;
                
                if(currNode->left)
                    q.push({currNode->left, 2LL * currPos});
                
                if(currNode->right)
                    q.push({currNode->right, 2LL * currPos + 1});
            }
            
            maxWidth = max(maxWidth, rightPos - leftPos + 1);
        }
        
        return maxWidth;
    }
};