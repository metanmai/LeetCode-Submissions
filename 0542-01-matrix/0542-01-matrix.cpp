class Solution {
private:
    struct cell
    {
        int x, y;
    };
    
    vector<int> dirs = {0, 1, 0, -1, 0};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n));
        queue<cell> q;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0)
                    q.push({i, j}), visited[i][j] = true;
        
        while(!q.empty())
        {
            cell curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nextRow = curr.x + dirs[i], nextCol = curr.y + dirs[i + 1];
                
                if(nextRow >= 0 and nextCol >= 0 and
                   nextRow < m and nextCol < n and
                   mat[nextRow][nextCol] != 0 and !visited[nextRow][nextCol])
                {
                    visited[nextRow][nextCol] = true;
                    mat[nextRow][nextCol] = mat[curr.x][curr.y] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }
        
        return mat;
    }
};