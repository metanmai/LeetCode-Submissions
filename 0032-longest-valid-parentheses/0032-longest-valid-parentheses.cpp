class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), currLen = 0, maxLen = 0;
        vector<bool> usedOpen(n), usedClose(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            
            else if(!st.empty())
            {
                usedOpen[st.top()] = usedClose[i] = true;
                st.pop();
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' and !usedOpen[i] or 
                s[i] == ')' and !usedClose[i])
                currLen = 0;
            
            else
                currLen++;
            
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};