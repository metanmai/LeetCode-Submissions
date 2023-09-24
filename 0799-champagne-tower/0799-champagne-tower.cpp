class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curr(query_row + 1);
        curr[0] = poured;
        
        for(int i = 0; i < query_row; i++)
        {
            vector<double> next(i + 2);
            
            for(int j = 0; j <= i; j++)
            {
                double extra = curr[j] >= 1 ? curr[j] - 1 : 0;
                curr[j] = curr[j] >= 1 ? 1 : curr[j];
                next[j] += extra / 2.0, next[j + 1] += extra / 2.0;
            }
            
            curr = next;
        }
        
        return curr[query_glass] >= 1 ? 1 : curr[query_glass];
    }
};