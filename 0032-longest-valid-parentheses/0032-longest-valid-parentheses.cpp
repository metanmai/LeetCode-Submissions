// Weird stack + DP solution.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), currLen = 0, maxLen = 0;
        vector<bool> used(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            
            else if(!st.empty())
            {
                used[st.top()] = used[i] = true;
                st.pop();
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            currLen = used[i] ? currLen + 1 : 0;
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};