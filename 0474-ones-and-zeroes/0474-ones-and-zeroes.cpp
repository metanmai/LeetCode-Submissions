class Solution {
private:
    int findOnesAndZeroes(vector<vector<vector<int>>> &dp, vector<vector<int>> &counts, 
                          int m, int n, int i, int len)
    {
        if(i == len)
            return 0;
        
        if(dp[m][n][i] != -1)
            return dp[m][n][i];
        
        int take = 0, notTake = 0;
        
        if(m - counts[i][0] >= 0 and n - counts[i][1] >= 0)
            take = 1 + findOnesAndZeroes(dp, counts, m - counts[i][0], n - counts[i][1], i + 1, len);
        
        notTake = findOnesAndZeroes(dp, counts, m, n, i + 1, len);
        
        return dp[m][n][i] = max(take, notTake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> counts(len);
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (len + 1, -1)));
        
        for(int i = 0; i < len; i++)
        {
            vector<int> temp(2);
            
            for(char ch : strs[i])
            {
                if(ch == '0')
                    temp[0]++;
                
                else
                    temp[1]++;
            }
            
            counts[i] = temp;
        }
        
        return findOnesAndZeroes(dp, counts, m, n, 0, len);
    }
};