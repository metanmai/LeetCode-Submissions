/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool checkVals(vector<vector<int>> &grid, int row, int col, int side)
    {
        int val = grid[row][col];
        
        for(int i = 0; i < side; i++)
            for(int j = 0; j < side; j++)
                if(grid[row + i][col + j] != val)
                    return false;
        
        return true;
    }
    
    Node *quadTree(vector<vector<int>> &grid, int row, int col, int side)
    {
        Node *root = new Node();
        if(checkVals(grid, row, col, side))
        {
            root->isLeaf = true;
            root->val = grid[row][col];
        }
        
        else
        {
            root->topLeft = quadTree(grid, row, col, side / 2);
            root->topRight = quadTree(grid, row, col + side / 2, side / 2);
            root->bottomLeft = quadTree(grid, row + side / 2, col, side / 2);
            root->bottomRight = quadTree(grid, row + side / 2, col + side / 2, side / 2);
        }
        
        return root;
    }  
    
public:
    Node* construct(vector<vector<int>>& grid) {
        return quadTree(grid, 0, 0, grid.size());
    }
};