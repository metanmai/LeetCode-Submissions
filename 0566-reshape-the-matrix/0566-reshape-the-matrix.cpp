class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), i1 = 0, j1 = 0;
        
        if(r * c != m * n)
            return mat;
        
        vector<vector<int>> answer(r, vector<int> (c));
        
        for(int i2 = 0; i2 < r; i2++)
            for(int j2 = 0; j2 < c; j2++)
            {
                answer[i2][j2] = mat[i1][j1++];
                
                if(j1 == n)
                    i1++, j1 = 0;
            }
        
        return answer;
    }
};