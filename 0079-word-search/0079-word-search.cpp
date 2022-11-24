class Solution {
private:
    int m, n;
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    void findWord(vector<vector<char>> &board, vector<vector<bool>> &visited, 
             string word, int x, int y, int i, bool &isWordPresent)
    {
        if(i == word.length())
        {
            isWordPresent = true;
            return;
        }
        
        if(x >= 0 and y >= 0 and
           x < m and y < n and
           !visited[x][y] and board[x][y] == word[i])
        {
            visited[x][y] = true;
            
            for(int k = 0; k < 4; k++)
                findWord(board, visited, word, 
                         x + dirs[k], y + dirs[k + 1], i + 1, isWordPresent);
            
            visited[x][y] = false;
        }
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        bool isWordPresent = false;
        vector<vector<bool>> visited(m, vector<bool> (n));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0])
                    findWord(board, visited, word, i, j, 0, isWordPresent);
        
        return isWordPresent;
                    
    }
};