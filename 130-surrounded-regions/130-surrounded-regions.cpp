class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs(vector<vector<char>> &board, vector<vector<int>> &currIsland, int x, int y, int m, int n)
    {
        if(x < 0 or y < 0 or 
           x >= m or y >= n or
           board[x][y] == 'X' or currIsland[x][y] == 1)
            return;

        currIsland[x][y] = 1;
        for(auto dir : directions)
            dfs(board, currIsland, x + dir[0], y + dir[1], m, n);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> currIsland(m, vector<int> (n, 0));
        
        // Only perform DFS for the boundary islands, then capture all the inner islands.
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
                dfs(board, currIsland, 0, j, m, n);

            if(board[m - 1][j] == 'O')
                dfs(board, currIsland, m - 1, j, m, n);
        }

        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                    dfs(board, currIsland, i, 0, m, n);
            
            if(board[i][n - 1] == 'O')
                    dfs(board, currIsland, i, n - 1, m, n);
        }
        
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!currIsland[i][j] == 1 and board[i][j] == 'O')
                    board[i][j] = 'X';
    }
};