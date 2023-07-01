class Solution {
private:
    int findDeleteDistance(vector<vector<int>> &dp, string &s1, string &s2, 
                           int i, int j, int n1, int n2)
    {
        if(i == n1)
        {
            int sum = 0;
            
            while(j < n2)
                sum += int(s2[j++]);
            
            return sum;
        }
        
        if(j == n2)
        {
            int sum = 0;
            
            while(i < n1)
                sum += int(s1[i++]);
            
            return sum;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] != s2[j])
        {
            int leftDelete = int(s1[i]) + findDeleteDistance(dp, s1, s2, i + 1, j, n1, n2);
            int rightDelete = int(s2[j]) + findDeleteDistance(dp, s1, s2, i, j + 1, n1, n2);
            
            return dp[i][j] = min(leftDelete, rightDelete);
        }
        
        return dp[i][j] = findDeleteDistance(dp, s1, s2, i + 1, j + 1, n1, n2);
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
        return findDeleteDistance(dp, s1, s2, 0, 0, n1, n2);
    }
};