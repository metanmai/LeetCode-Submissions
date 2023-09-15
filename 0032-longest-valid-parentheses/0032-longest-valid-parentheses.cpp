// Two Pass Solution.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), open = 0, close = 0, maxLen = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                open++;
            
            else
                close++;
            
            if(close > open)
                open = close = 0;
            
            else if(open == close)
                maxLen = max(maxLen, 2 * close);
        }
        
        open = close = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '(')
                open++;
            
            else
                close++;
            
            if(open > close)
                open = close = 0;
            
            else if(open == close)
                maxLen = max(maxLen, 2 * open);
        }
        
        return maxLen;
    }
};