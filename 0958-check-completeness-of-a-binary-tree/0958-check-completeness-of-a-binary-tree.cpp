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
    int heightOfTree(TreeNode *root)
    {
        if(!root)
            return 0;
        
        return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
    }
    
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        
        int level = 1, height = heightOfTree(root);
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty())
        {
            if(level == height)
                break;
            
            int len = q.size();
            bool nullFound = false;
            
            while(len--)
            {
                auto curr = q.front(); q.pop();
                
                if(curr->left and curr->right)
                {
                    if(nullFound)
                        return false;
                    
                    q.push(curr->left);
                    q.push(curr->right);
                }
                
                else if(level == height - 1)
                {
                    if(curr->right)
                        return false;
                    
                    if(curr->left)
                    {
                        if(nullFound)
                            return false;
                        
                        q.push(curr->left);
                    }
                    
                    nullFound = true;
                }
                
                else 
                    return false;
            }
            
            level++;
        }
        
        return true;
    }
};