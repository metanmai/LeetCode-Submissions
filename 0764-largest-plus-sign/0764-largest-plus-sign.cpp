class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int answer = 0;
        vector<vector<int>> left(n, vector<int> (n)), right(n, vector<int> (n)), up(n, vector<int> (n)), down(n, vector<int> (n)), matrix(n, vector<int> (n, 1));
        
        for(auto mine : mines)
            matrix[mine[0]][mine[1]] = 0;
        
        for(int i = 0; i < n; i++)
        {
            int leftOnes = 0, rightOnes = 0;
            
            for(int j = 0; j < n; j++)
            {
                left[i][j] = leftOnes;
                
                if(matrix[i][j] == 1)
                    leftOnes++;
                
                else
                    leftOnes = 0;
            }
            
            for(int j = n - 1; j >= 0; j--)
            {
                right[i][j] = rightOnes;
                
                if(matrix[i][j] == 1)
                    rightOnes++;
                
                else
                    rightOnes = 0;
            }
        }
        
        for(int j = 0; j < n; j++)
        {
            int upOnes = 0, downOnes = 0;
            
            for(int i = 0; i < n; i++)
            {
                up[i][j] = upOnes;
                
                if(matrix[i][j] == 1)
                    upOnes++;
                
                else
                    upOnes = 0;
            }
            
            for(int i = n - 1; i >= 0; i--)
            {
                down[i][j] = downOnes;
                
                if(matrix[i][j] == 1)
                    downOnes++;
                
                else
                    downOnes = 0;
            }
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 1)
                answer = max(answer, 1 + min(min(left[i][j], right[i][j]), 
                                             min(up[i][j], down[i][j])));
        
        return answer;
    }
};