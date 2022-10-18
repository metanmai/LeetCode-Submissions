class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> zeroRows(m), zeroCols(n);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                    zeroRows[i] = 1, zeroCols[j] = 1;
        
        int setRowZeros = 0, setColZeros = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(zeroRows[i] or zeroCols[j])
                    matrix[i][j] = 0;
    }
};