class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> cur(n + 1);
        
        for (int i = 0; i <= m; i++) 
        {
            bool pre = cur[0];
            cur[0] = !i;
            
            for (int j = 1; j <= n; j++) 
            {
                bool temp = cur[j];
                if (p[j - 1] == '*') 
                    cur[j] = cur[j - 2] or (i and cur[j] and 
                                            (s[i - 1] == p[j - 2] or p[j - 2] == '.'));
                else
                    cur[j] = i and pre and (s[i - 1] == p[j - 1] or p[j - 1] == '.');
                
                pre = temp;
            }
        }
        
        return cur[n];
    }
};