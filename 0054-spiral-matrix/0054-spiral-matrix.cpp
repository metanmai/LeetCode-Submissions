class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int lCol = 0, rCol = n - 1, uRow = 0, dRow = m - 1;
        vector<int> answer;
        
        while(true)
        {
            for(int j = lCol; j <= rCol; j++)
                answer.push_back(matrix[uRow][j]);
            
            if(answer.size() == m * n)
                break;
            
            uRow++;
            
            for(int i = uRow; i <= dRow; i++)
                answer.push_back(matrix[i][rCol]);
            
            if(answer.size() == m * n)
                break;
            
            rCol--;
            
            for(int j = rCol; j >= lCol; j--)
                answer.push_back(matrix[dRow][j]);
            
            if(answer.size() == m * n)
                break;
            
            dRow--;
            
            for(int i = dRow; i >= uRow; i--)
                answer.push_back(matrix[i][lCol]);
            
            if(answer.size() == m * n)
                break;
            
            lCol++;
        }
        
        return answer;
    }
};