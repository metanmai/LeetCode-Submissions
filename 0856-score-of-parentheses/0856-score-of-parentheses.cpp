class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for(char ch : s)
        {
            if(ch == '(')
                st.push(0);
            
            else
            {
                int curr = st.top(); st.pop();
                int next = st.top(); st.pop();
                
                st.push(next += max(2 * curr, 1));
            }
        }
        
        return st.top();
    }
};