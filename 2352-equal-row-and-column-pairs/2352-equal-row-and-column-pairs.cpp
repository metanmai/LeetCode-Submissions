class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int answer = 0;
        map<vector<int>, int> rows;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> row(n);
            
            for(int j = 0; j < n; j++)
                row[j] = grid[i][j];
            
            rows[row]++;
        }
        
        for(int j = 0; j < n; j++)
        {
            vector<int> col(n);
            
            for(int i = 0; i < n; i++)
                col[i] = grid[i][j];
            
            if(rows.find(col) != rows.end())
                answer += rows[col];
        }
        
        return answer;
    }
};