class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat1[0].size(), p = mat2[0].size();
        vector<vector<int>> answer(m, vector<int> (p));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < p; j++)
                for(int k = 0; k < n; k++)
                    answer[i][j] += mat1[i][k] * mat2[k][j];
        
        return answer;
    }
};