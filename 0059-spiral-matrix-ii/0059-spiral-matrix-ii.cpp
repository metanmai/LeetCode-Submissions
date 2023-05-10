class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int> (n));
        int lCol = 0, rCol = n - 1, uRow = 0, dRow = n - 1;
        int val = 0;
        
        while(true)
        {
            for(int j = lCol; j <= rCol; j++)
                answer[uRow][j] = ++val;
            
            if(val == n * n)
                break;
            
            uRow++;
            
            for(int i = uRow; i <= dRow; i++)
                answer[i][rCol] = ++val;
            
            if(val == n * n)
                break;
            
            rCol--;
            
            for(int j = rCol; j >= lCol; j--)
                answer[dRow][j] = ++val;
            
            if(val == n * n)
                break;
            
            dRow--;
            
            for(int i = dRow; i >= uRow; i--)
                answer[i][lCol] = ++val;
            
            if(val == n * n)
                break;
            
            lCol++;
        }
        
        return answer;
    }
};