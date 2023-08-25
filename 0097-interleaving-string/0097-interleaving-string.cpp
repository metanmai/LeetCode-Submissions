class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        vector<vector<int>> dp(len1, vector<int> (len2, -1));

        if(len1 + len2 != len3)
            return false;

        function<int(int, int)> canInterleave = [&] (int i, int j) -> bool
        {
            if(i == len1 and j == len2)
                return true;

            if(i == len1 or j == len2)
            {
                if(i == len1)
                    return s2.substr(j, len2 - j) == s3.substr(i + j, len3 - (i + j));

                if(j == len2)
                    return s1.substr(i, len1 - i) == s3.substr(i + j, len3 - (i + j));
            }

            if(dp[i][j] != -1)
                return dp[i][j];

            if(s1[i] == s2[j] and s1[i] == s3[i + j])
                return dp[i][j] = canInterleave(i + 1, j) or canInterleave(i, j + 1);

            else if(s1[i] == s3[i + j])
                return dp[i][j] = canInterleave(i + 1, j);

            else if(s2[j] == s3[i + j])
                return dp[i][j] = canInterleave(i, j + 1);
            
            else
                return dp[i][j] = false;
        };

        return canInterleave(0, 0);
    }
};